/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:13:08 by alounici          #+#    #+#             */
/*   Updated: 2024/05/11 20:06:39 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

char	*change_pwd(t_list **envlist)
{
	char	*buf;
	char	*full_env;

	buf = malloc(PATH_MAX + 1);
	if (!buf)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (!getcwd(buf, PATH_MAX))
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	full_env = ft_strjoin("OLDPWD=", buf);
	ft_export(envlist, full_env);
	return (buf);
}

void	cd_action(char *cdcmd, t_list **envlist)
{
	change_pwd(envlist);
	if (chdir(cdcmd) != 0)
	{
		perror("chdir");
		exit (EXIT_FAILURE);
	}
	change_pwd(envlist);
}

char	*my_getenv(t_list *envlist, char *name, int flag)
{
	char	*content;
	t_list	*tmp;

	init_list();
	tmp = envlist;
	content = NULL;
	while (tmp->next)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			content = tmp->content;
		tmp = tmp->next;
	}
	if (content == NULL)
	{
		if (flag == 1)
			write(2, "cd: HOME not set\n", 18);
		else
			write(2, "cd: OLDPWD not set\n", 20);
		exit(EXIT_FAILURE);
	}
	content = clean_content(content);
	return (content);
}

char	*clean_content(char *content)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	len = ft_strlen(content);
	res = malloc(sizeof(char) * len - 1);
	i = 1;
	j = 0;
	while (content[i])
		res[j++] = content[i++];
	res[len - 1] = '\0';
	return (res);
}

void	ft_cd(char *cdcmd, t_list **envlist)
{
	char	*envcontent;

	if (cdcmd == NULL)
	{
		envcontent = my_getenv(*envlist, "HOME", 1);
		cd_action(envcontent, envlist);
	}
	else if (!strcmp(cdcmd, "-"))
	{
		envcontent = my_getenv(*envlist, "OLDPWD", 2);
		cd_action(envcontent, envlist);
	}
	else
	{
		cd_action(cdcmd, envlist);
	}
}
