
NAME = Harl

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = Harl.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = Harl.hpp
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) Makefile
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(DEPS)
	c++ $(FLAGS) -c $< -o $@

clean:
	rm $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

