/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:00:24 by alounici          #+#    #+#             */
/*   Updated: 2024/06/19 19:02:26 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"

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
	if (!envcontent)
	{
		free(envname);
		return ;
	}
	new = ft_lstnew(envname, envcontent);
	if (!new)
	{
		free(envname);
		free(envcontent);
		return ;
	}
	if (!tmp)
	{
		*envlist = new;
		return ;
	}
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
	if (found == 0)
		ft_lstadd_back(envlist, new);
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
            while (tmp->content[i])
            {
				if (tmp->content[i] == '=')
				 	i++;
                write(1, &tmp->content[i++], 1);
            }
        }
		write(1, "\"\n", 2);
		tmp = tmp->next;
	}
}

//export hola =algo
//ls$ solo _
//export 'algo nose'