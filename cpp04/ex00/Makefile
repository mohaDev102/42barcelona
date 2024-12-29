
NAME = Animal

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = Animal.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp
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

