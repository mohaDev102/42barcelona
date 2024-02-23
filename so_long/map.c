
#include "so_long.h"

void floodFill(Map *map, int x, int y, int* accessibleCoins, int* exitFound)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height || map->grid[y][x] == '1' || map->grid[y][x] == 'F') return;
    if (map->grid[y][x] == 'C') (*accessibleCoins)++;
    if (map->grid[y][x] == 'E') *exitFound = 1;
    // if (map->grid[y][x] != '0') return ;
    map->grid[y][x] = 'F';
    floodFill(map, x + 1, y, accessibleCoins, exitFound);
    floodFill(map, x - 1, y, accessibleCoins, exitFound);
    floodFill(map, x, y + 1, accessibleCoins, exitFound);
    floodFill(map, x, y - 1, accessibleCoins, exitFound);
}

int validateMap(Map *map)
{
    // write(1, "qq", 2);
    int playerX = -1, playerY = -1;
    int exitCount = 0, playerCount = 0, coinCount = 0, accessibleCoins = 0, exitFound = 0;
    int i = 0, j = 0;
    //printf("%c", map->grid[0][0]);
    for (int j = 0; (j < map->width); j++) {
        if (map->grid[0][j] != '1' || map->grid[map->height - 1][j] != '1') {
            printf("Error: El borde debe ser '1'. Encontrado en borde superior/inferior en columna %d.\n", j);
            return 0; // Mapa no válido
        }
    }
    for (int i = 0; i < map->height; i++) {
        if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1') {
            printf("Error: El borde debe ser '1'. Encontrado en borde izquierdo/derecho en fila %d.\n", i);
            printf("Carácter en borde superior derecho: '%c'\n", map->grid[0][map->width - 2]);
            return 0; // Mapa no válido
        }
    }
    // for (int i = 0; i < map->height; i++)
    // {
    //     for (int j = 0; (j < map->width); j++)
    //     {
    //     printf("%c", map->grid[i][j]);
    //     }
    //     printf("\n");
    // }
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
            }
            j++;
        }
        i++;
    }
    if (exitCount != 1 || playerCount != 1 || coinCount == 0)
    {
        printf("error");
        printf("E: %d P: %d C: %d", exitCount, playerCount, coinCount);
        exit(1);
        return 0;
    }
    floodFill(map, playerX, playerY, &accessibleCoins, &exitFound);
    if (!exitFound || accessibleCoins != coinCount) return 0;
    return 1;
}

void movePlayer(t_flood *game, int new_x, int new_y)
{
    // Borra la imagen del jugador en la posición actual
    write(1, "falla", 5);
    printf("%d", new_x);
    printf("%d", new_y);
    if (game == NULL)
    {
        printf("no hay imagen ????");
        write(1, "no hay img1", 11);
    }
    erasePlayer(game, new_x, new_y);
    write(1, "qqqqq", 5);
    // Actualiza la posición del jugador
    game->player_x = new_x;
    game->player_y = new_y;
    write(1, "pasas", 5);
    // Dibuja la imagen del jugador en la nueva posición
    drawPlayer(game);
    write(1, "iiiii", 5);
}

void erasePlayer(t_flood *game, int x, int y)
{
    // int startX = 1;
    // int startY = 3;
    // (void) game;
    // (void) x;
    // (void) y;
    // if (game->win == NULL)
    // {
    //     printf("no hay imagen ????");
    //     write(1, "no hay img", 10);
    // }
    printf("dedwq");
    printf("valor x: %d", x);
    printf("valor y: %d", y);
    printf("%s", game->mlx);
    printf("%s", game->win);
    printf("%s", game->img_floor);
    // Borra la imagen del jugador en la posición actual
   mlx_put_image_to_window(game->mlx, game->win, game->img_floor, y, x);
}

void drawPlayer(t_flood *game)
{
    int startX = game->player_x;
    int startY = game->player_y;
    printf("%d", startX);
    printf("%d", startY);
    // Dibuja la imagen del jugador en la nueva posición
    mlx_put_image_to_window(game->mlx, game->win, game->img_player, startX, startY);
}

void printCell(t_flood *g, int x, int y, char type)
{
    int startX = x * CELL_SIZE;
    int startY = y * CELL_SIZE;

    if (type == '0') // Camino
        mlx_put_image_to_window(g->mlx, g->win, g->img_floor, startX, startY);
    else if (type == '1') // Pared
        mlx_put_image_to_window(g->mlx, g->win, g->img_wall, startX, startY);
    else if (type == 'P') // Posición inicial
        mlx_put_image_to_window(g->mlx, g->win, g->img_player, startX, startY);
    else if (type == 'E') // Salida
        mlx_put_image_to_window(g->mlx, g->win, g->img_exit, startX, startY);
    else if (type == 'C') // Moneda
        mlx_put_image_to_window(g->mlx, g->win, g->img_coin, startX, startY);
}

void printMap(t_flood *g, Map *map)
{
    int y = 0;
    int x = 0;
    char type;
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