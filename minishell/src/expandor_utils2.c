/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:06 by alounici          #+#    #+#             */
/*   Updated: 2024/06/23 17:45:58 by alounici         ###   ########.fr       */
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
	// int		j;
    int k = 0;

	i = 0;
	// j = 0;
	if (map == NULL || str == NULL)
		return (NULL);
    while (*map && map[k])
        k++;
    res = (char **)malloc((k + 2) * sizeof(char *));
	// printf("k = %d", k);
	if (res == NULL)
	    return (NULL);
	while (i < k)
	{
        res[i] = map[i]; //strdup(map[i]);
		i++;
	}
    res[i] = str;
	// i = 0;
	// // while (res[i])
	// {
		// printf("res%s\n", res[0]);
		// printf("res%s\n", res[1]);
		// i++;
	// }
	free(map);
    i++;
    res[i] = NULL;
		// free(str);
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
	j = 1;
	if (map == NULL || str == NULL)
		return (NULL);
	while (*map && map[k])
		k++;
    res = (char **)malloc((k + 2) * sizeof(char *));
	if (!res)
		return (NULL);
    res[0] = str;
	// if (res == NULL)
	//     return (NULL);
	while (i < k)
	{
        res[j] = map[i];
		// free(map[i]);
		i++;
		j++;
	}
	// printf("i: %d", i);
	// printf("k: %d", k);

	free(map);
    res[k + 1] = NULL;
	// free(str);
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

char	*ft_substrecho(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (start >= ft_strlenecho(s))
		return (NULL);
	if (len > ft_strlenecho(s) - start)
		len = ft_strlenecho(s) - start;
	res = ft_calloc(len + 1, sizeof(char)); //, len + 1);
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
	// free(s);
	return (res);
}

