/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/16 02:59:30 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/16 02:59:32 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*copy_map(t_map *original)
{
	t_map	*copy;
	int		i;

	copy = malloc(sizeof(t_map));
	initialize_copy(copy, original);
	i = 0;
	while (i < copy->height)
	{
		copy->grid[i] = malloc(sizeof(char) * (copy->width + 1));
		if (copy->grid[i] == NULL)
		{
			free(copy->grid);
			free(copy);
			exit(1);
		}
		ft_strcpy(copy->grid[i], original->grid[i]);
		i++;
	}
	return (copy);
}

void	initialize_copy(t_map *copy, t_map *original)
{
	if (copy == NULL)
		exit(1);
	copy->width = original->width;
	copy->height = original->height;
	copy->grid = malloc(sizeof(char *) * copy->height);
	if (copy->grid == NULL)
	{
		free(copy);
		exit(1);
	}
}

void	ft_put_img(t_game *g, int win_height, int win_width)
{
	int	height;
	int	width;

	height = 40;
	width = 40;
	g->win = mlx_new_window(g->mlx, win_width, win_height, "so_long");
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "floor.xpm", &width, &height);
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "wall.xpm", &width, &height);
	g->img_coin = mlx_xpm_file_to_image(g->mlx, "coin.xpm", &width, &height);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "player.xpm", &width,
			&height);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "exit.xpm", &width, &height);
}

void	init_param(t_game *g)
{
	g->player_x = 0;
	g->player_y = 0;
	g->ncollect = 0;
	g->coins = 0;
	g->nplayer = 0;
	g->moves = 0;
}
