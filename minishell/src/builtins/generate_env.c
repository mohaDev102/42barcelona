/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:22:46 by alounici          #+#    #+#             */
/*   Updated: 2024/06/01 17:21:33 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../inc/minishell.h"

// void	generate_env_list(char **env, t_list **envlist)
// {
// 	t_list *lst;
// 	t_list	*new;
// 	int i;
// 	int j;
// 	// char *name;
// 	// char *content;
<<<<<<< HEAD

// 	j = 0;
// 	i = 0;
// 	lst = *envlist;
// 	new = NULL;
// 	while (env[i])
// 	{
// 		while (env[i][j])
// 		{
// 			if (env[i][j] == '=')
// 			{
// 				new = ft_lstnew(add_env_name(env, i, j), add_env_content(env, i, j));
// 				ft_lstadd_back(&lst, new);
// 				lst = lst->next;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	generate_env_list(char **env, t_list **envlist)
// {
// 	int		i;
// 	int		j;
// 	t_list	*lst;

// 	i = 0;
// 	lst = *envlist;
// 	t_list *new_node;
// 	while (env[i])
// 	{
// 		j = 0;
// 		while (env[i][j])
// 		{
// 			if (env[i][j] == '=')
// 			{
// 				lst->name = add_env_name(env, i, j);
// 				lst->content = add_env_content(env, i, j);
// 				new_node = malloc(sizeof(t_list));
// 				if (!new_node)
// 					return ;
				
// 				new_node->next = NULL;
// 				lst->next = new_node;
// 				lst = new_node;
// 				break;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	generate_env_list(char **env, t_list **envlist)
// {
// 	int		i;
// 	int		j;
// 	t_list	*lst;

// 	i = 0;
// 	lst = *envlist;
// 	write(2, "33", 2);
// 	if (!env)
// 		return ;
// 	while (env[i + 1])
// 	{
// 		write(2, "44", 2);
// 		j = 0;
// 		while (env[i][j])
// 		{
// 				write(2, "66", 2);
// 			if (env[i][j] == '=')
// 			{
// 				lst->name = add_env_name(env, i, j);
// 				lst->content = add_env_content(env, i, j);
// 				lst->next = malloc(sizeof(t_list));
// 				lst = lst->next;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	lst->name = add_env_name(env, i, j);
// 	lst->content = add_env_content(env, i, j);
// 	lst->next = NULL;
// }

=======

// 	j = 0;
// 	i = 0;
// 	lst = *envlist;
// 	new = NULL;
// 	while (env[i])
// 	{
// 		while (env[i][j])
// 		{
// 			if (env[i][j] == '=')
// 			{
// 				new = ft_lstnew(add_env_name(env, i, j), add_env_content(env, i, j));
// 				ft_lstadd_back(&lst, new);
// 				lst = lst->next;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	generate_env_list(char **env, t_list **envlist)
// {
// 	int		i;
// 	int		j;
// 	t_list	*lst;

// 	i = 0;
// 	lst = *envlist;
// 	t_list *new_node;
// 	while (env[i])
// 	{
// 		j = 0;
// 		while (env[i][j])
// 		{
// 			if (env[i][j] == '=')
// 			{
// 				lst->name = add_env_name(env, i, j);
// 				lst->content = add_env_content(env, i, j);
// 				new_node = malloc(sizeof(t_list));
// 				if (!new_node)
// 					return ;
				
// 				new_node->next = NULL;
// 				lst->next = new_node;
// 				lst = new_node;
// 				break;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	generate_env_list(char **env, t_list **envlist)
// {
// 	int		i;
// 	int		j;
// 	t_list	*lst;

// 	i = 0;
// 	lst = *envlist;
// 	write(2, "33", 2);
// 	if (!env)
// 		return ;
// 	while (env[i + 1])
// 	{
// 		write(2, "44", 2);
// 		j = 0;
// 		while (env[i][j])
// 		{
// 				write(2, "66", 2);
// 			if (env[i][j] == '=')
// 			{
// 				lst->name = add_env_name(env, i, j);
// 				lst->content = add_env_content(env, i, j);
// 				lst->next = malloc(sizeof(t_list));
// 				lst = lst->next;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	lst->name = add_env_name(env, i, j);
// 	lst->content = add_env_content(env, i, j);
// 	lst->next = NULL;
// }

void free_envlist(t_list *envlist)
{
    t_list *tmp;

    while (envlist)
    {
        tmp = envlist->next;
		free(envlist->name);
        free(envlist->content);
        free(envlist);
        envlist = tmp;
    }
}
>>>>>>> origin

void	generate_env_list(char **env, t_list **envlist)
{
	int		i;
	// int		j;
	t_list	*lst;
	t_list *new_node;

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
		new_node->content = ft_substr(env[i], ft_strchr(env[i], '=') - env[i] + 1, ft_strlen(env[i]));
		// new_node->content = getenv(new_node->name);
		if (!new_node->content)
		{
			free(new_node->name);
			free(new_node);
		}
		new_node->next = NULL;
		if (!*envlist)
		{
			*envlist = new_node;
		}
		else
		{
			lst = *envlist;
			while (lst->next)
				lst = lst->next;
			lst->next = new_node;
		}
		i++;
	}
}

t_list	*ft_list(char **env)
{
	// int		i;
	t_list	*envlist;
	envlist = NULL;
<<<<<<< HEAD
	i = 0;
=======
	// i = 0;
>>>>>>> origin
	// envlist = init_list();
	// if (!envlist)
	// 	return (NULL);
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
<<<<<<< HEAD
=======

void free_env(char **env)
{
	int i = 0;
	if (!env)
		return;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}
>>>>>>> origin

// int main(int argc, char **argv, char **env)
// {
// 	t_list *envlist;

// 	envlist = ft_list(env);
// 	// ft_export_alone(&envlist);
// 	// ft_cd(NULL, &envlist);
// 	// ft_pwd();
	
// }