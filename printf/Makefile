

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_putnbrabs.c ft_puthexa.c ft_putptr.c

OBJ = $(SRC:.c=.o)


AR = ar rcs

HEADER = ft_printf.h
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o:%.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
