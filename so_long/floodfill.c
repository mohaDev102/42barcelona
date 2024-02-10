#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h" 
#include "so_long.h"

// void fill(char **tab, t_flood size, t_flood res, char to_fill)
// {
// 	if (res.x < 0 || res.x >= size.x || res.y < 0 || res.y >= size.y || tab[res.y][res.x] != to_fill)
// 		return ;

// 	tab[res.y][res.x] = 'F';
// 	fill(tab, size, (t_flood){res.x + 1, res.y}, to_fill);
// 	fill(tab, size, (t_flood){res.x - 1, res.y}, to_fill);
// 	fill(tab, size, (t_flood){res.x, res.y + 1}, to_fill);
// 	fill(tab, size, (t_flood){res.x, res.y - 1}, to_fill);
// }

// void  flood_fill(char **tab, t_flood size, t_flood begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }

// char** make_area(char** zone, t_flood size)
// {
// 	char** new;

// 	new = malloc(sizeof(char*) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}

// 	return new;
// }

void check_line(char *line, t_flood *flood)
{
	int i;

	i = 0;
	flood->linecontrol = 1;
	while (line[i])
	{
		if (line[i] == '\n')
			flood->linecontrol = 0;
		i++;
	}
}

int main(int argc, char *argv[])
{
   	t_flood g;
	char **map;
  //  t_flood size = {8,5};
    // char *zone[] = {
	// 	"11111111",
	// 	"10001001",
	// 	"10010001",
	// 	"10110001",
	// 	"11100001",
	// };
	//printf("entraa");
	map = check_param(argc, argv, &g);
	init_game(map, &g);
	

	// char**  area = make_area(zone, size);
    //t_flood begin = {7,4};
    //char *map_tmp;
    //for (int i = 0; i < size.y; ++i)
	//	printf("%s\n", area[i]);
	//flood.line = get_next_line(fd);
	//printf("%zu", ft_strlen(flood.line));
	//check_line(flood.line, &flood);
    //flood.big_line = ft_strjoin(flood.big_line, flood.line);
	//printf("%s", flood.big_line);
	//  while ((flood.map  = get_next_line(fd)))
    //  {
    //     map_tmp =  flood.map;
    //  } 
    // flood_fill(map_tmp, size, begin);

    return (0);
}