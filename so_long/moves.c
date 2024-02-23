
#include <unistd.h>
#include "so_long.h"

int isValidMove(Map *map, int x, int y)
{
    // Verifica si las coordenadas están dentro de los límites del mapa
    // printf("valor x: %d", x);
    // printf("valor y: %d", y);
    // printf("%d", map->height);
    // printf("%d\n", x);
    // printf("%d\n", y);
    // printf("%c", map->grid[2][1]);
    write(1, "11", 2);
    x = 2;
    y = 1;
    (void) x;
    (void) y;
    (void) map;
    // return 0;
    // printf("%d\n", y);
    char cell = map->grid[y][x];
    printf("Contenido de la celda: %c\n", cell);
    if (x < 0 || y < 0 || x >= map->width || y >= map->height)
        return 0;
    printf("puede moverse???");
    // Verifica si la posición contiene un camino ('0') o una moneda ('C')
    return (map->grid[y][x] == '0' || map->grid[y][x] == 'C');
    // return 1;
}

// void move_w(t_flood *game, Map *map)
// {
//     int x = 0;
//     int y = 0;

//     while (y < map->height)
//     {
//         x = 0;
//         while (x < map->width)
//         {
//             if (map->grid[y][x] == 'P')
//             {
//                 game->player_x = x;
//                 game->player_y = y;
//             }
//             x++;
//         }
//         y++;
//     }


//     // int x = game->player_x;
//     // int x = 0;
//     // int y = 0; 
//     // int y = game->player_y - 1;
//     // printf("%d", map->height);
//     //printf("%d", 11);
//     // Verifica si el movimiento hacia arriba es válido
//     if (isValidMove(map, game->player_x, game->player_y))
//     {
//         // Actualiza la posición del jugador
//         printf("mover jugador");
//         game->player_y--;
//         printMap(game, map);
//         // También puedes realizar otras acciones aquí, como actualizar contadores, etc.
//     }
// }
void move_w(t_flood *game, Map *map)
{
    int x = game->player_x;
    int y = game->player_y - 1;

    // Verifica si el movimiento hacia arriba es válido
    if (isValidMove(map, x, y))
    {
        // Actualiza la posición del jugador
        map->grid[game->player_y][game->player_x] = '0';
        game->player_y--;
        map->grid[game->player_y][game->player_x] = 'P';
        // Actualiza las coordenadas del jugador en la estructura t_flood
        game->player_x = x;
        game->player_y = y;
        printMap(game, map);
    }
}