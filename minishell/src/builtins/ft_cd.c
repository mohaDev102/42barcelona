/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:13:08 by alounici          #+#    #+#             */
/*   Updated: 2024/06/23 18:01:28 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <linux/limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

void change_pwd(t_list **envlist)
{
	char *buf;
	char *full_env;

	buf = malloc(PATH_MAX + 1);
	if (!buf)
	{
	perror("malloc");
	//exit(EXIT_FAILURE);
	}
	if (!getcwd(buf, PATH_MAX))
	{
	perror("getcwd");
	free(buf);
	// return (NULL);
	//exit(EXIT_FAILURE);
	}
	full_env = ft_strjoin("PWD=", buf);
	if (!full_env)
	{
	free(buf);
	// return (NULL);
	}
	ft_export(envlist, full_env);
	free(full_env);
	free(buf);
	// return (buf);
}

void change_oldpwd(t_list **envlist)
{
	char	*buf;
	char	*full_env;

	buf = malloc(PATH_MAX + 1);
	if (!buf)
	{
		perror("malloc");
		//exit(EXIT_FAILURE);
	}
	if (!getcwd(buf, PATH_MAX))
	{
		perror("getcwd");
		free(buf);
		//exit(EXIT_FAILURE);
	}
	full_env = ft_strjoin("OLDPWD=", buf);
	ft_export(envlist, full_env);
	free(full_env);
	free(buf);
}

void	cd_action(char *cdcmd, t_list **envlist)
{
	change_oldpwd(envlist);
	if (chdir(cdcmd) != 0)
	{
		perror("chdir");
		// exit (EXIT_FAILURE);
	}
	change_pwd(envlist);
}

char	*my_getenv(t_list *envlist, char *name, int flag, int ifree)
{
	char	*content;
	t_list	*tmp;

	// init_list();
	tmp = envlist;
	content = NULL;
	while (tmp)
	{
		// printf("%s\n%s\n", tmp->name, name);
		if (!name)
			return (NULL);
		while (tmp != NULL)
		{
			// da seg fault al poner $$
			if (tmp->name && ft_strcmp(name, tmp->name) == 0)
			{
				// printf("ici %s\n%s\n", tmp->content, name);
				content = tmp->content;
				// printf("conte %s", content);
			}
			tmp = tmp->next;
		}
		if (content == NULL)
		{
			if (flag == 1)
				write(2, "cd: HOME not set\n", 18);
			else if (flag == 2)
				write(2, "cd: OLDPWD not set\n", 20);
			return (NULL);
		}
		// content = clean_content(content);
		// printf("content%s\n", content);
		if (ifree == 1)
			free(name);
	}
		return (content);
	// }
}

char	*clean_content(char *content)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	len = ft_strlen(content);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (content[i])
		res[j++] = content[i++];
	res[j] = '\0';
	return (res);
}

// cd ~
void	ft_cd(char *cdcmd, t_list **envlist)
{
	char	*envcontent;

	if ((cdcmd == NULL) || ft_strcmp(cdcmd, "~") == 0)
	{
		envcontent = my_getenv(*envlist, "HOME", 1, 0);
		cd_action(envcontent, envlist);
	}
	else if (!strcmp(cdcmd, "-"))
		ft_pwd();
	else
	{
		cd_action(cdcmd, envlist);
	}
}
