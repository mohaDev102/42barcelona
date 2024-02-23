
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

Map    *check_param(int argc, char *argv[], Map *map)
{
    int fd;
	//printf("%d", argc);
    if (argc != 2)
	{
        error_param("Incorrect parameters", NULL);
		//printf("error\n");
	}
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        error_param("Error in file", NULL);
    if (ft_conteins_ber(argv[1]) || !ft_strcmp(argv[1], ".ber"))
	{
        error_param("File format not correct", NULL);
	}
    return (check_map(fd, map));
}

int addToMap(Map *map, char *line) 
{
    int lineLength = ft_strlen(line);
    if (map->height == 0)
        map->width = lineLength;
    char **newGrid = realloc(map->grid, (map->height + 1) * sizeof(char *));
    if (newGrid == NULL) 
        return 0;
    map->grid = newGrid;
    map->grid[map->height] = malloc(strlen(line) + 1);
    if (map->grid[map->height] == NULL)
        return 0;
    strcpy(map->grid[map->height], line);
    map->height++;
    return 1;
}

int initializeMap(Map *map) 
{
    map->grid = NULL;
    map->height = 0;
    map->width = 0;
    return 1;
}

void freeMap(Map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        free(map->grid[i]);
    }
    free(map->grid);
}

Map* copyMap(Map* original)
{
    Map* copy = malloc(sizeof(Map));
    if (copy == NULL) 
    {
        // Manejo de error: no se pudo asignar memoria para la copia
        exit(EXIT_FAILURE);
    }
    // Copiar la anchura y la altura del mapa original
    copy->width = original->width;
    copy->height = original->height;

    // Asignar memoria para la cuadrícula de la copia
    copy->grid = malloc(sizeof(char*) * copy->height);
    if (copy->grid == NULL) {
        // Manejo de error: no se pudo asignar memoria para la cuadrícula
        free(copy); // Liberar memoria asignada para la copia
        exit(EXIT_FAILURE);
    }

    // Copiar cada fila del mapa original a la copia
    int i = 0;
    while (i < copy->height) {
        copy->grid[i] = malloc(sizeof(char) * (copy->width + 1)); // +1 para el carácter nulo
        if (copy->grid[i] == NULL) {
            // Manejo de error: no se pudo asignar memoria para la fila de la copia
            free(copy->grid); // Liberar memoria asignada para las filas de la copia
            free(copy); // Liberar memoria asignada para la copia
            exit(EXIT_FAILURE);
        }
        strcpy(copy->grid[i], original->grid[i]); // Copiar la fila del mapa original a la copia
        i++;
    }

    return copy;
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

Map    *check_map(int fd, Map *map)
{
	char *line;
    Map *map_valid;

	if (!initializeMap(map))
	{
		printf("Error inicializando el mapa.\n");
	}
	while ((line = get_next_line(fd)) != NULL)
	{
        if (!addToMap(map, line))
		{
			printf("Error al añadir línea al mapa.\n");
			free(line);
			freeMap(map);
		}
        free(line);
	}
    map_valid = copyMap(map);
	if (validateMap(map))
		return (map_valid);
    return (NULL);
}

int key_press(int key, GameMap *gameMap)
{

	t_flood *game = gameMap->game;
    Map *map = gameMap->map;
    //printf("%d", map->height);
    //printf("%d", map->height);
    // printf("%c", map->grid[3][1]);
	if (key == 53)
		exit(1);
	else if (key == 13)
	{
        if (isValidMove(map, game->player_x, game->player_y - 1))
        {
            write(1, "\nmover\n", 7);
            movePlayer(game, game->player_x, game->player_y - 1);
        }
        else
        {
            printf("no moverse");
            write(1, "qqq", 3);
        }
    }
	else if (key == 0)
		game->player_x--;
	else if (key == 1)
		game->player_y--;
	else if (key == 28)
		game->player_x++;
    //printMap(&game, &map);
	return (0);
}

void init_game(Map *map, t_flood *g)
{
	// inicializar
	g->mlx = mlx_init();
	if (g->mlx == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
    int height = 40;
    int width = 40;

    // int x = 1200;
    // int y = 800;
	int win_width = map->width * CELL_SIZE;
    int win_height = map->height * CELL_SIZE;
    g->win = mlx_new_window(g->mlx, win_width, win_height, "so_long");
    g->img_floor = mlx_xpm_file_to_image(g->mlx, "floor.xpm", &width, &height);
    g->img_wall = mlx_xpm_file_to_image(g->mlx, "wall.xpm", &width, &height);
    g->img_coin = mlx_xpm_file_to_image(g->mlx, "coin.xpm", &width, &height);
    g->img_player = mlx_xpm_file_to_image(g->mlx, "player.xpm", &width, &height);
    g->img_exit = mlx_xpm_file_to_image(g->mlx, "exit.xpm", &width, &height);

    if (g->img_floor == NULL || g->img_wall == NULL || g->img_coin == NULL || g->img_player == NULL || g->img_exit == NULL)
    {
        perror("Error al cargar imágenes");
        exit(EXIT_FAILURE);
    }
    printMap(g, map);
    // printf("%c", map->grid[0][0]);
    GameMap gm = {g, map};
    mlx_key_hook(g->win, key_press, &gm);
    mlx_loop(g->mlx);
}