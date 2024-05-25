/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:15:13 by alounici          #+#    #+#             */
/*   Updated: 2024/05/25 19:14:16 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
//echo $?
//cd ok
//unset path

int    is_buildins2(t_cmd **tmp, t_list *envlist)
{
    int i;

    i = 0;
    if (ft_strcmp((*tmp)->args[0], "echo") == 0) //&& ft_strcmp((*tmp)->args[1], "-n") == 0)
        {
            if ((*tmp)->args[1] && ft_strcmp((*tmp)->args[1], "-n") == 0)
            {
                i = i + 2;
                while ((*tmp)->args[i])
                ft_echo((*tmp)->args[i++], 0, envlist);
                return (1);
            }
            else
            {
                i++;
                while ((*tmp)->args[i])
                    ft_echo((*tmp)->args[i++], 1, envlist);
                return(1);
            }
        }
        return (0);
}

int    is_buildins(t_cmd **cmd, t_list **envlist)
{
    int i;
    t_cmd *tmp;

    // envlist = generate_env_list(env, &envlist);
    // printf("envlist = %s%s", envlist->name, envlist->content);
    tmp = *cmd;
    i = 1;
    //  write(1, "ic222\n\n", 7);
    if (is_buildins2(&tmp, *envlist) == 1)
        return (1);
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
        // printf("%s", (*envlist)->name);
    // while ((*envlist) != NULL)
    // {
    //     printf("%s\t%s\n",(*envlist)->name, (*envlist)->content);
    //     envlist = &(*envlist)->next;
        
    // }
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
        // write(2, "si", 2);
        ft_export_alone(envlist);
        return (1);
    }
    return (0);
    // tmp = tmp->next;
}