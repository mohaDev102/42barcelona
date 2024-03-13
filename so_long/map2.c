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

int	add_to_map(Map *map, char *line)
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

int	initialize_map(Map *map)
{
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->nexit = 0;
	map->ncoins = 0;
	return (1);
}

void	free_map(Map *map)
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
