/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:15:38 by mel-atta          #+#    #+#             */
/*   Updated: 2023/12/16 22:20:25 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*int main()
{
	char s1[100] = "";
	char s2[100] = "test";
	printf("original:%d\n", strncmp(s1, s2, 0));
	printf("%d\n", ft_strncmp(s1, s2, 0));
}*/
