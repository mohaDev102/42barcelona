/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:10:15 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/23 01:32:40 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	//int	i;

	//i = 0;
	return (ft_memchr(str, c, ft_strlen(str) + 1));
}
/*int	main(void)
{
	char str[100] = "teste";
	int c = 1024;
	printf("custom: %s\n", ft_strchr(str, c));
	printf("original: %s\n", strchr(str, c));
}*/
