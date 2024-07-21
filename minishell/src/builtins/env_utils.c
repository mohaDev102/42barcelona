/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:02:15 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 11:34:49 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	add_env_node(t_list **envlist, t_list *new_node, t_list **lst)
{
	if (!*envlist)
		*envlist = new_node;
	else
	{
		*lst = *envlist;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new_node;
	}
}
