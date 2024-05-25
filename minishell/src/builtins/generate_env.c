/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:22:46 by alounici          #+#    #+#             */
/*   Updated: 2024/05/25 02:22:55 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../inc/minishell.h"

void	generate_env_list(char **env, t_list **envlist)
{
	int		i;
	int		j;
	t_list	*lst;

	i = 0;
	lst = *envlist;
	while (env[i + 1])
	{
		j = 0;
		while (env[i][j])
		{
			if (env[i][j] == '=')
			{
				lst->name = add_env_name(env, i, j);
				lst->content = add_env_content(env, i, j);
				lst->next = malloc(sizeof(t_list));
				lst = lst->next;
			}
			j++;
		}
		i++;
	}
	lst->name = add_env_name(env, i, j);
	lst->content = add_env_content(env, i, j);
	lst->next = NULL;
}

t_list	*ft_list(char **env)
{
	int		i;
	t_list	*envlist;

	i = 0;
	envlist = init_list();
	generate_env_list(env, &envlist);
	return (envlist); 
}

char **copy_env(char **env)
{
	int len;
	int i;
	char **my_env;

	len = 0;
	i = 0;
	while (env[len])
		len++;
	my_env = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		my_env[i] = ft_strdup(env[i]);
		i++;
	}
	my_env[i] = NULL;
	return (my_env);
}

// int main(int argc, char **argv, char **env)
// {
// 	t_list *envlist;

// 	envlist = ft_list(env);
// 	// ft_export_alone(&envlist);
// 	// ft_cd(NULL, &envlist);
// 	// ft_pwd();
	
// }