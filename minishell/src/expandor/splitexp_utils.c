/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitexp_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:24:30 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 20:00:34 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ft_free_malloc(char **str, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	is_separator(char c, char sep)
{
	return (c == sep || c == ' ' || c == '\'' || c == '\"');
}

char	**set_value_split(char **res, int *i, int *j, char *s)
{
	res = (char **)malloc(sizeof(char *) * (ft_count_word(s, '$') + 1));
	if (res == NULL)
		return (NULL);
	*i = 0;
	*j = 0;
	return (res);
}

void	set_start(int *i, int *start)
{
	if (*i > 0)
		*start = *i - 1;
	else
		*start = *i;
}

int	splitexp2(char *s, char **res, int *i, int *j)
{
	int len;

	len = ft_count_word(s, '$');
	res[*j] = ft_substr(s, *i, 1);
	if (res[*j] == NULL)
	{
		ft_free_malloc(res, *j);
		return (0);
	}
	(*i)++;
	(*j)++;
	if (*j == len)
	{
		res[*j] = NULL;
		return (1);
	}
	return (2);
}