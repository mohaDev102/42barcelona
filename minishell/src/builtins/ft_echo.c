/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:28:48 by alounici          #+#    #+#             */
/*   Updated: 2024/05/31 21:01:47 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"

//flag 1 = -n

void	print_env(char *echocmd, t_list *envlist)
{
	t_list	*tmp;
	// char	*envname;
	int		j;
	// int		flag;

	j = 0;
	// flag = 0;
	tmp = envlist;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, echocmd) == 0 && tmp)
		{
			j = 1;
			// flag = 1;
			while(tmp->content[j])
				write(1, &tmp->content[j++], 1);
			return ;
		}
		else
			tmp = tmp->next;
	}
	j = 0;
	// if (flag == 0)
	// {
	// 	write(1, "$", 1);
	// 	while (echocmd[j])
	// 		write(1, &echocmd[j++], 1);
	// }
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
	int		i;
	// int j = 0;
	// char *envname;
	(void)envlist;
	i = 0;
	// ft_putnbr(flag);
	if (echocmd == NULL)
	{
		if (flag == 1)
			write(1, "\n", 1);
		// write(1, "ici", 3);
		return ;
	}
	else
	{
		while (echocmd[i])
		{
				write(1, &echocmd[i], 1);
				// while(echocmd[i])
				// {
					// write(1, "text", 4);
					// write(1, echocmd[i], 1);
					// printf("eef");
					// i++;
				// }
			// }
			i++;
		}
	}
	// if (echocmd == NULL || echocmd[0] == '\0')// && flag == 1)
	// {
		// if (flag == 1)
		// {
		// 		write(1, "\n", 1);
		// 		// write(1, "fin", 3);
		// }
		// return ;
	// }
}
 