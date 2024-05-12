/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:14:33 by alounici          #+#    #+#             */
/*   Updated: 2024/05/11 17:30:57 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(void)
{
	char	*buf;

	buf = malloc(PATH_MAX + 1);
	if (!buf)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	buf = getcwd(buf, PATH_MAX);
	if (!buf)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", buf);
}
