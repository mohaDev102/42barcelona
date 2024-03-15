#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_flood	g;
	Map		map;
	Map		*map_pars;

	map_pars = check_param(argc, argv, &map);
	init_game(map_pars, &g);
	return (0);
}
