/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:11:46 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/24 15:12:29 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;
	size_t	maxsize;

	i = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	maxsize = size - lendst - 1;
	if (size <= lendst)
	{
		return (lensrc + size);
	}
	if (lendst > size)
		return (lendst + lensrc);
	while (src[i] != '\0' && i < maxsize)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}

/*int	main(void)

{
	char src[100] = "lorem";
	char dest[100] = "a";
	char dest1[100] = "a";
	printf("custom: %ld\n", ft_strlcat(dest, src, 15));
	printf("original: %ld\n", strlcat(dest1, src, 15));
	write(1, dest, 15);
	write(1, dest1, 15);
}*/
