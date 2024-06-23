/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:37:03 by alounici          #+#    #+#             */
/*   Updated: 2024/06/23 17:57:33 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/minishell.h"

void ft_tilde(t_list *envlist)
{
    char *home;

    home = my_getenv(envlist, "HOME", 0, 0);
    printf("%s: Is a directory\n", home);
}