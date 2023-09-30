/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:46:35 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/16 00:51:43 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*i;

	i = 0;
	i = s;
	while (*i != '\0')
		i++;
	while (i >= s)
	{
		if (*i == (unsigned char)c)
			return ((char *)i);
		i--;
	}
	return (NULL);
}
