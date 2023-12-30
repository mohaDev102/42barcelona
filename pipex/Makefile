NAME = pipex

SRC = src/pipex.c src/pipex_utils.c src/utils2.c libft/libft.a

OBJ = $(SRC:.c=.o)
HEADER = pipex.h
LIB = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME):
	make all -C libft
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
