/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:58:53 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/16 02:58:55 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_game	g;
	t_map	map;
	t_map	*map_pars;

	map_pars = check_param(argc, argv, &map);
	init_game(map_pars, &g);
	return (0);
}
