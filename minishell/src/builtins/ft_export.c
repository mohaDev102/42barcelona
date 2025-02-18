/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:00:24 by alounici          #+#    #+#             */
/*   Updated: 2024/06/02 13:10:55 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"

// char	*extract_env_name(char *str)
// {
// 	int		i;
// 	int		j;
// 	char	*res;

// 	i = 0;
// 	j = 0;
// 	while (str[i] && str[i] != '=')
// 		i++;
// 	res = malloc(sizeof(char) * (i + 1));
// 	if (res == NULL)
// 		return (NULL);
// 	while (j < i)
// 	{
// 		if (ft_isdigit(str[j]) == 0 && str[i] != '=')
// 			return (0);
// 		res[j] = str[j];
// 		j++;
// 	}
// 	res[j] = '\0';
// 	return (res);
// }

// char	*extract_env_content(char *str)
// {
// 	char	*res;
// 	int		i;
// 	int		j;
// 	int		len;

// 	i = 0;
// 	j = 0;
// 	while (str[i] && str[i] != '=')
// 		i++;
// 	len = ft_strlen(str) - i;
// 	res = malloc(sizeof(char) * len + 1);
// 	if (res == NULL)
// 		return (NULL);
// 	while (j < len)
// 		res[j++] = str[i++];
// 	res[j] = '\0';
// 	return (res);
// }

// void	ft_add_node(char *name, char *content, t_list **envlist)
// {
// 	t_list	*tmp;
// 	t_list *last;

// 	(void)name;
// 	(void)content;
// 	tmp = *envlist;
// 	// last = NULL;
// 	// write(2, "33", 2);
// 	// while (tmp)
// 	// {
// 	// 	// last = tmp->next;
// 	// 	tmp = tmp->next;
// 	// }
// 	tmp = ft_lstlast(tmp);
// 	last = malloc(sizeof(t_list));
// 	if (!last)
// 		return ;
// 	last->name = name;
// 	last->content = content;
// 	last->next = NULL;
// 	// envlist = &tmp;
// 	// printf("%s", tmp->content);
// }

void	ft_export(t_list **envlist, char *str)
{
	char	*envname;
	char	*envcontent;
	t_list	*tmp;
	t_list	*new;
	int		found;

	found = 0;
	tmp = *envlist;
	new = NULL;
	if (!str)
		return ;
	envname = extract_env_name(str);
	if (envname == 0)
	{
		print_export_error(str);
		return ;
	}
	envcontent = extract_env_content(str);
	new = ft_lstnew(envname, envcontent);
	if (!tmp)
		return ;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, envname) == 0)
		{
			found = 1;
			free(tmp->content);
			tmp->content = envcontent;
			break ;
		}
		tmp = tmp->next;
	}
	if (found == 0)
		ft_lstadd_back(envlist, new);
	// free(new);
}

void 	ft_export_alone(t_list **envlist)
{
	t_list *tmp;
	int i;

	i = 0;

    if (!envlist || !*envlist)
		return ;
	tmp = *envlist;
	while (tmp)
	{
		i = 0;
		if (tmp->name) // Verificar si name no es NULL
        {
            write(1, "declare -x ", 11);
            i = 0;
            while (tmp->name[i])
            {
                write(1, &tmp->name[i], 1);
                i++;
            }
        }
        if (tmp->content) // Verificar si content no es NULL
        {
            i = 0;
            write(1, "=\"", 2);
			// if (tmp->content[1])
			// {
            while (tmp->content[i])
            {
				if (tmp->content[i] == '=')
				 	i++;
                write(1, &tmp->content[i++], 1);
            }
			// }
            //write(1, "\"", 1);
        }
		write(1, "\"\n", 2);
		tmp = tmp->next;
	}
}