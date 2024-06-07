/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:36:33 by alounici          #+#    #+#             */
/*   Updated: 2024/06/01 14:38:34 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *ft_realloc(char *str, int i)
{
    char *res;

    res = malloc(sizeof(char) * (ft_strlen(str) - i));
    free (str);
    return (res);
}