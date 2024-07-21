/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:42:34 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 11:47:33 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_update(char **str, int j, char *substr)
{
	free(str[j]);
	str[j] = ft_strdup(substr);
	free(substr);
}

void	value_set(int *flag, int *l, int *k)
{
	*flag = 0;
	*l = 0;
	*k = 0;
}

int	check_quote(char *str, int i, int *count)
{
	int	j;

	j = i + 1;
	*count += 1;
	while (str[j] && (str[j] != str[i]))
	{
		j++;
	}
	if (str[j] == str[i])
		*count += 1;
	return (j - i);
}

int	closed_quote(char *str)
{
	int	i;
	int	single;
	int	doble;

	i = 0;
	single = 0;
	doble = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i += check_quote(str, i, &single);
		if (str[i] == '\"')
			i += check_quote(str, i, &doble);
		if (str[i] == '\0')
			break ;
		i++;
	}
	if (((single > 0) && (single % 2 != 0)) || ((doble > 0) && (doble
				% 2 != 0)))
		return (0);
	return (1);
}

int	quote_erase(char **str, int j, int i)
{
	char	*substr;
	int		k;

	k = 0;
	substr = malloc(sizeof(char) * (ft_strlen(str[j])));
	if (substr == NULL)
		return (-1);
	k = quote_clean(str, j, substr, i);
	if ((unsigned int)k == ft_strlen(str[j]))
		return (0);
	return (k);
}
