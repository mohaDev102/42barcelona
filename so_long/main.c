#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h" 

# define MAP_WIDTH 10
# define MAP_HEIGHT 5

typedef struct s_game
{
	void *mlx;
	void *win;
	int player_x;
	int player_y;
	char *map;
	void *img;
	char *dir;
	int bit_pixel;
	int length;
	int endian;

} t_game;

//   typedef struct  s_point
//   {
//     int           x;
//     int           y;
//   }               t_point;

void init_game(t_game *game)
{
	// inicializar
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	int width = 80;
    	int height = 60;
	game->win = mlx_new_window(game->mlx, 800, 600, "so_long");
	//game->img = mlx_new_image(game->mlx, 800, 600);
	game->img = mlx_xpm_file_to_image(game->mlx, "mario_bros.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_x,game->player_y);
	// funcion para cargar el mapa
		
}

// W = 13
// A = 0
// S = 1
// D = 28
// ESC = 53
int key_press(int key, void *param)
{
	t_game game;
	//printf("key pressed %d", key);
	if (key == 53)
		exit(1);
	else if (key == 13)
		game.player_y++;
	else if (key == 0)
		game.player_x--;
	else if (key == 1)
		game.player_y--;
	else if (key == 28)
		game.player_x++;
	return (0);		
}

int close_window(void *param)
{
	printf("Closed Window");
	exit(0);
}

// void fill(char **tab, t_point size, t_point res, char to_fill)
// {
// 	if (res.x < 0 || res.x >= size.x || res.y < 0 || res.y >= size.y || tab[res.y][res.x] != to_fill)
// 		return ;

// 	tab[res.y][res.x] = 'F';
// 	fill(tab, size, (t_point){res.x + 1, res.y}, to_fill);
// 	fill(tab, size, (t_point){res.x - 1, res.y}, to_fill);
// 	fill(tab, size, (t_point){res.x, res.y + 1}, to_fill);
// 	fill(tab, size, (t_point){res.x, res.y - 1}, to_fill);
// }

// void  flood_fill(char **tab, t_point size, t_point begin)
// {
// 	fill(tab, size, tab[begin.y, begin.x], to_fill);
// }

int main(int argc, char *argv[])
{
	t_game game;
	if (argc == 2)
	{
		//  char **area;
		// t_point size = { 8, 5 };
		// t_point begin = { 2, 2 };
		// char *zone[] = {
		// 	"11111111",
		// 	"10001001",
		// 	"10010001",
		// 	"10110001",
		// 	"11100001"
		// };
		// area = make_area(zone);
		// print_tab(area);
		// flood_fill(area, size, begin);
		// putc('\n');
		// print_tab(area);
		// return (0);



		int fd = open("map1.ber", O_WRONLY, 0777);
		if (fd == -1)
			return (1);
		game.map = get_next_line(fd);
		printf("%s\n", game.map);
		init_game(&game);
		mlx_key_hook(game.win, key_press, (void *)0);
		mlx_hook(game.win, 17, 1L << 17, close_window ,(void *)0);
		//mlx_key_hook(game.win, key_press, (void *)0);
		mlx_loop(game.mlx);
	}
	return (0);

}

