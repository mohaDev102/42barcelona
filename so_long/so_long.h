
#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "minilibx/mlx.h"

typedef struct flood_fill
{
    char *map;
	char *line;
    void *mlx;
	void *win;
    void *img;
	int player_x;
	int player_y;
	int linecontrol;
	char *big_line;
	int ncol;
	int nrow;
	int ncollect;
	int nexits;
	int nwalls;
    int x;
    int y;
} t_flood;


typedef struct t_error
{
	int rowlen;
	int nplayer;
	int ncollect;
	int nexits;
	int nwalls;
} t_err;

//void check_line(char *line, t_flood *flood);
char	*get_next_line(int fd);
void error_param(char *msg, char **map);
char	**check_param(int argc, char *argv[], t_flood *g);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**check_map(int fd, t_flood *g);
void init_game(char **map, t_flood *g);
int ft_conteins_ber(char *str);
// char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);

#endif