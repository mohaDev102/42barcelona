/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:48:08 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/25 11:48:16 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (n == 0)
		return (src_len);
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*int	main(void)
{
	char src[100] = "lorem ipsum dolor sit amet";
	char dest[100] = "";
	char dest1[100]	= "";
	//printf("custom: %ld\n", ft_strlcpy(dest, src, 0));
	printf("original: %ld\n", strlcpy(dest1, src, 89));
	//write(1, dest, 15);
	write(1, dest1, 15);

}*/
