/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:01 by alounici          #+#    #+#             */
/*   Updated: 2024/06/02 16:17:18 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

    var_name =  extract_var_name(str, i);
    while(str[i])
    {
        if (str[i] == '$')
        {
            aux = extract_var_name(str, i);
           var_name = ft_strjoin(var_name, aux);
        }
        i++;
    }
    res = ft_split(var_name, '$');
    return (res);
}

char *extract_var_name(char *str, int i)
{
    int j;
    int k;
    char *var;

    j = i;
    k = 0;
    while (str[i] && ft_isprint(str[i]) && str[i + 1] != '$')
        i++;
    var = malloc(sizeof(char) * i + 1);
    while (j <= i)
    {
        var[k++] = str[j++];
    }
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