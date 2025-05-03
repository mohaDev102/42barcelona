/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:27:42 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/07 10:42:44 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_putstr(char *str, int flag)
{
	int	len;

	if (str == NULL)
	{
		flag = write(1, "(null)", 6);
		if (flag == -1)
			return (-1);
		return (6);
	}
	len = ft_strlen(str);
	flag = write(1, str++, len);
	if (flag == -1)
		return (-1);
	return (len);
}

/*int main()
{
	//printf("%d\n",ft_putstr("wddw"));
	char ptr[] = "hola";
	printf("%d\n", ft_putHexa(0xF182));
}*/
