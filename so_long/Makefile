NAME = so_long

SRC = floodfill.c get_next_line.c get_next_line_utils.c checker.c errors.c map.c moves.c

OBJ = $(SRC:.c=.o)
HEADER = so_long.h
LIBFT = libft/libft.a
RM = rm -f
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -lmlx -L minilibx/ -framework OpenGL -framework AppKit $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
