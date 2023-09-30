NAME = libft.a

SRC = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strnstr.c\
	  ft_bzero.c ft_toupper.c ft_tolower.c ft_strncmp.c ft_calloc.c ft_memset.c ft_strdup.c\
	  ft_strlen.c ft_strchr.c ft_strrchr.c ft_memmove.c ft_substr.c ft_strjoin.c ft_memcpy.c\
	  ft_strtrim.c ft_putnbr_fd.c ft_striteri.c ft_memchr.c ft_strlcpy.c ft_split.c ft_atoi.c\
	  ft_memcmp.c ft_memchr.c ft_strlcat.c ft_strdup.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c

B_SRC = ft_lstlast.c ft_lstsize.c ft_lstnew.c ft_lstadd_front.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
	ft_lstmap.c

OBJ = $(SRC:.c=.o)
#B_OBJ = $(B_SRC:.c=.o)
HEADER = libft.h

LIB = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o:%.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

#bonus: $(OBJ) $(B_OBJ)
#	ar rcs $(NAME) $(OBJ) $(B_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
re: fclean all

rebonus: clean bonus

.PHONY: all clean fclean re
