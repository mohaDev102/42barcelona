/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:06 by alounici          #+#    #+#             */
/*   Updated: 2024/06/19 18:12:28 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_maplen(char **str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i])
    {
        i++;
    }
    return (i);
}

char	**ft_mapjoin(char **map, char *str)
{
	char	**res;
	int		i;
	int		j;
    int k = 0;
    (void)j;

	i = 0;
	j = 0;
	if (map == NULL || str == NULL)
		return (NULL);
    while (*map && map[k])
        k++;
    res = (char **)malloc((k + 2) * sizeof(char *));
	if (res == NULL)
	    return (NULL);
	while (i < k)
	{
        res[i] = ft_strdup(map[i]);
		i++;
	}
    res[i] = ft_strdup(str);
    i++;
    res[i] = NULL;
	return (res);
}

char	**ft_joinmap(char **map, char *str)
{
	char	**res;
	int		i;
	int		j;
    int k = 0;
    (void)j;

	i = 0;
	j = 0;
	if (map == NULL || str == NULL)
		return (NULL);
    while (*map && map[k])
        k++;
    res = (char **)malloc((k + 2) * sizeof(char *));
    res[0] = ft_strdup(str);
	if (res == NULL)
	    return (NULL);
	while (i < k)
	{
        res[i + 1] = ft_strdup(map[i]);
		i++;
	}
    res[k + 1] = NULL;
	return (res);
}

size_t	ft_strlenecho(const char *c)
{
	size_t	i;
    size_t len;

    len = 0;
	i = 0;
	while (c[i] != '\0')
	{
        if (c[i] != '\"' || c[i] != '\'')
		    len++;
        i++;
	}
	return (i);
}

char	*ft_substrecho(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (start >= ft_strlenecho(s))
		return (ft_strdup(""));
	if (len > ft_strlenecho(s) - start)
		len = ft_strlenecho(s) - start;
	res = ft_calloc(sizeof(char), len + 1);
	if (res == NULL || s == NULL)
		return (NULL);
	i = 0;
	while (start < ft_strlenecho(s) && i < len && s[start] != '$')
	{
        if (s[start] == '$')
        {
            res[i] = '\0';
            return (res);
        }
        if (s[start] != '\"' && s[start] != '$' && s[start] != '\'')
            res[i++] = s[start];
		start++;
	}
    res[i] = '\0';
	return (res);
}