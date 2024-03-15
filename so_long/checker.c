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

// Map	*check_map(int fd, Map *map)
// {
// 	char	*line;
// 	// char *line_map;
// 	Map		*map_valid;
// 	// size_t len;
// 	// int len_map;

// 	if (!initialize_map(map))
// 		ft_exit("Error inicializando el mapa.", 1);
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// line_map = get_next_line(fd);
// 	// len = ft_strlen(line_map);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		// len_map = ft_strlen(line);
// 		if (!line)
// 			break ;
// 		// if (len != ft_strlen(line))
// 		// {
// 		// 	ft_exit("Mapa no rectangular", 1);
// 		// 	free(line);
// 		// 	free_map(map);
// 		// }
// 		if (!add_to_map(map, line))
// 		{
// 			ft_exit("Error al añadir línea al mapa", 1);
// 			free(line);
// 			free_map(map);
// 		}
// 		free(line);
// 	}
// 	// free(line_map);
// 	map_valid = copy_map(map);
// 	if (validate_map(map))
// 		return (map_valid);
// 	return (NULL);
// }
Map	*check_map(int fd, Map *map)
{
	char	*line;
	size_t	first_map_width;
	Map		*map_valid;

	if (!initialize_map(map))
		ft_exit("Error inicializando el mapa.", 1);
	first_map_width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_map_rectangularity(map, &first_map_width, line);
		add_line_to_map(map, line);
	}
	map_valid = copy_map(map);
	if (validate_map(map))
		return (map_valid);
	return (NULL);
}

int	key_press(int key, game_map *gameMap)
{
	t_flood	*game;
	Map		*map;

	game = gameMap->game;
	map = gameMap->map;
	if (game->player_x == 0 || game->player_y == 0)
		get_player_position(game, map);
	collected_coins(game, map);
	handler_movement(key, game, map);
	if (exit_game(map, game->player_x, game->player_y)
		&& game->coins == game->ncollect)
		ft_exit("Has ganado", 0);
	put_nbr(game->moves);
	write(1, "\n", 1);
	return (0);
}
// 50 lineas
// int	key_press(int key, GameMap *gameMap)
// {
// 	t_flood	*game;
// 	Map		*map;
// 	char	c;

// 	game = gameMap->game;
// 	map = gameMap->map;
// 	if (game->player_x == 0 || game->player_y == 0)
// 		get_player_position(game, map);
// 	c = map->grid[game->player_y][game->player_x];
// 	if (c == 'C' && game->ncollect < game->coins)
// 	{
// 		map->grid[game->player_y][game->player_x] = '0';
// 		game->ncollect++;
// 		write(1, "Collected ", 10);
// 		put_nbr(game->ncollect);
// 		write(1, " coins\n", 7);
// 	}
// 	if (key == 53)
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(1);
// 	}
// 	else if (key == 13)
// 	{
// 		if (is_valid_move(map, game, game->player_x, game->player_y - 1))
// 			move_player(map, game, game->player_x, game->player_y - 1);
// 	}
// 	else if (key == 0)
// 	{
// 		if (is_valid_move(map, game, game->player_x - 1, game->player_y))
// 			move_player(map, game, game->player_x - 1, game->player_y);
// 	}
// 	else if (key == 1)
// 	{
// 		if (is_valid_move(map, game, game->player_x, game->player_y + 1))
// 			move_player(map, game, game->player_x, game->player_y + 1);
// 	}
// 	else if (key == 2)
// 	{
// 		if (is_valid_move(map, game, game->player_x + 1, game->player_y))
// 			move_player(map, game, game->player_x + 1, game->player_y);
// 	}
// 	if (exit_game(map, game->player_x, game->player_y)
// 		&& game->coins == game->ncollect)
// 		ft_exit("Has ganado", 0);
// 	put_nbr(game->moves);
// 	write(1, "\n", 1);
// 	return (0);
// }

void	init_game(Map *map, t_flood *g)
{
	int			win_width;
	int			win_height;
	game_map	gm;

	g->mlx = mlx_init();
	if (g->mlx == NULL)
		ft_exit("Error", 1);
	win_width = map->width * CELL_SIZE;
	win_height = map->height * CELL_SIZE;
	if (win_height >= 720 || win_width >= 1920)
		ft_exit("Mapa demasiado grande\n", 1);
	ft_put_img(g, win_height, win_width);
	init_param(g);
	count_coins(g, map);
	if (g->img_floor == NULL || g->img_wall == NULL || g->img_coin == NULL
		|| g->img_player == NULL || g->img_exit == NULL)
		ft_exit("Error al cargar imágenes", 1);
	print_map(g, map);
	gm.game = g;
	gm.map = map;
	mlx_hook(g->win, 2, 0, key_press, &gm);
	mlx_loop(g->mlx);
}
