/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:11:29 by alounici          #+#    #+#             */
/*   Updated: 2024/06/18 18:20:49 by alounici         ###   ########.fr       */
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

int after_var(char *str)
{
    int j;
    int res;

    j = 0;
    res = 0;
    while(str[j])
    {
        if(str[j] == '$')
            res = j;
        j++;
    }
    return (res);
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