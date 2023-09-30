/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 01:06:14 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/23 01:12:45 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*byte_src;
	unsigned char	*byte_dst;

	byte_src = (unsigned char *)src;
	byte_dst = (unsigned char *)dst;
	if (byte_dst < byte_src)
	{
		i = 0;
		while (i < len)
		{
			byte_dst[i] = byte_src[i];
			i++;
		}
	}
	else if (byte_src < byte_dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			byte_dst[i] = byte_src[i];
		}
	}
	return (dst);
}
/*int main()
{
	char src[100] = "Learningisfun";
	char *dest = src;
	char src1[100] = "Learningisfun";
	char *dest1 = src;
	int size = 10;
	ft_memmove(dest + 8, dest, size);
	//memmove(dest1 + 8, dest, size);
	write(1, &src, 25);
	//write(1, "original:\n", 10);
	//write(1, &dest1, 7);

}*/
