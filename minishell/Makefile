NAME = minishell
SRC = src/minishell.c src/lexer/ft_lexer.c src/lexer/lexer_utils.c src/lexer/lexer_utils2.c src/parser/ft_parser.c \
	src/signal.c src/parser/ft_parser_utils.c src/parser/ft_parser_utils2.c src/parser/ft_free.c src/parser/ft_parser_utils3.c \
	src/executor/ft_executor.c src/expandor.c src/expandor_utils.c src/builtins/generate_env.c src/builtins/ft_cd.c \
	src/builtins/ft_echo.c src/builtins/ft_env.c src/builtins/ft_export.c src/builtins/ft_pwd.c src/builtins/ft_unset.c \
	src/executor/ft_executor.c src/executor/ft_redirects.c src/her_doc/her_doc.c src/her_doc/utils.c \
	src/executor/ft_executor.c src/expandor.c src/expandor_utils.c src/builtins/generate_env.c src/builtins/env_utils.c src/builtins/ft_cd.c \
	src/builtins/ft_echo.c src/builtins/ft_env.c src/builtins/ft_export.c src/builtins/ft_pwd.c src/builtins/ft_unset.c src/builtins/export_utils.c \
	src/builtins/ft_exit.c src/executor/is_builtins.c


OBJ = $(SRC:.c=.o)
HEADER = inc/minishell.h
LIBFT = libft/libft.a
RM = rm -f
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I./readline -L./readline $^ -o $@ -lreadline -lhistory -ltermcap

$(LIBFT):
	make -C libft

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re