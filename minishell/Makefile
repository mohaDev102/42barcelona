NAME = minishell
SRC = src/minishell.c src/lexer/ft_lexer.c src/lexer/lexer_utils.c src/lexer/lexer_utils2.c src/parser/ft_parser.c src/signal.c

OBJ = $(SRC:.c=.o)
HEADER = minishell.h
LIBFT = libft/libft.a
RM = rm -f
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I./readline -L./readline $^ -o $@ -lreadline -lhistory -ltermcap

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