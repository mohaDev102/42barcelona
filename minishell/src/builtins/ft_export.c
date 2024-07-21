/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:00:24 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 11:29:31 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdio.h>

int	export_name_check(char **envname, char *str, char **envcontent)
{
	*envname = extract_env_name(str);
	if (*envname == NULL)
	{
		print_export_error(str);
		return (0);
	}
	*envcontent = extract_env_content(str);
	if (!*envcontent)
	{
		free(envname);
		return (0);
	}
	return (1);
}

int	update_content(t_list *tmp, char *envname, char *envcontent, t_list *new)
{
	int	found;

	found = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, envname) == 0)
		{
			found = 1;
			free(tmp->content);
			tmp->content = envcontent;
			free(envname);
			free(new);
			break ;
		}
		tmp = tmp->next;
	}
	return (found);
}

int	set_new(char *envname, char *envcontent, t_list **new)
{
	*new = ft_lstnew(envname, envcontent);
	if (!new)
	{
		free(envname);
		free(envcontent);
		return (0);
	}
	return (1);
}

void	ft_export(t_list **envlist, char *str)
{
	char	*envname;
	char	*envcontent;
	t_list	*tmp;
	t_list	*new;

	tmp = *envlist;
	new = NULL;
	envname = NULL;
	envcontent = NULL;
	if (!str)
		return ;
	if (!export_name_check(&envname, str, &envcontent))
		return ;
	if (!set_new(envname, envcontent, &new))
		return ;
	if (!tmp)
	{
		*envlist = new;
		return ;
	}
	if (!update_content(tmp, envname, envcontent, new))
		ft_lstadd_back(envlist, new);
}

void	ft_export_alone(t_list **envlist)
{
	t_list	*tmp;
	int		i;

	if (!envlist || !*envlist)
		return ;
	tmp = *envlist;
	while (tmp)
	{
		i = 0;
		write(1, "declare -x ", 11);
		i = 0;
		while (tmp->name[i])
			write(1, &tmp->name[i++], 1);
		if (tmp->content)
			write_content(tmp->content);
		write(1, "\"\n", 2);
		tmp = tmp->next;
	}
}
