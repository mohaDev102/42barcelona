/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:48:37 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/25 11:48:42 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen(s);
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
/*char map_function(unsigned int index, char c) {
	if (c >= 'a' && c <= 'z') {
		return (c - ('a' - 'A'));
	}
	return (c);
}*/
/*int main()
{
	char str[] = "hola";
	printf("%s\n", ft_strmapi(str, &map_function));

}*/
