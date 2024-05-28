/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:15:13 by alounici          #+#    #+#             */
/*   Updated: 2024/05/27 23:02:52 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
//echo $?
//cd ok
//unset path

int echo_flag(char **args, int i)
{
    // int ;
    int j;
    int ret;

    ret = 0;
    // i = 1;
    j = 0;
    while (args[i])
    {

        if (args[i][0] == '-' && args[i][1] == 'n' && ft_strcmp(args[i - 1], "echo"))
        {
            j = 1;
            while (args[i][j] == 'n')
            {
                j++;
            }
            ret++;
        }
        i++;
    }
   return (ret);    
}

int    is_buildins2(t_cmd **tmp, t_list *envlist)
{
    int i;
    int ret;
    int j;

    ret = 0;
    i = 0;
    j = 0;
    if ((*tmp)->args[0])
    {
        while ((*tmp)->args[i])
        {
            if (ft_strcmp((*tmp)->args[i], "echo") == 0)
            {
                ret  = echo_flag(&(*tmp)->args[i], i);
                if (ret != 0)
                {
                    ret++;
                    while ((*tmp)->args[ret])
                    {
                        ft_echo((*tmp)->args[ret], 0, envlist);
                        // write(1, " ", 1);
                        ret++;
                    }
                    return (1);
                }
                else
                {
                    i++;
                    while ((*tmp)->args[i])
                    {
                        if (i > 1)
                        {
                            write(1, " ", 1);
                        }
                        ft_echo((*tmp)->args[i++], 1, envlist);
                    }
                    write(1, "\n", 1);
                    return(1);
                }
            }
            i++;
        }
    }
        return (0);
}

int    is_buildins(t_cmd **cmd, t_list **envlist)
{
    int i;
    t_cmd *tmp;
    // int i;

    // i = 0;
    // envlist = generate_env_list(env, &envlist);
    tmp = *cmd;
    // printf("cmd = %s", tmp->args[0]);
    i = 1;
    //  write(1, "ic222\n\n", 7);
        while (tmp)
        {
            while (tmp->args[i])
            {
                // if (tmp->args[0])
                    if (is_buildins2(&tmp, *envlist) == 1)
                        return (1);
                // }
                else if (ft_strcmp(tmp->args[0], "cd") == 0)
                {
                    ft_cd(tmp->args[1], envlist);
                    return (1);
                }
                else if (ft_strcmp(tmp->args[0], "unset") == 0)
                {
                    while (tmp->args[i])
                        ft_unset(envlist, tmp->args[i++]);
                    return (1);
                }
                else if (ft_strcmp(tmp->args[0], "export") == 0 && tmp->args[1])
                {
                    while (tmp->args[i])
                        ft_export(envlist, tmp->args[i++]);
                        return (1);
                }
                else if (ft_strcmp(tmp->args[0], "env") == 0)
                {
                    ft_env(envlist);
                    return (1);
                }
                else if (ft_strcmp(tmp->args[0], "pwd") == 0)
                {
                    ft_pwd();
                    return (1);
                }
                else if (ft_strcmp(tmp->args[0], "exit") == 0)
                {
                    ft_exit(tmp->args);
                    return (1);
                }
                else if (ft_strcmp(tmp->args[0], "export") == 0)
                {
                    ft_export_alone(envlist);
                    return (1);
                }
            i++;
        }
        tmp = tmp->next;

        }
        
    // }
    return (0);
    // tmp = tmp->next;
}