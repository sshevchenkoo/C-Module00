SRC = AMateria.cpp Cure.cpp Ice.cpp ICharacter.cpp IMateriaSource.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = materia

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re