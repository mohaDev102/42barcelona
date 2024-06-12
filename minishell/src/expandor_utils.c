/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:01 by alounici          #+#    #+#             */
/*   Updated: 2024/06/10 16:42:38 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// int ft_maplen(char **str)
// {
//     int i;

//     i = 0;
//     if (str == NULL)
//         return (0);
//     while (str[i])
//     {
//         i++;
//     }
//     return (i);
// }
// char	**ft_mapjoin(char **map, char *str)
// {
// 	char	**res;
// 	int		i;
// 	int		j;
//     int k = 0;
//     (void)j;

// 	i = 0;
// 	j = 0;
// 	if (map == NULL || str == NULL)
// 		return (NULL);
//     while (*map && map[k])
//         k++;
//     res = (char **)malloc((k + 2) * sizeof(char *));
// 	if (res == NULL)
// 	    return (NULL);
// 	while (i < k)
// 	{
//         res[i] = ft_strdup(map[i]);
// 		i++;
// 	}
//     res[i] = ft_strdup(str);
//     i++;
//     res[i] = NULL;
// 	return (res);
// }

// char	**ft_joinmap(char **map, char *str)
// {
// 	char	**res;
// 	int		i;
// 	int		j;
//     int k = 0;
//     (void)j;

// 	i = 0;
// 	j = 0;
// 	if (map == NULL || str == NULL)
// 		return (NULL);
//     while (*map && map[k])
//         k++;
//     res = (char **)malloc((k + 2) * sizeof(char *));
//     res[0] = ft_strdup(str);
// 	if (res == NULL)
// 	    return (NULL);
// 	while (i < k)
// 	{
//         res[i + 1] = ft_strdup(map[i]);
// 		i++;
// 	}
//     res[k + 1] = NULL;
// 	return (res);
// }

char *clean_str(char *str, char c, int quote)
{
    int i;
    int j;
    char *res;

    j = 0;
    i = 0;
    res = malloc(sizeof(char) * ((ft_strlen(str) + 1) - quote));
   if (res == NULL)
        return (NULL);
    while (str[i])
    {
        if (str[i] != c)
        {
            res[j] = str[i];
            j++;
        }
        i++;
    }
    res[j] = '\0';
    return(res);
}
// size_t	ft_strlenecho(const char *c)
// {
// 	size_t	i;
//     size_t len;

//     len = 0;
// 	i = 0;
// 	while (c[i] != '\0')
// 	{
//         if (c[i] != '\"')
// 		    len++;
//         i++;
// 	}
// 	return (i);
// }


// char	*ft_substrecho(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*res;

// 	if (start >= ft_strlenecho(s))
// 		return (ft_strdup(""));
// 	if (len > ft_strlenecho(s) - start)
// 		len = ft_strlenecho(s) - start;
// 	res = ft_calloc(sizeof(char), len + 1);
// 	if (res == NULL || s == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (start < ft_strlenecho(s) && i < len && s[start] != '$')
// 	{
//         if (s[start] == '$')
//         {
//             res[i] = '\0';
//             return (res);
//         }
//         if (s[start] != '\"' && s[start] != '$')
//             res[i++] = s[start];
// 		start++;
// 	}
//     res[i] = '\0';
// 	return (res);
// }

char **join_var_name(char *str, int i)
{
    char *aux;
    char *var_name;
    char **res;
    char *temp;
    char *left;
    char *first;
    int flag1 = 0;
    int flag2 = 0;

    i = 0;
    while (str[i] != '$' && str[i])
        i++;
    if (i > 1 && str[0] != '$')
    {
        flag1 = 1;
        first = ft_substrecho(str, 0, i);
    }
    if (str[i] == '$')
    {
        var_name =  extract_var_name(str, i + 1);
        i++;
    }
    i++;
    while(str[i])
    {
        if (str[i] == '$')
        {
            aux = extract_var_name(str, i);
            temp = var_name;
           var_name = ft_strjoin(var_name, aux);
            free(aux);
            free(temp);
        }
        else if (str[i] == '\"')
        {
            flag2 = 1;
            left = ft_substrecho(str, i + 1, ft_strlen(str) - i - 1);
        }
        i++;
    }
    res = ft_split(var_name, '$');
    if (first != NULL && flag1 == 1)
    {
        res = ft_joinmap(res, first);
    }
    if (left != NULL && flag2 == 1)
        res = ft_mapjoin(res, left);
    // i = 0;
    // while (res[i])
    // {
    //     printf("res %s\n", res[i++]);
    // }
    return (res);
}

char *extract_var_name(char *str, int i)
{
    int j;
    int k;
    char *var;

    j = i;
    k = 0;
    // printf("var 1 %s\n", str);
    while (str[i] && ft_isprint(str[i]) && str[i + 1] != '$' && str[i + 1] != '\"')
        i++;
    var = malloc(sizeof(char) * i + 1);
    while (j <= i)
            var[k++] = str[j++];
    var[k] = '\0';
    // printf("var 2 %s\n", var);
    return (var);
}

int check_quote_number(char *str, char c)
{
    int i;
    int even;

    i = 0;
    even = 0;
    while (str[i])
    {
        if (str[i] == c)
            even++;
        i++;
    }
    if (even % 2 == 0 || even == 0)
        return (1);
    return (0);
}

char *last_exit()
{
    char *res;
    res = ft_itoa(exit_status(0));
    return (res);
}

int	exit_status(int value)
{
	static int	prev = 0;
	int			ret;

	ret = prev;
	prev = value;
	return (ret);
}