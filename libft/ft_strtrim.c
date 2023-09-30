/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:44:28 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/23 14:46:49 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1 = abcbcaholacaracolaabcbca
// set = "abc"
// return = malloc -> holacaracol
#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
	{
		len--;
	}
	res = ft_substr(&s1[i], 0, (len - i) + 1);
	return (res);
}
/*int main()
{
	char str[] = "Hola gente";
	char set[] = "He";
	printf("%s\n",ft_strtrim(str, set));
}*/
