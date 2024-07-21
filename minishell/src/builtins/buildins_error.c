/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:25:23 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 21:40:17 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_export_error(char *str)
{
	int	i;

	i = 0;
	write(2, "export: `", 9);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "': not a valid identifier\n", 26);
	exit_status(1);
}

void	empty_exit(char *res, char *str)
{
	free(res);
	print_exit_error(str, 0);
	free(str);
	exit(255);
}

void	exit_malloc(char *str)
{
	free(str);
	print_exit_error("Memory allocation failed", 0);
	exit(255);
}

int	copy_res(char *str, char **res, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			*res[j++] = str[i];
		i++;
	}
	return (j);
}

void	set_value_exit(int *i, int *j, int *len)
{
	*i = 0;
	*j = 0;
	*len = 0;
}
