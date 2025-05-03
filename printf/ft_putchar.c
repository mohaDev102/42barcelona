/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:03:47 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/07 10:36:42 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c, int flag)
{
	flag = write(1, &c, 1);
	if (flag == -1)
		return (-1);
	return (1);
}
