/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:13:08 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 13:56:53 by mel-atta         ###   ########.fr       */
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

// void change_pwd(t_list **envlist)
// {
// 	char *buf;
// 	char *full_env;

// 	buf = malloc(PATH_MAX + 1);
// 	if (!buf)
// 	{
// 	perror("malloc");
// 	//exit(EXIT_FAILURE);
// 	}
// 	if (!getcwd(buf, PATH_MAX))
// 	{
// 	perror("getcwd");
// 	// free(buf);
// 	// return (NULL);
// 	//exit(EXIT_FAILURE);
// 	}
// 	full_env = ft_strjoin("PWD=", buf);
// 	if (!full_env)
// 	{
// 	free(buf);
// 	// return (NULL);
// 	}
// 	ft_export(envlist, full_env);
// 	free(full_env);
// 	free(buf);
// 	// return (buf);
// }

// void change_oldpwd(t_list **envlist)
// {
// 	char	*buf;
// 	char	*full_env;

// 	buf = malloc(PATH_MAX + 1);
// 	if (!buf)
// 	{
// 		perror("malloc");
// 		//exit(EXIT_FAILURE);
// 	}
// 	if (!getcwd(buf, PATH_MAX))
// 	{
// 		perror("getcwd");
// 		free(buf);
// 		//exit(EXIT_FAILURE);
// 	}
// 	full_env = ft_strjoin("OLDPWD=", buf);
// 	ft_export(envlist, full_env);
// 	free(full_env);
// 	// free(buf);
// }

int change_pwd(t_list **envlist) {
    char *buf = malloc(PATH_MAX + 1);
    if (!buf) {
        perror("malloc");
        return -1;
    }

    if (!getcwd(buf, PATH_MAX)) {
        perror("getcwd");
        free(buf);
        return -1;
    }

    char *full_env = ft_strjoin("PWD=", buf);
    if (!full_env) {
        free(buf);
        return -1;
    }

    ft_export(envlist, full_env);
    free(full_env);
    free(buf);
    return 0;
}


// int change_oldpwd(t_list **envlist)
// {
//     char    *buf;
//     char    *full_env;
//     t_list  *tmp;

//     tmp = *envlist;
//     while (tmp)
//     {
//         if (ft_strcmp(tmp->name, "PWD") == 0)
//             buf = ft_strdup(tmp->content);
//         tmp = tmp->next;
//     }
// 	if (!buf)
// 	{
// 		perror("malloc");
// 		return (-1);
// 	}

//     full_env = ft_strjoin("OLDPWD=", buf);
// 	if (!full_env)
// 	{
// 		free(buf);
// 		return (-1);
// 	}
//     ft_export(envlist, full_env);
//     free(full_env);
//     free(buf);
// 	return (0);
// }

int change_oldpwd(t_list **envlist) {
    char *buf = malloc(PATH_MAX + 1); 
    if (!buf) {
        perror("malloc");
        return -1;
    }
    if (!getcwd(buf, PATH_MAX)) {
        perror("getcwd");
        free(buf);
        return -1;
    }

    char *full_env = ft_strjoin("OLDPWD=", buf);
    if (!full_env) {
        free(buf);
        return -1;
    }

    ft_export(envlist, full_env);
    free(full_env);
    free(buf);
    return 0;
	buf = malloc(PATH_MAX + 1);
	write(1, "ici", 3);
	if (!buf)
	{
	perror("malloc");
	//exit(EXIT_FAILURE);
	}
	getcwd(buf, PATH_MAX);
	// {
	// perror("getcwd");
	// free(buf);
	// // return (NULL);
	// //exit(EXIT_FAILURE);
	// }
	// printf("buf %s\n", buf);
	full_env = ft_strjoin("PWD=", buf);
	if (!full_env)
	{
	free(buf);
	// return (NULL);
	}
	ft_export(envlist, full_env);
	free(full_env);
	free(buf);
}

void change_oldpwd(t_list **envlist)
{
	char	*buf;
	char	*full_env;
	t_list	*tmp;

	tmp = *envlist;
	buf = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "PWD") == 0)
			buf = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	if (buf == NULL)
		return ;
	full_env = ft_strjoin("OLDPWD=", buf);
	ft_export(envlist, full_env);
	free(full_env);
	free(buf);
}

void	cd_action(char *cdcmd, t_list **envlist)
{
	if (change_oldpwd(envlist) == -1)
	{
		write(2, "Errorss\n", 8);
		return ;
	}
	if (chdir(cdcmd) != 0)
		perror("chdir");
		return ;
		// exit (EXIT_FAILURE);
	}
	if (change_pwd(envlist) == -1)
	{
		write(2, "Errorss\n", 8);
		return ;
	}
	// change_pwd(envlist);
	change_pwd(envlist);
}

char	*my_getenv(t_list *envlist, char *name, int flag, int ifree)
{
	char	*content;
	t_list	*tmp;

	tmp = envlist;
	content = NULL;
	(void)ifree;
	if (!name)
		return (NULL);

	while (tmp != NULL)
	{
		if (tmp->name && ft_strcmp(name, tmp->name) == 0)
		{
			content = ft_strdup(tmp->content);
			break;
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
	// if (ifree == 1)
	// 	free(name);
	// printf("content%s\n", content);
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

int all_spacescd(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] != '\"' && cmd[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

// cd ~
void	ft_cd(char *cdcmd, t_list **envlist)
{
	char	*envcontent;

	// printf("cmd %s\n", cdcmd);
	if ((cdcmd == NULL) || ft_strcmp(cdcmd, "~") == 0)
	{
		envcontent = my_getenv(*envlist, "HOME", 1, 0);
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
