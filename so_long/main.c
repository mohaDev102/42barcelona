#include "minilibx-linux/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define MAP_WIDTH 10
# define MAP_HEIGHT 5

typedef struct s_game
{
	void *mlx;
	void *win;
	int player_x;
	int player_y;
	char map[MAP_HEIGHT][MAP_WIDTH];
	void *img;
	char *dir;
	int bit_pixel;
	int length;
	int endian;

} t_game;

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
	//my_mlx_pixel_put(game, 5, 5,0x00FF0000);
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
	printf("key pressed %d", key);
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

int main(int argc, char *argv[])
{
	t_game game;

	init_game(&game);

	mlx_key_hook(game.win, key_press, (void *)0);
	//mlx_hook(game.win, 17, 1L << 17, close_window ,(void *)0);
	//mlx_key_hook(game.win, key_press, (void *)0);
	mlx_loop(game.mlx);
	return (0);

}

