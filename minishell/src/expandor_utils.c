/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:01 by alounici          #+#    #+#             */
/*   Updated: 2024/06/23 18:59:59 by alounici         ###   ########.fr       */
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
    char *left;
    char **res;

    res = join_var_name(str, 0);
    left = text_after_var(str);
    if (left != NULL)
       res = ft_mapjoin(res, left);
    free(str);
    return (res);
}

unsigned int strchrint(char *str, char c)
{
    unsigned int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (0);
}

char **join_var_name(char *str, unsigned int i)
{
    char *aux;
    char *var_name;
    char **res;

    var_name = ft_strdup(str);
    while (str[i] != '$' && str[i])
        i++;
    if (str[i] == '$' && str[i + 1])
    {
        var_name =  extract_var_name(str, i + 1);
        i++;
    }
    i++;
    if (ft_strlen(str) > i)
    {
        while(str[i])
        {
            if (str[i] == '$' && str[i + 1])
            {
                aux = extract_var_name(str, i);
                var_name = ft_strjoin(var_name, aux);
                free(aux);
            }
            i++;
        }
    }
    if (strchrint(str, '$') != (ft_strlen(str) - 1))
        res = ft_split(var_name, '$');
    else
    {
        res = malloc(sizeof(char *) * 2);
        res[0] = ft_strdup(var_name);
        res[1] = NULL;
    }
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
    return (var);
}
