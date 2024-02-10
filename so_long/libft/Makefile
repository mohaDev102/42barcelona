NAME = libft.a

SRC = ft_strjoin.c ft_strlen.c ft_strcmp.c ft_strncmp.c

OBJ = $(SRC:.c=.o)
HEADER = pipex.h
LIB = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
