/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:34:48 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/21 17:45:16 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_contar_digitos(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_numero_absoluto(int n)
{
	if (n < 0)
	{
		n = -n;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_contar_digitos(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
		res[0] = '-';
	while (n != 0)
	{
		res[--len] = ft_numero_absoluto(n % 10) + '0';
		n /= 10;
	}
	return (res);
}
