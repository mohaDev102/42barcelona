
#include "so_long.h"

void floodFill(Map *map, int x, int y, int* accessibleCoins, int* exitFound)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height || map->grid[y][x] == '1' || map->grid[y][x] == 'F') return;
    if (map->grid[y][x] == 'C') (*accessibleCoins)++;
    if (map->grid[y][x] == 'E') *exitFound = 1;
    map->grid[y][x] = 'F';
    floodFill(map, x + 1, y, accessibleCoins, exitFound);
    floodFill(map, x - 1, y, accessibleCoins, exitFound);
    floodFill(map, x, y + 1, accessibleCoins, exitFound);
    floodFill(map, x, y - 1, accessibleCoins, exitFound);
}

int exitGame(Map *map, int x, int y) 
{
    return (map->grid[y - 1][x] == 'E' ||     
            map->grid[y + 1][x] == 'E' ||     
            map->grid[y][x - 1] == 'E' ||     
            map->grid[y][x + 1] == 'E');
}

int validateMap(Map *map)
{
    int playerX = -1, playerY = -1;
    int exitCount = 0, playerCount = 0, coinCount = 0, accessibleCoins = 0, exitFound = 0;
    int i = 0, j = 0;
    for (int j = 0; (j < map->width); j++)
    {
        if (map->grid[0][j] != '1' || map->grid[map->height - 1][j] != '1') 
        {
            printf("Error: El borde debe ser '1'. Encontrado en borde superior/inferior en columna %d.\n", j);
            exit(1);
            return 0;
        }
    }
    for (int i = 0; i < map->height; i++)
    {
        if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1') 
        {
            printf("Error: El borde debe ser '1'. Encontrado en borde izquierdo/derecho en fila %d.\n", i);
            printf("Carácter en borde superior derecho: '%c'\n", map->grid[0][map->width - 2]);
            exit(1);
            return 0;
        }
    }
    while (i < map->height)
    {
        j = 0;
        while (j < (map->width))
        {
            char c = map->grid[i][j];
            if (c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C')
            {
                if (c == 'P')
                {
                    playerCount++;
                    playerX = j;
                    playerY = i; 
                }
                else if (c == 'E')
                    exitCount++;
                else if (c == 'C')
                    coinCount++;
            }
            else
            {
                printf("Carácter no reconocido: '%c' en la posición [%d, %d].\n", c, i, j);
                exit(1);
            }
            j++;
        }
        i++;
    }
    t_flood game;
    game.ncollect = coinCount;
    if (exitCount != 1 || playerCount != 1 || coinCount == 0)
    {
        write(1, "error", 6);
        //printf("E: %d P: %d C: %d", exitCount, playerCount, coinCount);
        exit(1);
        return 0;
    }
    floodFill(map, playerX, playerY, &accessibleCoins, &exitFound);
    if (!exitFound || accessibleCoins != coinCount)
    {
        write(1, "Error\n", 7);
        exit(1);
        return 0;
    }
    return 1;
}

void movePlayer(Map *map, t_flood *game, int new_x, int new_y)
{
    game->x = game->player_x;
    game->y = game->player_y;
    game->player_x = new_x;
    game->player_y = new_y;
    game->moves++;
    erasePlayer(game, game->x, game->y);
    drawPlayer(game);
    if (exitGame(map, game->player_x, game->player_y) && game->coins == game->ncollect )
    {
        write(1, "Has ganado!!!", 13);
        exit(0);
    }
}

void erasePlayer(t_flood *game, int x, int y)
{
    int startX = x * CELL_SIZE;
    int startY = y * CELL_SIZE;

    mlx_put_image_to_window(game->mlx, game->win, game->img_floor, startX, startY);
}

void drawPlayer(t_flood *game)
{
    int startX = game->player_x * CELL_SIZE;
    int startY = game->player_y * CELL_SIZE;

    mlx_put_image_to_window(game->mlx, game->win, game->img_player, startX, startY);
}

void printCell(t_flood *g, int x, int y, char type)
{
    int startX;
    int startY;

    startX = x * CELL_SIZE;
    startY = y * CELL_SIZE;

    if (type == '0')
        mlx_put_image_to_window(g->mlx, g->win, g->img_floor, startX, startY);
    else if (type == '1')
        mlx_put_image_to_window(g->mlx, g->win, g->img_wall, startX, startY);
    else if (type == 'P')
        mlx_put_image_to_window(g->mlx, g->win, g->img_player, startX, startY);
    else if (type == 'E')
        mlx_put_image_to_window(g->mlx, g->win, g->img_exit, startX, startY);
    else if (type == 'C')
        mlx_put_image_to_window(g->mlx, g->win, g->img_coin, startX, startY);
}

void printMap(t_flood *g, Map *map)
{
    int y;
    int x;
    char type;

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

void count_coins(t_flood *game, Map *map)
{
    int i;
    int j;

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