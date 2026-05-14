# Compiler
CXX = c++

# Compiler flags
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror -Wshadow -Wno-shadow

# Program name
TARGET = mutant_stack

# Source files
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Default rule
all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(TARGET)

re : fclean all

.PHONY: all clean fclean re
