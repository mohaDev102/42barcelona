
NAME = Serializer

FLAGS = -std=c++98 -Wall -Wextra -Werror -g -fsanitize=address

SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = Serializer.hpp Data.hpp
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

