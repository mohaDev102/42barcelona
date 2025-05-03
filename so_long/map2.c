/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:18:10 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/11 14:18:12 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_to_map(t_map *map, char *line)
{
	int		line_length;
	char	**new_grid;

	line_length = ft_strlen(line);
	if (map->height == 0)
		map->width = line_length;
	new_grid = realloc(map->grid, (map->height + 1) * sizeof(char *));
	if (new_grid == NULL)
		return (0);
	map->grid = new_grid;
	map->grid[map->height] = malloc(ft_strlen(line) + 1);
	if (map->grid[map->height] == NULL)
		return (0);
	ft_strcpy(map->grid[map->height], line);
	map->height++;
	return (1);
}

int	initialize_map(t_map *map)
{
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->nexit = 0;
	map->ncoins = 0;
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	check_map_rectan(t_map *map, size_t *first_map_width, char *line)
{
	if (*first_map_width == 0)
		*first_map_width = ft_strlen(line);
	else if (ft_strlen(line) != *first_map_width)
	{
		ft_exit("Mapa no rectangular", 1);
		free(line);
		free_map(map);
	}
}

void	add_line_to_map(t_map *map, char *line)
{
	if (!add_to_map(map, line))
	{
		ft_exit("Error al añadir línea al mapa", 1);
		free(line);
		free_map(map);
	}
	free(line);
}
