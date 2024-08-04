
NAME = phoneBook

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = PhoneBook.cpp Contact.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = PhoneBook.hpp Contact.hpp
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

