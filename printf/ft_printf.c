/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:20:32 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/07 13:39:59 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_putporcentaje(char c)
{
	int	len;

	len = 0;
	len = write(1, &c, 1);
	if (len == -1)
		return (-1);
	return (1);
}

int	ft_evaluate(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == '%')
		len = ft_putporcentaje('%');
	if (c == 'c')
		len = ft_putchar(va_arg(args, int), 0);
	if (c == 's')
		len = ft_putstr(va_arg(args, char *), 0);
	if (c == 'p')
		len = ft_putptr(va_arg(args, long *), 0);
	if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		len = ft_putnbrabs(va_arg(args, unsigned int));
	if (c == 'x')
		len = ft_puthexa(va_arg(args, int), 0, 0);
	if (c == 'X')
		len = ft_puthexa(va_arg(args, int), 1, 0);
	return (len);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_evaluate(s[++i], args);
			if (len == -1)
				return (-1);
		}
		else
		{
			len += write(1, &s[i], 1);
			if (len == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*int main()
{
	ft_printf("cant%d\n",ft_printf("%s", (char *)NULL));
	printf("cant%d\n",printf("%s", (char *)NULL));
}*/
