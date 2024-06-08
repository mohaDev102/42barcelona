/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:11:46 by alounici          #+#    #+#             */
/*   Updated: 2024/06/08 01:35:19 by alounici         ###   ########.fr       */
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
        if (!ft_isdigit(str[i]))
        {
            print_exit_error(str, 0);
            // print_exit_error(str);
            exit(255);
        }
        i++;
    }
}


void   print_exit_error(char *str, int neg)
{
    int i;

    i = 0;
    (void)str;
    // write(1, "ici", 3);
    write(2, "exit: ", 6);
    if (neg)
        write(1, "-", 1);
    while(str[i])
    {
            write(2, &str[i], 1);
            i++;
    }
    write(2, ": numeric argument required", 28);
}

// void print_limit_exit(char *str)
// {
//     int i;

//     i = 0;
//     (void)str;
//     write(2, "exit: ", 6);
//     while(str[i])
//             write(2, &str[i++], 1);
//     write(2, ": numeric argument required", 27);
// }

// char *clean_exit_space(char *str)

void print_limit_exit(char *str)
{
    int i;
    // int j;
    // int k;
    // char *res;

    i = 0;
    // (void)str;
    write(2, "exit: ", 6);
    while(str[i])
            write(2, &str[i++], 1);
    write(2, ": numeric argument required", 27);
}
// void print_limit_exit(char *str)
// {
//     int i;

//     i = 0;
//     (void)str;
//     write(2, "exit: ", 6);
//     while(str[i])
//             write(2, &str[i++], 1);
//     write(2, ": numeric argument required", 27);
// }

char *clean_exit_space(char *str)
{
    int i;
    int j;
    // int k;
    char *res;

    i = 0;
    // k = 0;
    j = 0;
    while (str[i] && ft_isspace(str[i]))
        i++;
    // write(1, &ft_itoa(i), 1);
    res = malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
    while (str[i] && !ft_isspace(str[i]))
    {
        res[j] = str[i];
        j++;
        i++;
    }
    res[j] = '\0';
    if (ft_strlen(res) == 0)
    {

        print_exit_error(str, 0);
        exit(255);
    }
    return (res);
}

char *clean_zero(char *str)
{
    int i;
    int j;
    char *res;

    j = 0; 
    i = 0;
    while (str[i] == '0')
        i++;
    j = ft_strlen(str) - (i);
    res = malloc(sizeof(char) * (j + 1));
    j = 0;
    while (str[i])
    {
        res[j] = str[i];
        j++;
        i++;
    }
    res[j] = '\0';
    // return (res);
    //     print_exit_error(str);
    //     exit(255);
    // }
    return (res);
}

void check_limit(char *str)
{
    int neg;
    // int i;

    // i = 0;
    // int i;

    // i = 0;
    neg = 0;
    if (*str == '-')
    {
        str++;
        neg = 1;
    }
    printf("%s\n", str);
    if (ft_strlen(str) > 19 && neg)
        print_exit_error(str, 1);
    else if (ft_strlen(str) > 19 && !neg)
        print_exit_error(str, 0);
    else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775807") > 0 && !neg)
        print_exit_error(str, neg);
    else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775808") > 0 && neg)
        print_exit_error(str, neg);
    else
        return;
    exit (255);
}

void ft_exit(char **args)
{
    
    if (args[1] == NULL || ft_strcmp(args[1], "--") == 0)
    {
        exit(0);
    }
    else if (!args[1][0])
    {
        write(2, "exit: : numeric argument required", 33);
        exit (255);
    }
    else if (args[1] && args[2])
    {
        write(2, "exit: too many arguments", 24);
        exit (1);
    }
    else if (args[1])
    {
        args[1] = clean_exit_space(args[1]);
        args[1] = clean_zero(args[1]);
        check_exit(args[1]);
        check_limit(args[1]);
    }
    exit (ft_atoi(args[1]));
}