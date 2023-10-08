/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:26:49 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/07 15:01:22 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_numero_negativo(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = write(1, "-2147483648", 11);
		if (i == -1)
			return (-1);
		return (i);
	}
	return (1);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (ft_numero_negativo(-2147483648));
	if (nb < 0)
	{
		i += ft_putchar('-', 0);
		if (i == -1)
			return (-1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		if (i == -1)
			return (-1);
	}
	i += ft_putchar(nb % 10 + '0', 0);
	if (i == -1)
		return (-1);
	return (i);
}
