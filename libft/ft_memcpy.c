/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:05:52 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/25 10:48:14 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*byte_src;
	unsigned char	*byte_dest;
	size_t			i;

	byte_src = (unsigned char *)src;
	byte_dest = (unsigned char *)dest;
	i = 0;
	if (src == 0 && dest == 0)
		return (NULL);
	while (i < n)
	{
		byte_dest[i] = byte_src[i];
		i++;
	}
	return (dest);
}
/*int main()
{
	char *dest = (void *)0;
	char *src = "hola";
	ft_memcpy(src, dest, 3);
	printf("%s", dest);

}*/
