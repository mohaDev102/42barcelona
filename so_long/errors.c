/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 04:11:27 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/16 04:11:29 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_param(char *msg, char **map)
{
	if (map)
		free(map);
	if (ft_strlen(msg) != 0)
		write(1, msg, ft_strlen(msg));
	exit(1);
}
