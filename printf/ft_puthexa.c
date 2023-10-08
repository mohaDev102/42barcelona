/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:14:56 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/07 14:40:19 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

static char	*ft_hexadecimal_upper(int is_upper, int valor)
{
	if (is_upper == 1)
		return (&("0123456789ABCDEF"[valor]));
	else
		return (&("0123456789abcdef"[valor]));
}

int	ft_puthexa(int numero, int is_upper, int flag)
{
	char	hexadecimal[9];
	int		len;
	int		i;
	int		valor;
	int		emp;

	i = 28;
	len = 0;
	emp = 0;
	while (i >= 0)
	{
		valor = (numero >> i) & 0xF;
		if (valor > 0 || emp || i == 0)
		{
			emp = 1;
			hexadecimal[len] = *ft_hexadecimal_upper(is_upper, valor);
			len++;
		}
		i -= 4;
	}
	hexadecimal[len] = '\0';
	flag = write(1, hexadecimal, len);
	if (flag == -1)
		return (-1);
	return (len);
}
/*int main()
{
	ft_puthexa(1);
	printf("\noriginal:%x\n", 1);
}*/
