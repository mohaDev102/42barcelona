/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:01:50 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/16 03:01:52 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define CELL_SIZE 50
# define HEIGHT 40
# define WIDTH 40

typedef struct validMap
{
	char	**grid;
	int		height;
	int		width;
	int		ncoins;
	int		nexit;
	int		x;
	int		y;
}			t_map;

typedef struct flood_fill
{
	t_map	*map;
	char	*line;
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_coin;
	void	*img_exit;
	int		player_x;
	int		player_y;
	int		moves;
	int		nplayer;
	int		linecontrol;
	char	*big_line;
	int		ncol;
	int		nrow;
	int		ncollect;
	int		coins;
	int		nexits;
	int		nwalls;
	int		x;
	int		y;
}			t_game;

typedef struct game_map
{
	t_game	*game;
	t_map	*map;
}			t_game_map;

char		*get_next_line(int fd);
void		error_param(char *msg, char **map);
t_map		*check_param(int argc, char *argv[], t_map *map);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_map		*check_map(int fd, t_map *map);
void		init_game(t_map *map, t_game *g);
int			ft_conteins_ber(char *str);
int			validar_mapa(t_game *g);
// t_err		ft_newmap_error(void);
size_t		ft_strlen(const char *c);
// void		ft_read_map(int fd, t_err *map_err, t_game *g, char **map_str);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strcpy(char *s1, char *s2);
int			validate_map(t_map *map);
void		print_map(t_game *g, t_map *map);
int			is_valid_move(t_map *map, t_game *game, int x, int y);
void		draw_player(t_game *game);
void		count_coins(t_game *game, t_map *map);
void		put_nbr(int num);
void		print_cell(t_game *g, int x, int y, char type);
void		move_player(t_game *game, int new_x, int new_y);
void		erase_player(t_game *game, int x, int y);
void		verify_walls(t_map *map);
int			exit_game(t_map *map, int x, int y);
void		ft_exit(char *str, int ex);
int			initialize_map(t_map *map);
void		free_map(t_map *map);
int			add_to_map(t_map *map, char *line);
void		get_player_position(t_game *game, t_map *map);
t_map		*copy_map(t_map *original);
void		initialize_copy(t_map *copy, t_map *original);
void		collected_coins(t_game *game, t_map *map);
void		ft_put_img(t_game *g, int win_height, int win_width);
void		init_param(t_game *g);
void		handler_movement(int key, t_game *game, t_map *map);
void		add_line_to_map(t_map *map, char *line);
void		check_map_rectan(t_map *map, size_t *first_map_width,
				char *line);
int			close_window(void);
#endif
