/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:11:46 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 21:44:24 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_exit_error(char *str, int neg)
{
	int	i;

	i = 0;
	(void)str;
	(void)neg;
	write(2, "exit: ", 6);
	if (neg)
		write(1, "-", 1);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, ": numeric argument required", 28);
	exit(2);
}

char	*clean_exit_space(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	set_value_exit(&i, &j, &len);
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			len++;
		i++;
	}
	if (i == len)
		return (str);
	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		exit_malloc(str);
	j = copy_res(str, &res, j);
	res[j] = '\0';
	if (ft_strlen(res) == 0)
		empty_exit(res, str);
	free(str);
	return (res);
}

char	*clean_zero(char *str)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	i = 0;
	while (str[i] == '0')
		i++;
	j = ft_strlen(str) - (i);
	res = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[i])
	{
		res[j] = str[i];
		j++;
		i++;
	}
	res[j] = '\0';
	free(str);
	return (res);
}

int	ft_allspaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(char **args)
{
	if (args[1] == NULL || ft_strcmp(args[1], "--") == 0)
		exit(0);
	else if (!args[1][0])
	{
		print_exit_error(args[1], 0);
		exit(2);
	}
	else if (ft_strcmp(args[1], "\"\"") == 0 || ft_allspaces(args[1]) == 1)
	{
		write(2, "exit: : numeric argument required", 33);
		exit(2);
	}
	else if (args[1] && args[2])
	{
		exit_many(args);
		return ;
	}
	else if (args[1])
	{
		args[1] = clean_exit_space(args[1]);
		args[1] = clean_zero(args[1]);
		check_exit(args[1]);
		check_limit(args[1]);
	}
}
