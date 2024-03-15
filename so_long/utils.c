
#include "so_long.h"

void collected_coins(t_flood *game, Map *map)
{
    char c;

	c = map->grid[game->player_y][game->player_x];
    if (c == 'C' && game->ncollect < game->coins)
	{
		map->grid[game->player_y][game->player_x] = '0';
		game->ncollect++;
		write(1, "Collected ", 10);
		put_nbr(game->ncollect);
		write(1, " coins\n", 7);
	}
}

void handler_movement(int key, t_flood *game, Map *map)
{
    if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(1);
	}
	else if (key == 13)
	{
		if (is_valid_move(map, game, game->player_x, game->player_y - 1))
			move_player(game, game->player_x, game->player_y - 1);
	}
	else if (key == 0)
	{
		if (is_valid_move(map, game, game->player_x - 1, game->player_y))
			move_player(game, game->player_x - 1, game->player_y);
	}
	else if (key == 1)
	{
		if (is_valid_move(map, game, game->player_x, game->player_y + 1))
			move_player(game, game->player_x, game->player_y + 1);
	}
	else if (key == 2)
	{
		if (is_valid_move(map, game, game->player_x + 1, game->player_y))
			move_player(game, game->player_x + 1, game->player_y);
	}
}

int	ft_conteins_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i] || ft_strcmp(&str[i], ".ber") != 0)
		return (1);
	return (0);
}
