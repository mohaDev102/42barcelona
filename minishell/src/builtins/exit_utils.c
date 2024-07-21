/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:11:48 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 20:56:03 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	check_exit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '\'' && str[i] != '\"')
		{
			print_exit_error(str, 0);
			free(str);
			exit_status(2);
			exit(2);
		}
		i++;
	}
}

void	check_exit_many(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			print_exit_error(str, 0);
			i = 0;
			free(str);
			str = NULL;
			exit_status(255);
			exit(255);
		}
		i++;
	}
}

void	check_limit_many(char *str)
{
	int	neg;

	neg = 0;
	if (*str == '-')
	{
		str++;
		neg = 1;
	}
	if (ft_strlen(str) > 19 && neg)
		print_exit_error(str, 1);
	else if (ft_strlen(str) > 19 && !neg)
		print_exit_error(str, 0);
	else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775807") > 0
		&& !neg)
		print_exit_error(str, neg);
	else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775808") > 0
		&& neg)
		print_exit_error(str, neg);
	else
		return ;
	free(str);
	exit(255);
}

void	handle_exit(char *str)
{
	int	num;
	int	ex;

	num = ft_atoi(str);
	num = num % 256;
	ex = num + 256;
	if (num < 0)
		exit(ex);
	else
		exit(num);
}

void	check_limit(char *str)
{
	int	neg;

	neg = 0;
	if (*str == '-')
		neg = 1;
	if (ft_strlen(str) > 19 && neg)
		print_exit_error(str, 1);
	else if (ft_strlen(str) > 19 && !neg)
		print_exit_error(str, 0);
	else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775807") > 0
		&& !neg)
		print_exit_error(str, neg);
	else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775808") > 0
		&& neg)
		print_exit_error(str, neg);
	else
		handle_exit(str);
	exit(255);
}
