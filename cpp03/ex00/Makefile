
NAME = ClapTrap

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = ClapTrap.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = ClapTrap.hpp
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(DEPS)
	g++ $(FLAGS) -c $< -o $@

clean:
	rm $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

