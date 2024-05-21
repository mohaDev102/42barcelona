/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:15:13 by alounici          #+#    #+#             */
/*   Updated: 2024/05/20 20:49:19 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
//echo $?
//cd ok
//unset path

void    is_buildins2(t_cmd **tmp, t_list *envlist)
{
    int i;

    i = 0;
    if (ft_strcmp((*tmp)->args[0], "echo") == 0 && ft_strcmp((*tmp)->args[1], "-n") == 0)
        {
            i = i + 2;
            while ((*tmp)->args[i])
                ft_echo((*tmp)->args[i++], 1, envlist);
        }
        else if (ft_strcmp((*tmp)->args[0], "echo") == 0)
        {
            i++;
            while ((*tmp)->args[i])
                ft_echo((*tmp)->args[i++], 0, envlist);
        }
}

void    is_buildins(t_cmd **cmd, t_list *envlist)
{
    int i;
    t_cmd *tmp;

    tmp = *cmd;
    i = 1;
    // while (tmp)
    // {
        // if (ft_strcmp(tmp->args[0], "echo") == 0 && ft_strcmp(tmp->args[1], "-n") == 0)
        // {
        //     i = i + 2;
        //     while (tmp->args[i])
        //         ft_echo(tmp->args[i++], 1, envlist, error);
        // }
        // else if (ft_strcmp(tmp->args[0], "echo") == 0)
        // {
        //     i++;
        //     while (tmp->args[i])
        //         ft_echo(tmp->args[i++], 0, envlist, error);
        // }
        is_buildins2(tmp, envlist);
        if (ft_strcmp(tmp->args[0], "cd") == 0)
            ft_cd(tmp->args[1], &envlist);
        else if (ft_strcmp(tmp->args[0], "env") == 0)
            ft_env(&envlist);
        else if (ft_strcmp(tmp->args[0], "export") == 0 && tmp->args[1])
        {
            while (tmp->args[i])
                ft_export(&envlist, tmp->args[i++]);
        }
        // else if (ft_strcmp(tmp->args[0], "export"))
        //     ft_export_alone(&envlist);
        else if (ft_strcmp(tmp->args[0], "pwd") == 0)
            ft_pwd();
        else if (ft_strcmp(tmp->args[0], "unset") == 0)
        {
            while (tmp->args[i])
               ft_unset(&envlist, tmp->args[i++]);
        }
        tmp = tmp->next;
    // }
}