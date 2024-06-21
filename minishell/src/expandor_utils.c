/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:01 by alounici          #+#    #+#             */
/*   Updated: 2024/06/22 01:18:02 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *text_before_var(char *str)
{
    int i;
    char *first;

    i = 0;
    while (str[i] != '$' && str[i])
        i++;
    if (i > 1 && str[0] != '$')
    {
        first = ft_substrecho(str, 0, i);
        return(first);
    }
    return(NULL);
}

char *text_after_var(char *str)
{
    int i;
    char *left;

    i = after_var(str);
    while(str[i])
    {
         if (str[i] == '\"' || str[i] == '\'' || (ft_isalpha(str[i + 1]) == 0 || ft_isdigit(str[i + 1] == 1)))
        {
            left = ft_substrecho(str, i + 1, ft_strlen(str) - i - 1);
            return (left);
        }
        i++;
    }
    return (NULL);

}

char **assembl_var(char *str)
{
    char *first;
    char *left;
    char **res;
    // int i = 0;

// printf("%s", str);
//     write(1, "ici", 3);
    first = text_before_var(str);
    res = join_var_name(str, 0);
    left = text_after_var(str);
    if (first != NULL)
    {
        res = ft_joinmap(res, first);
    }
    if (left != NULL)
        res = ft_mapjoin(res, left);
    // while (res[i])
    // {
    //     printf("%s", res[i]);
    //         i++;
    // }
    return (res);
}

char **join_var_name(char *str, int i)
{
    char *aux;
    char *var_name;
    char **res;

    while (str[i] != '$' && str[i])
        i++;
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
           var_name = ft_strjoin(var_name, aux);
            free(aux);
        }
        i++;
    }
    res = ft_split(var_name, '$');
    free(var_name);
    return (res);
}

char *extract_var_name(char *str, int i)
{
	int j;
	int k;
    char *var;

    j = i;
    k = 0;
    while (str[i] && (ft_isalpha(str[i + 1]) || ft_isdigit(str[i + 1])) \
    && str[i + 1] != '$' && str[i + 1] != '\"' && str[i + 1] != '\'')
        i++;
    var = malloc(sizeof(char) * (i - j) + 2);
    if (var == NULL)
        return(NULL);
    while (j <= i)
            var[k++] = str[j++];
    var[k] = '\0';
    // free(str);
    return (var);
}
