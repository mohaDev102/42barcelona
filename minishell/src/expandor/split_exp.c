/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:08:48 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 13:15:26 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_count_word_exp(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == ' '))
		{
			i++;
		}
		if (s[i] == '\'' || s[i] == '\"')
		{
			cont++;
			i++;
		}
		else if (s[i])
		{
			cont++;
			while (s[i] && (s[i] != c && s[i] != ' ' && s[i] != '\''
					&& s[i] != '\"'))
				i++;
		}
	}
	return (cont);
}

int	splitexp3(char *s, char **res, int *i, int *j)
{
	int	k;

	k = *i;
	while (s[*i] && is_separator(s[*i], '$') && res[*j])
	{
		if (s[*i] == '\'' || s[*i] == '\"')
		{
			if (splitexp2(s, res, i, j) == 1)
				return (0);
		}
		k++;
		*i = k;
	}
	return (1);
}

char	**ft_splitexp(char *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;

	res = NULL;
	res = set_value_split(res, &i, &j, s);
	while (s[i] != '\0')
	{
		if (!splitexp3(s, res, &i, &j))
			return (res);
		set_start(&i, &start);
		while (s[i] && !is_separator(s[i], c))
			i++;
		if (i > start)
		{
			res[j] = ft_substr(s, start, (i - start));
			if (res[j] == NULL)
				return (ft_free_malloc(res, j));
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
