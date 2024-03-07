/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:48:23 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/07 11:48:25 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

void verify_walls(Map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < map->width)
	{
		if (map->grid[0][j] != '1' || map->grid[map->height - 1][j] != '1')
		{
			// printf("Error: El borde debe ser '1'. Encontrado en borde superior/inferior en columna
			// 	%d.\n", j);
			exit(1);
		}
		j++;
	}
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
		{
			// printf("Error: El borde debe ser '1'. Encontrado en borde izquierdo/derecho en fila
			// 	%d.\n", i);
			// printf("Carácter en borde superior derecho: '%c'\n",
			// 	map->grid[0][map->width - 2]);
			exit(1);
		}
		i++;
	}
}

void ft_exit(char *str, int ex)
{
	int len;

	len = ft_strlen(str);
	if (len > 0)
		write(1, &str, len);
	exit(ex);
}
