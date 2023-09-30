/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:34:37 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/25 03:17:27 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *str, const char *find_to, size_t len)
{
	size_t		len_to_find;
	const char	*s;
	const char	*find;

	if (*find_to == '\0')
		return ((char *)str);
	len_to_find = ft_strlen(find_to);
	while (*str != '\0' && len >= len_to_find)
	{
		if (*str == *find_to)
		{
			s = str;
			find = find_to;
			while (*find != '\0' && *s == *find)
			{
				s++;
				find++;
			}
			if (*find == '\0')
				return ((char *)str);
		}
		str++;
		len--;
	}
	return (NULL);
}
/*int main()
{
	char str[] = "lorem ipsum dolor sit amet";
	char find[] = "lorem";
	size_t n = 1;
	printf("custom:%s\n", ft_strnstr(str, find, n));
	//printf("original:%s\n", strnstr(str, find, n));
}*/
