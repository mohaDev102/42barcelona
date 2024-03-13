#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct validMap {
    char** grid;
    int height;
    int width;
} Map;

int addToMap(Map *map, char *line) 
{
    int lineLength = ft_strlen(line);
    printf("val line: %d\n", lineLength);
    if (map->height == 0)
        map->width = lineLength;
    // else if (lineLength != map->width)
    // {
    //     printf("Error:\n las líneas del mapa no tienen la misma longitud.\n");
    //     return 0;
    // }
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

int initializeMap(Map* map) 
{
    map->grid = NULL;
    map->height = 0;
    map->width = 0;
    return 1;
}

void freeMap(Map* map)
{
    for (int i = 0; i < map->height; i++)
    {
        free(map->grid[i]);
    }
    free(map->grid);
}

void floodFill(Map* map, int x, int y, int* accessibleCoins, int* exitFound)
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

int validateMap(Map* map)
{
    int playerX = -1, playerY = -1;
    int exitCount = 0, playerCount = 0, coinCount = 0, accessibleCoins = 0, exitFound = 0;
    int i = 0, j = 0;
// printf("Carácter en borde superior izquierdo: '%c'\n", map->grid[0][0]);
// printf("Carácter en borde superior derecho: '%c'\n", map->grid[0][map->width - 2]);
    printf("%d", map->width);
    for (int j = 0; (j < map->width - 2); j++) {
        if (map->grid[0][j] != '1' || map->grid[map->height - 1][j] != '1') {
            printf("Error: El borde debe ser '1'. Encontrado en borde superior/inferior en columna %d.\n", j);
            return 0; // Mapa no válido
        }
    }
    for (int i = 0; i < map->height; i++) {
        if (map->grid[i][0] != '1' || map->grid[i][map->width - 2] != '1') {
            printf("Error: El borde debe ser '1'. Encontrado en borde izquierdo/derecho en fila %d.\n", i);
            printf("Carácter en borde superior derecho: '%c'\n", map->grid[0][map->width - 2]);
            return 0; // Mapa no válido
        }
    }
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; (j < map->width - 2); j++)
        {
        printf("%c", map->grid[i][j]);
        }
        printf("\n");
    }
    while (i < map->height)
    {
        j = 0;
        while (j < (map->width - 2)) 
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
        printf("eerror");
        printf("E: %d P: %d C: %d", exitCount, playerCount, coinCount);
        exit(1);
        return 0;
    }
    floodFill(map, playerX, playerY, &accessibleCoins, &exitFound);
    if (!exitFound || accessibleCoins != coinCount) return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int fd;
        char *line;
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            printf("Error\n");
            exit(1);
        }
        Map map;
        if (!initializeMap(&map))
        {
             printf("Error inicializando el mapa.\n");
            return 1;
        }
        while ((line = get_next_line(fd)) != NULL)
        {
            if (!addToMap(&map, line))
            {
                printf("Error al añadir línea al mapa.\n");
                free(line);
                freeMap(&map);
                return 1;
            }
            free(line);
        }
        if (validateMap(&map))
            init_game(&map);
        else
            printf("El mapa no es valido");
    }
    else
        printf("Error\n");
}