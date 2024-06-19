/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:11:48 by alounici          #+#    #+#             */
/*   Updated: 2024/06/19 22:00:56 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void    check_exit(char *str)
{
    int i = 0;

    if ((str[i] == '-' || str[i] == '+') && str[i + 1])
        i++;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0)
        {
            print_exit_error(str, 0);
            free(str);
            exit_status(255);
            exit(255);
        }
        i++;
    }
}
void    check_exit_many(char *str)
{
    int i = 0;

        if ((str[i] == '-' || str[i] == '+') && str[i + 1])
            i++;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0)
        {
            // write(1, "dans check", 10);
            print_exit_error(str, 0);
            // print_exit_error(str);
            i = 0;
            // while(str[i] != NULL)
            // {
            //     free(str[i]);
            //     i++;
            // }
            free(str);
            str = NULL;
            exit_status(255);
            exit(255);
        }
        i++;
    }
}

void check_limit_many(char *str)
{
    int neg;

    neg = 0;
    if (*str == '-')
    {
        str++;
        neg = 1;
    }
    if (ft_strlen(str) > 19 && neg)
        print_exit_error(str, 1);
    else if (ft_strlen(str) > 19 && !neg)
        print_exit_error(str, 0);
    else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775807") > 0 && !neg)
        print_exit_error(str, neg);
    else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775808") > 0 && neg)
        print_exit_error(str, neg);
    else
        return ;
    exit (255);
}

void check_limit(char *str)
{
    int neg;

    neg = 0;
    if (*str == '-')
    {
        str++;
        neg = 1;
    }
    if (ft_strlen(str) > 19 && neg)
        print_exit_error(str, 1);
    else if (ft_strlen(str) > 19 && !neg)
        print_exit_error(str, 0);
    else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775807") > 0 && !neg)
        print_exit_error(str, neg);
    else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775808") > 0 && neg)
        print_exit_error(str, neg);
    else
        exit(ft_atoi(str));
    exit (255);
}

// void free_args(char **args)
// {
//     int i;

//     i = 0;
//     while(args[i])
//     {
//         free(args[i]);
//         i++;
//     }
//     free(args);
// }