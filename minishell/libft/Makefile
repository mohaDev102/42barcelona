NAME = libft.a

SRC = ft_strjoin.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_split.c ft_substr.c ft_strdup.c ft_calloc.c ft_memset.c ft_strcpy.c ft_memmove.c ft_isprint.c

OBJ = $(SRC:.c=.o)
HEADER = minishell.h
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
