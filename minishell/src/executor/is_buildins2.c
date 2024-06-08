/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_buildins2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:00:10 by alounici          #+#    #+#             */
/*   Updated: 2024/06/06 20:45:59 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int exec_echo_n(int nindex, char **args, t_list *envlist)
{
    int i;
    int auxindex;

    auxindex = nindex;
    i = 0;
    while (args[i])
        i++;
    if (nindex != 0)
    {
        nindex++;
        while (args[nindex])
		{
        	ft_echo(args[nindex++], 0, envlist);
            if (i - nindex >= 1 && nindex > auxindex)
                write(1, " ", 1);
        }
        return (1);
    }
    return (0);
}

void exec_echo(int i, char **args, t_list *envlist)
{
    while (args[i])
    {
        if (i > 1)
            write(1, " ", 1);
        ft_echo(args[i++], 1, envlist);
    }
    write(1, "\n", 1);
}