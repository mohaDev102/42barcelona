/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:48:55 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/07 11:48:56 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movePlayer(Map *map, t_flood *game, int new_x, int new_y)
{
	game->x = game->player_x;
	game->y = game->player_y;
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	erasePlayer(game, game->x, game->y);
	drawPlayer(game);
	if (exitGame(map, game->player_x, game->player_y)
		&& game->coins == game->ncollect)
		ft_exit("Has ganado", 0);
}

void	erasePlayer(t_flood *game, int x, int y)
{
	int	start_x;
	int	start_y;

	start_x = x * CELL_SIZE;
	start_y = y * CELL_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, start_x,
		start_y);
}

void	drawPlayer(t_flood *game)
{
	int	start_x;
	int	start_y;

	start_x = game->player_x * CELL_SIZE;
	start_y = game->player_y * CELL_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, start_x,
		start_y);
}

void	printCell(t_flood *g, int x, int y, char type)
{
	int	start_x;
	int	start_y;

	start_x = x * CELL_SIZE;
	start_y = y * CELL_SIZE;
	if (type == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img_floor, start_x, start_y);
	else if (type == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall, start_x, start_y);
	else if (type == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img_player, start_x,
			start_y);
	else if (type == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_exit, start_x, start_y);
	else if (type == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_coin, start_x, start_y);
}