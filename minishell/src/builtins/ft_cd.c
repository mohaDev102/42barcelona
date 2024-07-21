/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:13:08 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 11:39:33 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <errno.h>
#include <limits.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	change_pwd(t_list **envlist)
{
	char	*buf;
	char	*full_env;

	buf = malloc(PATH_MAX + 1);
	if (!buf)
	{
		perror("malloc");
		return (-1);
	}
	if (!getcwd(buf, PATH_MAX))
	{
		perror("getcwd");
		free(buf);
		return (-1);
	}
	full_env = ft_strjoin("PWD=", buf);
	if (!full_env)
	{
		free(buf);
		return (-1);
	}
	ft_export(envlist, full_env);
	free(full_env);
	free(buf);
	return (0);
}

int	change_oldpwd(t_list **envlist)
{
	char	*buf;
	char	*full_env;
	t_list	*tmp;

	tmp = *envlist;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "PWD") == 0)
			buf = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	if (!buf)
		return (-1);
	full_env = ft_strjoin("OLDPWD=", buf);
	if (!full_env)
	{
		free(buf);
		return (-1);
	}
	ft_export(envlist, full_env);
	free(full_env);
	free(buf);
	return (0);
}

void	cd_action(char *cdcmd, t_list **envlist)
{
	if (change_oldpwd(envlist) == -1)
	{
		write(2, "Errors\n", 7);
		return ;
	}
	if (chdir(cdcmd) != 0)
	{
		perror("chdir");
		return ;
	}
	if (change_pwd(envlist) == -1)
	{
		write(2, "Errors\n", 7);
		return ;
	}
	change_pwd(envlist);
}

void	ft_cd(char *cdcmd, t_list **envlist)
{
	char	*envcontent;

	if ((cdcmd == NULL) || ft_strcmp(cdcmd, "~") == 0)
	{
		envcontent = my_getenv(*envlist, "HOME", 1);
		cd_action(envcontent, envlist);
		free(envcontent);
	}
	else if (!strcmp(cdcmd, "-"))
		ft_pwd();
	else if (all_spacescd(cdcmd) != 0)
		return ;
	else
	{
		cd_action(cdcmd, envlist);
	}
}
