/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:14:33 by alounici          #+#    #+#             */
/*   Updated: 2024/07/14 00:40:37 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(void)
{
	char	*buf;
	char	*res;

	buf = malloc(PATH_MAX + 1);
	if (!buf)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	res = getcwd(buf, PATH_MAX);
	if (!res)
	{
		perror("getcwd");
		free(buf);
		return ;
		// exit(EXIT_FAILURE);
	}
	// if (buf != NULL)
		printf("%s\n", buf);
	free(buf);
}
