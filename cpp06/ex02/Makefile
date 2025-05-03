
NAME = Base

FLAGS = -std=c++98 -Wall -Wextra -Werror -g -fsanitize=address

SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = Base.hpp A.hpp B.hpp C.hpp
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

