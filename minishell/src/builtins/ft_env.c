/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:02:51 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 20:48:18 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdio.h>

void	ft_env(t_list **envlist)
{
	t_list	*tmp;

	tmp = *envlist;
	while (tmp)
	{
		if (tmp->content[0] || strchrint(tmp->name, '=') != 0)
		{
			printf("%s", tmp->name);
			printf("=");
			printf("%s\n", tmp->content);
		}
		tmp = tmp->next;
	}
}
