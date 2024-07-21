/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:22:46 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 11:35:12 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	free_envlist(t_list *envlist)
{
	t_list	*tmp;

	while (envlist)
	{
		tmp = envlist->next;
		free(envlist->name);
		free(envlist->content);
		free(envlist);
		envlist = tmp;
	}
}

void	generate_env_list(char **env, t_list **envlist)
{
	int		i;
	t_list	*lst;
	t_list	*new_node;

	i = 0;
	if (!envlist)
		return ;
	lst = *envlist;
	while (env[i])
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return ;
		new_node->name = ft_substr(env[i], 0, ft_strchr(env[i], '=') - env[i]);
		new_node->content = ft_substr(env[i], ft_strchr(env[i], '=') - env[i]
				+ 1, ft_strlen(env[i]));
		if (!new_node->content)
		{
			free(new_node->name);
			free(new_node);
		}
		new_node->next = NULL;
		add_env_node(envlist, new_node, &lst);
		i++;
	}
}

t_list	*ft_list(char **env)
{
	t_list	*envlist;

	envlist = NULL;
	generate_env_list(env, &envlist);
	return (envlist);
}

char	**copy_env(char **env)
{
	int		len;
	int		i;
	char	**my_env;

	len = 0;
	i = 0;
	if (!env)
		return (NULL);
	while (env[len])
		len++;
	my_env = malloc(sizeof(char *) * (len + 1));
	if (!my_env)
		return (NULL);
	while (i < len)
	{
		my_env[i] = ft_strdup(env[i]);
		i++;
	}
	my_env[i] = NULL;
	return (my_env);
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}
