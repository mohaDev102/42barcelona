#include "so_long.h"

Map	*copy_map(Map *original)
{
	Map *copy;
	int i;

	copy = malloc(sizeof(Map));
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

void    initialize_copy(Map *copy, Map *original)
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

void ft_put_img(t_flood *g, int win_height, int win_width)
{
	int height;
	int width;

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

void init_param(t_flood *g)
{
	g->player_x = 0;
	g->player_y = 0;
	g->ncollect = 0;
	g->coins = 0;
	g->nplayer = 0;
	g->moves = 0;
}