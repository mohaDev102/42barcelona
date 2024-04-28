NAME = minishell
SRC = minishell.c lexer.c lexer_utils.c lexer_utils2.c parser/ft_parser.c signal.c

OBJ = $(SRC:.c=.o)
HEADER = minishell.h
LIBFT = libft/libft.a
RM = rm -f
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -Lreadline/ -lreadline -lhistory -ltermcap

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