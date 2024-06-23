/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:11:29 by alounici          #+#    #+#             */
/*   Updated: 2024/06/23 15:05:53 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

size_t	ft_strlenexp(const char *str, char c)
{
	size_t	i;
    size_t len;

    len = 0;
	i = 0;
	while (str[i] != '\0')
	{
        if (str[i] != c) //&& c[i] != '\'')
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
char *quit_quote(char *str, int i, int last)
{
    char *res;
    int j = 0;

    res = malloc(sizeof(char) * (ft_strlen(str)));
    while(str[j])
    {
        if (j != i && j != last)
            res[j] = str[j];
        j++;
    }
    res[j] = '\0';
    free(str);
    return(res);
}


char *clean_str(char *str, char c, int quote)
{
    int i;
    int j;
    int len;
    char *res;

    j = 0;
    i = 0;
    len = ft_strlenexp(str, c);
    (void)quote;
    if (len == 0)
        return (str);
    // printf("%d", len);
    // exit(1);
    res = malloc(sizeof(char) * (ft_strlen(str) + 1)); // - (quote)));
   if (!res)
        return (NULL);
    // printf("%c", c);
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

// char *clean_str(char *str, char c, int quote)
// {
// //     char *res;
// //     int i;
// //     // int last;

// //     i = 0;
// //     (void)quote;
// //     // last = len;
// //     res = ft_strdup(str);
// //     while(res[i])
// //     {
// //     int len = ft_strlen(res) + 1;
// //         if (res[i] == c)
// //         {

// //             while (len > 0)
// //             {
// //                 if (res[len] == c)
// //                     res = quit_quote(str, i, len);
// //                 len--;
// //             }
// //         }
// //     }
// //     // free(str);
// //     return(res);
// // }
//     int i;
//     int j;
//     int len;
//     char *res;

//     j = 0;
//     i = 0;
//     len = ft_strlenexp(str, c);
//     (void)quote;
//     if (len == 0)
//         return (str);
//     res = malloc(sizeof(char) * (ft_strlen(str) + 1)); // - (quote)));
//    if (!res)
//         return (NULL);
//     while (str[i])
//     {
//         if (str[i] != c)
//         {
//             res[j] = str[i];
//             j++;
//         }
//         i++;
//     }
//     // while(res[i])
//     // {
//     // int len = ft_strlen(res) + 1;
//     //     if (res[i] == c)
//     //     {

//     //         while (len > 0)
//     //         {
//     //             if (res[len] == c)
//     //             {
//     //                     res = quit_quote(res, i, len);
//     //             }
//     //             len--;
//     //         }
//     //     }
//     //     i++;
//     // }
//                     // printf("res: %s", res);
//     res[j] = '\0';
//     free(str);
//     return(res);
// }


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
int check_quote_number(char *str, char c, int i)
{
    i++;
    int j = 0;

    while (str[i])
    {
        if (str[i] == c)
            j++;
        i++;
    }
    if (j % 2 == 0 && j != 0)
        return(j);
    if (j == 0)
        return (1);
    return (0);
}

int check_quote_number_dollar(char *str)
{
    int even;
    char c;
    int first;
    int i;

    i = 0;
    first = 0;
    even = 0;
    while (str[i])
    {
        if ((str[i] == '\'' || str[i] == '\"') && first == 0)
        {
            c = str[i];
            first = 1;
            even++;
        }
        else if (str[i] == c)
            even++;
            // return (i);
        i++;
    }
    // printf("%d\n", even);
    if (even % 2 == 0 && even != 0)
        return(even);
    if (even == 0)
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