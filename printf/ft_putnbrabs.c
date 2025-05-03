/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:26:49 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/07 10:48:00 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbrabs(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-', 0);
		if ((int)i == -1)
			return (-1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		i += ft_putnbrabs(nb / 10);
		if ((int)i == -1)
			return (-1);
	}
	i += ft_putchar(nb % 10 + '0', 0);
	if ((int)i == -1)
		return (-1);
	return (i);
}
