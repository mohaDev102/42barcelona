/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:31:53 by mel-atta          #+#    #+#             */
/*   Updated: 2023/09/25 10:33:34 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	
#include <string.h>	

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*byte_ptr;

	byte_ptr = (unsigned char *)ptr;
	while (n > 0)
	{
		*byte_ptr = 0;
		byte_ptr++;
		n--;
	}
}
/*int	main()
{
	int number;
	char str[20] = "hola";
	char str2[10] = "hola";
	printf("%s\n",str);
	printf("%s\n", str2);
	bzero(str, 4);
	printf("original:%s\n", str);
	ft_bzero(str2, 4);
	printf("custom:%s\n",str2);

}*/
