/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:28:15 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/07 20:25:25 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

static int	ft_putptr_hexa(const long *ptr, int flag, int j)
{
	char	buffer[24];
	int		pos;
	int		desplazar;
	int		digit;

	pos = 1;
	desplazar = sizeof(long) * 8 - 4;
	while (desplazar >= 0)
	{
		digit = ((long)ptr >> desplazar) & 0xF;
		if (digit != 0 || !pos)
		{
			buffer[j++] = "0123456789abcdef"[digit];
			pos = 0;
		}
		desplazar -= 4;
	}
	if (pos)
		buffer[j++] = '0';
	buffer[j] = '\0';
	flag = write(1, buffer, j);
	if (flag == -1)
		return (-1);
	return (j);
}

int	ft_putptr(const long *ptr, int flag)
{
	flag = write(1, "0x", 2);
	if (flag == -1)
		return (-1);
	return (2 + ft_putptr_hexa(ptr, flag, 0));
}

/*int main()
{
	//void *ptr;

	//int ptr = -1;
	ft_putptr(-42);
	printf("\n el printf: %p\n", -42);
}*/
