
NAME = Fixed

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = Fixed.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = Fixed.hpp
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

