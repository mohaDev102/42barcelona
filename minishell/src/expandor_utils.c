/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:01 by alounici          #+#    #+#             */
/*   Updated: 2024/06/08 13:09:24 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_maplen(char **str)
{
    int i;
    // int j;

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
    int k = 2;
    (void)j;

	i = 0;
	j = 0;
	if (map == NULL || str == NULL)
		return (NULL);
    // printf("%s\n", map[0]);
    // while (map[k])
    //     k++;
	res = malloc(sizeof(char *) * k);
    // write(1, "ici", 3);
	if (res == NULL)
		return (NULL);
	while (map[i])
	{
        res[i] = ft_strdup(map[i]);
		i++;
	}
    // printf("%s", res[0]);
    // exit(0);
    // res[i] = malloc(sizeof(char) * (ft_strlen(str) + 1));
    // if (res[i] == NULL) // Vérifier que l'allocation a réussi
    // {
    //     // Libérer la mémoire allouée jusqu'à présent en cas d'échec
    //     while (i-- > 0)
    //         free(res[i]);
    //     free(res);
    //     return (NULL);
    // }
	// while (str[j])
	// {
	// 	res[i][j] = str[j];
    //     j++;
	// }
	// res[i] = '\0';
//    res[i] = NULL;
	return (res);
}

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

char **join_var_name(char *str, int i)
{
    char *aux;
    char *var_name;
    char **res;
    char *left;

    var_name =  extract_var_name(str, i);
    i++;
    while(str[i])
    {
        // i++;
        if (str[i] == '$')
        {
            aux = extract_var_name(str, i);
           var_name = ft_strjoin(var_name, aux);
        }
        else if (str[i] == '\"')
        {
            left = ft_substr(str, i + 1, ft_strlen(str) - i);
            // printf("%s\n", left);
            // res = ft_strjoin(var_name, left);
            // return (res);
        }
        i++;
    }
    res = ft_split(var_name, '$');
    res = ft_mapjoin(res, left);
        
    // start = 0;
    // while(res[start])
    // {
        // printf("%s\t%s\n", res[0], res[1]);
    //     start++;
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
    while (str[i] && ft_isprint(str[i]) && str[i + 1] != '$' && str[i + 1] != '\"')
        i++;
    var = malloc(sizeof(char) * i + 1);
    while (j <= i)
            var[k++] = str[j++];
    var[k] = '\0';
    // printf("var%s\n", var);
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
    if (even % 2 == 0)
        return (even);
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