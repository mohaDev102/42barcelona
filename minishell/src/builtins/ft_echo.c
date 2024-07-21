/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:28:48 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 20:52:48 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdio.h>

void	print_env(char *echocmd, t_list *envlist)
{
	t_list	*tmp;
	int		j;

	j = 0;
	tmp = envlist;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, echocmd) == 0 && tmp)
		{
			j = 1;
			while (tmp->content[j])
				write(1, &tmp->content[j++], 1);
			return ;
		}
		else
			tmp = tmp->next;
	}
	j = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_echo(char *echocmd, int flag, t_list *envlist)
{
	int	i;

	(void)envlist;
	i = 0;
	if (echocmd == NULL)
	{
		if (flag == 1)
			write(1, "\n", 1);
		return ;
	}
	else
	{
		while (echocmd[i])
		{
			write(1, &echocmd[i], 1);
			i++;
		}
	}
}
