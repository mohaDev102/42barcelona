/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:22:46 by alounici          #+#    #+#             */
/*   Updated: 2024/05/20 21:09:24 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../inc/minishell.h"

t_list	*init_list(void)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->name = NULL;
	temp->content = NULL;
	temp->next = NULL;
	return (temp);
}

void	generate_env_list(char **env, t_list **envlist)
{
	int		i;
	int		j;
	t_list	*lst;

	i = 0;
	lst = *envlist;
	while (env[i])
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
}

char	*add_env_name(char **env, int i, int j)
{
	char	*aux;
	int		k;

	k = 0;
	aux = malloc(sizeof(char) * (j + 1));
	if (!aux)
		return (NULL);
	while (k < j)
	{
		aux[k] = env[i][k];
		k++;
	}
	aux[k] = '\0';
	return (aux);
}

char	*add_env_content(char **env, int i, int j)
{
	char	*aux;
	int		k;
	int		kk;

	kk = 0;
	k = 0;
	while (env[i][j])
	{
		j++;
	}
	while (env[i][kk] != '=')
		kk++;
	aux = malloc(sizeof(char) * (j - k + 1));
	k = 0;
	while (k < j && env[i][kk])
	{
		aux[k] = env[i][kk];
		kk++;
		k++;
	}
	aux[k] = '\0';
	k = 0;
	return (aux);
}

t_list	*ft_list(char **env)
{
	int		i;
	t_list	*envlist;

	i = 0;
	envlist = init_list();
	generate_env_list(env, &envlist);
	//ft_echo("$PWD -n", 1, envlist, 126);
	// ft_env(&envlist);
	ft_export(&envlist, "a");
		ft_env(&envlist);

	return (envlist); 
}


// int main(int argc, char **argv, char **env)
// {
// 	ft_list(env);
// }