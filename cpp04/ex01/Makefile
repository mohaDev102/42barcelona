
NAME = Brain

FLAGS = -std=c++98 -Wall -Wextra -Werror -g -fsanitize=address

SRC = Animal.cpp main.cpp WrongAnimal.cpp WrongCat.cpp Dog.cpp Cat.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
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

