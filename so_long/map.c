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

void	floodFill(Map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height
		|| map->grid[y][x] == '1' || map->grid[y][x] == 'F')
		return ;
	if (map->grid[y][x] == 'C')
		map->ncoins++;
	if (map->grid[y][x] == 'E')
		map->nexit = 1;
	map->grid[y][x] = 'F';
	floodFill(map, x + 1, y);
	floodFill(map, x - 1, y);
	floodFill(map, x, y + 1);
	floodFill(map, x, y - 1);
}

int	exitGame(Map *map, int x, int y)
{
	return (map->grid[y - 1][x] == 'E' || map->grid[y + 1][x] == 'E'
		|| map->grid[y][x - 1] == 'E' || map->grid[y][x + 1] == 'E');
}

int	validateMap(Map *map)
{
	int		player_count;
	int		coin_count;
	int		i;
	int		j;
	t_flood	game;

	player_count = 0;
	coin_count = 0;
	i = -1;
	verify_walls(map);
	while (++i < map->height)
	{
		j = -1;
		while (++j < (map->width))
		{
			if (map->grid[i][j] == '1' || map->grid[i][j] == '0' || 
			map->grid[i][j] == 'E' || map->grid[i][j] == 'P' || 
			map->grid[i][j] == 'C')
			{
				if (map->grid[i][j] == 'P')
				{
					player_count++;
					map->x = j;
					map->y = i;
				}
				else if (map->grid[i][j] == 'E')
					map->nexit++;
				else if (map->grid[i][j] == 'C')
					coin_count++;
			}
			else
				ft_exit("caracter invalido", 1);
		}
	}
	game.ncollect = coin_count;
	if (map->nexit != 1 || player_count != 1 || coin_count == 0)
		ft_exit("Error\n", 1);
	floodFill(map, map->x, map->y);
	if (map->nexit < 1 || map->nexit > 1 || map->ncoins != coin_count)
		ft_exit("Error\n", 1);
	return (1);
}

void	printMap(t_flood *g, Map *map)
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
			printCell(g, x, y, type);
			x++;
		}
		y++;
	}
}

void	count_coins(t_flood *game, Map *map)
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