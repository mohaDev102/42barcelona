
#include "so_long.h"

t_flood ft_newmap()
{
    t_flood game;

    game.nrow = 0;
    game.ncol = 0;
    game.ncollect = 0;
    game.nexits = 0;
    game.nwalls = 0;
    return (game);
}

char    **check_param(int argc, char *argv[], t_flood *g)
{
    int fd;
	//printf("%d", argc);
    if (argc != 2)
	{
        error_param("Incorrect parameters", NULL);
		//printf("error\n");
	}
    fd = open(argv[1], O_WRONLY);
    if (fd == -1)
        error_param("Error in file", NULL);
    if (ft_conteins_ber(argv[1]) || !ft_strcmp(argv[1], ".ber"))
	{
        error_param("File format not correct", NULL);
	}
    return (check_map(fd, g));
}

int ft_conteins_ber(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '.')
        i++;
    if (!str[i] || ft_strcmp(&str[i], ".ber") != 0)
        return (1);
    return (0);
}

char    **check_map(int fd, t_flood *g)
{
	char *map_str;
	char **map;
	t_err map_err;

	map_str = NULL;
	map = NULL;
	map_err = ft_newmap_error();
	*g = ft_newmap();
	ft_read_map(fd, &map_err, g, &map_str);
	ft_print_map_error(&map_err, &map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		error_param("Memory Error", NULL);
    return (map);
}

void init_game(char **map, t_flood *g)
{
	// inicializar
	(void) **map;
	g->mlx = mlx_init();
	if (g->mlx == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	int width = 80;
    int height = 60;
	g->win = mlx_new_window(g->mlx, 800, 600, "so_long");
	//game->img = mlx_new_image(game->mlx, 800, 600);
	g->img = mlx_xpm_file_to_image(g->mlx, "mario_bros.xpm", &width, &height);
	mlx_put_image_to_window(g->mlx, g->win, g->img, g->player_x,g->player_y);
	// funcion para cargar el mapa
		
}