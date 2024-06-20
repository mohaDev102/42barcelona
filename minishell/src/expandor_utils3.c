/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:11:29 by alounici          #+#    #+#             */
/*   Updated: 2024/06/20 17:10:40 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

size_t	ft_strlenexp(const char *c)
{
	size_t	i;
    size_t len;

    len = 0;
	i = 0;
	while (c[i] != '\0')
	{
        if (c[i] != '\"' && c[i] != '\'')
		{
            // printf("dans str%c", c[i]);
            len++;
            i++;
        }
        else
            i++;
	}
    // printf("len str%ld", len);
	return (len);
}

char *clean_str(char *str, char c, int quote)
{
    int i;
    int j;
    int len;
    char *res;

    j = 0;
    i = 0;
    len = ft_strlenexp(str);
    (void)quote;
    if (len == 0)
        return (str);
    // printf("%d", len);
    // exit(1);
    res = malloc(sizeof(char) * (len + 1)); // - (quote)));
   if (!res)
        return (NULL);
    printf("%c", c);
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
    free(str);
    // printf("res: %s", res);
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