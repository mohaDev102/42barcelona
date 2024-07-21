# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alounici <alounici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 13:47:31 by alounici          #+#    #+#              #
#    Updated: 2024/07/21 13:47:34 by alounici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = src/minishell.c src/lexer/ft_lexer.c src/lexer/lexer_utils.c
src/lexer/lexer_utils2.c src/parser/ft_parser.c \
src/signal.c src/parser/ft_parser_utils.c
src/parser/ft_parser_utils2.c src/parser/ft_free.c
src/parser/ft_parser_utils3.c \
src/executor/ft_executor.c src/expandor.c src/expandor_utils.c
src/builtins/generate_env.c src/builtins/ft_cd.c \
src/builtins/ft_echo.c src/builtins/ft_env.c src/builtins/ft_export.c
src/builtins/ft_pwd.c src/builtins/ft_unset.c \
src/executor/ft_redirects.c src/her_doc/her_doc.c src/her_doc/utils.c
src/builtins/env_utils.c \
src/builtins/export_utils.c src/executor/is_buildins2.c
src/builtins/ft_exit.c src/executor/is_builtins.c
src/builtins/buildins_error.c src/executor/ft_free.c \
src/expandor_utils2.c src/builtins/ft_tilde.c src/expandor_utils3.c
src/builtins/exit_utils.c src/split_exp.c


OBJ = $(SRC:.c=.o)
HEADER = inc/minishell.h
LIBFT_DIR = libft
READLINE_DIR = readline/
READLINE = $(READLINE_DIR)libreadline.a
HISTORY = $(READLINE_DIR)libhistory.a
LIBFT = $(LIBFT_DIR)/libft.a
RM = rm -f
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address

all: readl $(NAME)

$(NAME): $(OBJ)
make -C $(LIBFT_DIR)
$(CC) $(CFLAGS) $(OBJ) -L./libft/ -L./readline/ -lreadline -lhistory
-ltermcap -lft -o $@

$(LIBFT):
make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
$(CC) $(CFLAGS) -c -o $@ $<

readl:
@if [ -e "$(HISTORY)" ] && [ -e "$(READLINE)" ]; then \
echo "readline and minishell already compiled"; \
else \
cd ./readline/ && bash ./configure && make; \
fi

clean:
$(RM) $(OBJ)
make clean -C $(LIBFT_DIR)
make clean -C $(READLINE_DIR)

fclean: clean
$(RM) $(NAME)
$(RM) $(LIBFT_DIR)libft.a

re: fclean all

.PHONY: all clean fclean re readl

