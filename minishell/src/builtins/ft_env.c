/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:02:51 by alounici          #+#    #+#             */
/*   Updated: 2024/05/31 20:28:37 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"

void	ft_env(t_list **envlist)
{
	t_list	*tmp;
	// int i;

	// i = 0;
	tmp = *envlist;
	while (tmp)
	{
		// printf("%s", tmp->name);
		if (tmp->content[0] == '=')
		{
			printf("%s", tmp->name);
			printf("%s\n", tmp->content);
		}
		tmp = tmp->next;
	}
		//  write(1, "ici\n\n", 5);
}
