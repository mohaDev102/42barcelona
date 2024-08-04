
NAME = megaphone

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

