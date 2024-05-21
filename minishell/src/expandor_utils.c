/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:01 by alounici          #+#    #+#             */
/*   Updated: 2024/05/20 19:42:45 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *clean_str(char *str, int start, int end)
{
    char *res;
    int i;
    int j;

    i = 0;
    j = 0;
	// printf("ici%s", str);
    res = malloc(sizeof(char) * (ft_strlen(str) - 2));
    if (res == NULL)
        return (NULL);
    while (str[j])
    {
        if (j != start && j != end)
        {
            res[i++] = str[j++];
            // write(1, &res[i], 1);
        }
        else
            j++;
    }
    res[i] = '\0';
	// printf("ici%s", res);
    return(res);
}

char *extract_var_name(char *str, int i)
{
    int j;
    int k;
    char *var;

    j = i;
    k = 0;
    while (str[i] && ft_isprint(str[i]))
    {
        i++;
    }
    var = malloc(sizeof(char) * (i - j));
    while (j <= i)
    {
        var[k++] = str[j++];

    }
    var[k] = '\0';
    return (var);
}