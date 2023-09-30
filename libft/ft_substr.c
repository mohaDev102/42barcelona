/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:54:10 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/25 13:53:47 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (res == 0)
		return (0);
	i = 0;
	while (start < ft_strlen(s) && i < len && s[i])
	{
		res[i] = s[start];
		i++;
		start++;
	}
	return (res);
}
int	main(void)
{

	char s[100] = "hola";
	int start = 2;
	size_t len = 30;
	printf("%s\n", ft_substr(s, start, len));
}
