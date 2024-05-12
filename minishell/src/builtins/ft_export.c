/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:00:24 by alounici          #+#    #+#             */
/*   Updated: 2024/05/11 20:05:07 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"

char	*extract_name(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*extract_content(char *str)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != '=')
		i++;
	res = malloc(sizeof(char) * (len - i) + 1);
	if (res == NULL)
		return (NULL);
	while (j < len)
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}

void	ft_add_node(char *name, char *content, t_list **envlist)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *envlist;
	while (tmp->next)
		tmp = tmp->next;
	tmp->name = name;
	tmp->content = content;
	tmp->next = NULL;
}

void	ft_export(t_list **envlist, char *str)
{
	char	*envname;
	char	*envcontent;
	t_list	*tmp;
	int		found;

	found = 0;
	init_list();
	tmp = *envlist;
	envname = extract_name(str);
	envcontent = extract_content(str);
	while (tmp->next)
	{
		if (strcmp(tmp->name, envname) == 0)
		{
			found = 1;
			free(tmp->content);
			tmp->content = envcontent;
			break ;
		}
		tmp = tmp->next;
	}
	if (found == 0)
		ft_add_node(envname, envcontent, &tmp);
}
