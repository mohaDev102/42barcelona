/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:47:53 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/07 11:47:57 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height
		|| map->grid[y][x] == '1' || map->grid[y][x] == 'F')
		return ;
	if (map->grid[y][x] == 'C')
		map->ncoins++;
	if (map->grid[y][x] == 'E')
		map->nexit = 1;
	map->grid[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	caracter_map(t_map *map, t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			c = map->grid[i][j];
			if (map->grid[i][j] == 'P')
			{
				game->nplayer++;
				map->x = i;
				map->y = j;
			}
			else if (map->grid[i][j] == 'E')
				map->nexit++;
			else if (map->grid[i][j] == 'C')
				game->coins++;
			if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
				ft_exit("caracter invalido", 1);
		}
	}
}

int	validate_map(t_map *map)
{
	int		player_count;
	int		coin_count;
	t_game	game;

	player_count = 0;
	coin_count = 0;
	game.coins = 0;
	game.nplayer = 0;
	verify_walls(map);
	caracter_map(map, &game);
	game.ncollect = game.coins;
	if (map->nexit != 1 || game.nplayer != 1 || game.coins == 0)
		ft_exit("Error\n", 1);
	flood_fill(map, map->x, map->y);
	if (map->nexit < 1 || map->nexit > 1 || map->ncoins != game.coins)
		ft_exit("Error\n", 1);
	return (1);
}

void	print_map(t_game *g, t_map *map)
{
	int		y;
	int		x;
	char	type;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			type = map->grid[y][x];
			print_cell(g, x, y, type);
			x++;
		}
		y++;
	}
}

void	count_coins(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'C')
				game->coins++;
			j++;
		}
		i++;
	}
}
