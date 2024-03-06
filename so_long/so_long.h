
#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "minilibx/mlx.h"

#define CELL_SIZE 50

typedef struct validMap
{
	char **grid;
	int height;
	int width;
} Map;

typedef struct flood_fill
{
    Map *map;
	char *line;
    void *mlx;
	void *win;
    void *img_player;
	void *img_floor;
	void *img_wall;
	void *img_coin;
	void *img_exit;
	int player_x;
	int player_y;
	int moves;
	int linecontrol;
	char *big_line;
	int ncol;
	int nrow;
	int ncollect;
	int coins;
	int nexits;
	int nwalls;
    int x;
    int y;
} t_flood;

typedef struct
{
    t_flood *game;
    Map *map;
} GameMap;

typedef struct t_error
{
	int rowlen;
	int nplayer;
	int ncollect;
	int nexits;
	int nwalls;
} t_err;

char	*get_next_line(int fd);
void error_param(char *msg, char **map);
Map	*check_param(int argc, char *argv[], Map *map);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
Map	*check_map(int fd, Map *map);
void init_game(Map *map, t_flood *g);
int ft_conteins_ber(char *str);
int validarMapa(t_flood *g);
t_err ft_newmap_error();
size_t	ft_strlen(const char *c);
void ft_read_map(int fd, t_err *map_err, t_flood *g, char **map_str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char    *ft_strcpy(char *s1, char *s2);
int	validateMap(Map* map);
void printMap(t_flood *g, Map *map);
int isValidMove(Map *map, int x, int y);
void movePlayer(Map *map, t_flood *game, int new_x, int new_y);
void erasePlayer(t_flood *game, int x, int y);
void drawPlayer(t_flood *game);
void count_coins(t_flood *game, Map *map);
void put_nbr(int num);
#endif