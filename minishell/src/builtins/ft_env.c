/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:02:51 by alounici          #+#    #+#             */
/*   Updated: 2024/05/11 20:05:23 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"

void	ft_env(t_list **envlist)
{
	t_list	*tmp;

	tmp = *envlist;
	while (tmp)
	{
		printf("%s", tmp->name);
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
