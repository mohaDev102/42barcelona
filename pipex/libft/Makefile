NAME = libft.a

SRC = ft_strjoin.c ft_split.c ft_strlen.c ft_strdup.c ft_substr.c ft_calloc.c ft_memset.c ft_strcmp.c

OBJ = $(SRC:.c=.o)
HEADER = pipex.h
LIB = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o:%.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
