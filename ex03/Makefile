NAME = ex03

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -f

SRC = main.cpp \
	AMateria.cpp Ice.cpp Cure.cpp \
	Character.cpp MateriaSource.cpp 

OBJ = $(SRC:.cpp=.o)

HEADERS = AMateria.hpp Ice.hpp Cure.hpp \
	ICharacter.hpp Character.hpp \
	IMateriaSource.hpp MateriaSource.hpp

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re