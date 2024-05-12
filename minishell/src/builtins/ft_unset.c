/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:30:00 by alounici          #+#    #+#             */
/*   Updated: 2024/05/11 20:03:23 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <unistd.h>

void	ft_unset(t_list **envlist, char *unscmd)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *envlist;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, unscmd) == 0)
		{
			if (tmp2 == NULL)
				*envlist = tmp->next;
			else
			{
				tmp2->next = tmp->next;
				free(tmp->name);
				free(tmp->content);
				free(tmp);
				tmp = tmp2->next;
				break ;
			}
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
}
