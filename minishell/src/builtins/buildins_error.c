/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:25:23 by alounici          #+#    #+#             */
/*   Updated: 2024/05/30 23:50:25 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void    print_export_error(char *str)
{
    int i;

    i = 0;
    write(2, "export: `", 9);
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    write(2, "': not a valid identifier\n", 26);
    exit_status(1);
}


// write(2, "export: '", 9);
// 		printf("%s", str);
// 		write(2, "': not a valid identifier", 26);