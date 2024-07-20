/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:08:48 by alounici          #+#    #+#             */
/*   Updated: 2024/07/17 20:02:04 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	ft_count_word(char const *s, char c)
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
			while (s[i] && (s[i] != c && s[i] != ' ' && s[i] != '\'' && s[i] != '\"'))
			{
				i++;
			}
		}
	}
	// printf("cont %d\n", cont);
	return (cont);
}

static char	**ft_free_malloc(char **str, size_t j)
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

static int	is_separator(char c, char sep) {
	return (c == sep || c == ' ' || c == '\'' || c == '\"');
}

char	**ft_splitexp(char *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;
	int len = ft_count_word(s, c);

	// printf("%d\n", len);

	res = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && is_separator(s[i], c))
		{
			if (s[i] == '\'' || s[i] == '\"')
			{
				res[j] = ft_substr(s, i, 1);
				if (res[j] == NULL)
					return (ft_free_malloc(res, j));
				// i++;
				j++;
				if (j == len)
				{
					res[j] = NULL;
					return(res);
				}
			}
			i++;
		}
		// if (i > 0 && (ft_strcmp(res[j - 1], "\"") == 0 || ft_strcmp(res[j - 1], "\'") == 0))
		if (i > 0) // && s[i - 1] == '$')
			start = i - 1;
		else
			start = i;
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
	// free(s);
	res[j] = NULL;
	return (res);
}

// char	**ft_splitexp(char const *s, char c)
// {
// 	char	**res;
// 	int		i;
// 	int		j;
// 	int		start;

// 	// printf("word %d\n", ft_count_word(s, c));
// 	res = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
// 	if (res == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	start = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (i > 0 && ((s[i] != c && s[i - 1] == c) || (s[i] != ' ' && s[i - 1] == ' ')))
// 			start = i;
// 		if (s[i] != c && ((s[i + 1] == c || s[i + 1] == '\0') || (s[i + 1] == ' ' || s[i + 1] == '\0')))
// 		{
// 			res[j] = ft_substr(s, start, i - start + 1);
// 			printf("res %s", res[j]);
// 			j++;
// 			if (res[j - 1] == NULL)
// 				return (ft_free_malloc(res, j - 1));
// 		}
// 		i++;
// 	}
// 	res[j] = NULL;
// 	return (res);
// }