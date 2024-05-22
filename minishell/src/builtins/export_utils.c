/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:43:16 by alounici          #+#    #+#             */
/*   Updated: 2024/05/20 20:44:36 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*extract_env_name(char *str)
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

char	*extract_env_content(char *str)
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
	// t_list	*last;

	tmp = *envlist;
	while (tmp->next)
		tmp = tmp->next;
	tmp->name = name;
	tmp->content = content;
	tmp->next = NULL;
}

int	check_format(char *str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] == '=')
			return(1);
		i++;
	}
	return (0);
}