/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:48:05 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/07 11:48:06 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

Map	*check_param(int argc, char *argv[], Map *map)
{
	int	fd;

	if (argc != 2)
		error_param("Incorrect parameters", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_param("Error in file", NULL);
	if (ft_conteins_ber(argv[1]) || !ft_strcmp(argv[1], ".ber"))
		error_param("File format not correct", NULL);
	return (check_map(fd, map));
}

//  28 lineas
Map	*copy_map(Map *original)
{
	Map	*copy;
	int	i;

	copy = malloc(sizeof(Map));
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

Map	*check_map(int fd, Map *map)
{
	char	*line;
	Map		*map_valid;

	if (!initialize_map(map))
		ft_exit("Error inicializando el mapa.", 1);
	while ((line = get_next_line(fd)) != NULL)
	// while (1)
	{
		// line = get_next_line(fd);
		// if (!line)
		//    {
		//     // free(map);
		//     write(1, "11", 2);
		//     // return (NULL);
		//     exit(1);
		//    }
		if (!add_to_map(map, line))
		{
			ft_exit("Error al añadir línea al mapa.", 1);
			free(line);
			free_map(map);
		}
		free(line);
	}
	map_valid = copy_map(map);
	if (validate_map(map))
		return (map_valid);
	return (NULL);
}

int	key_press(int key, GameMap *gameMap)
{
	t_flood	*game;
	Map		*map;
	char	c;

	game = gameMap->game;
	map = gameMap->map;
	if (game->player_x == 0 || game->player_y == 0)
		get_player_position(game, map);
	c = map->grid[game->player_y][game->player_x];
	if (c == 'C' && game->ncollect < game->coins)
	{
		map->grid[game->player_y][game->player_x] = '0';
		game->ncollect++;
		write(1, "Collected ", 10);
		put_nbr(game->ncollect);
		write(1, " coins\n", 7);
	}
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(1);
	}
	else if (key == 13)
	{
		if (is_valid_move(map, game, game->player_x, game->player_y - 1))
		{
			move_player(map, game, game->player_x, game->player_y - 1);
		}
	}
	else if (key == 0)
	{
		if (is_valid_move(map, game, game->player_x - 1, game->player_y))
			move_player(map, game, game->player_x - 1, game->player_y);
	}
	else if (key == 1)
	{
		if (is_valid_move(map, game, game->player_x, game->player_y + 1))
			move_player(map, game, game->player_x, game->player_y + 1);
	}
	else if (key == 2)
	{
		if (is_valid_move(map, game, game->player_x + 1, game->player_y))
			move_player(map, game, game->player_x + 1, game->player_y);
	}
	if (exit_game(map, game->player_x, game->player_y) && game->coins == game->ncollect)
		ft_exit("Has ganado", 0);
	put_nbr(game->moves);
	write(1, "\n", 1);
	return (0);
}

// t_img *create_buffer(t_flood *g, t_img *buffer, int width, int height)
// {

// 	buffer = mlx_new_image(g->mlx, width, height);
// 	buffer->addr = mlx_get_data_addr(buffer->img, &bits_per_pixel,
// 		&line_length, &endian);
// 	return (buffer);
// }

void	init_game(Map *map, t_flood *g)
{
	int		height;
	int		width;
	int		win_width;
	int		win_height;
	GameMap	gm;

	g->mlx = mlx_init();
	if (g->mlx == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	height = 40;
	width = 40;
	win_width = map->width * CELL_SIZE;
	win_height = map->height * CELL_SIZE;
	if (win_height >= 720 || win_width >= 1920)
	{
		write(1, "Mapa demasiado grande\n", 22);
		exit(1);
	}
	g->win = mlx_new_window(g->mlx, win_width, win_height, "so_long");
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "floor.xpm", &width, &height);
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "wall.xpm", &width, &height);
	g->img_coin = mlx_xpm_file_to_image(g->mlx, "coin.xpm", &width, &height);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "player.xpm", &width,
			&height);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "exit.xpm", &width, &height);
	g->player_x = 0;
	g->player_y = 0;
	g->ncollect = 0;
	g->coins = 0;
	g->nplayer = 0;
	g->moves = 0;
	count_coins(g, map);
	if (g->img_floor == NULL || g->img_wall == NULL || g->img_coin == NULL
		|| g->img_player == NULL || g->img_exit == NULL)
	{
		perror("Error al cargar imágenes");
		exit(EXIT_FAILURE);
	}
	print_map(g, map);
	gm.game = g;
	gm.map = map;
	mlx_hook(g->win, 2, 0, key_press, &gm);
	mlx_loop(g->mlx);
}
