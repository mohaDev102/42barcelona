
NAME = Zombie

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = Zombie.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = Zombie.hpp
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(DEPS)
	c++ $(FLAGS) -c $< -o $@

clean:
	rm $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

