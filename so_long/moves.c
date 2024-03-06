
#include <unistd.h>
#include "so_long.h"

int isValidMove(Map *map, int x, int y)
{
    if (x < 0 || y < 0 || x >= map->width || y >= map->height)
        return 0;
    return (map->grid[y][x] == '0' || map->grid[y][x] == 'C' || map->grid[y][x] == 'P');
}

void put_nbr(int num)
{
    char res;
    if (num > 9)
        put_nbr(num / 10);
    res = num % 10 + '0';
    write(1, &res, 1);
}