
# Compiler
CXX = c++

# Compiler flags
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror

# Program name
TARGET = a.out

# Source files
SRC = main.cpp Fixed.cpp bsp.cpp Point.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	#$(CXX) $(CXXFLAGS) -c $< -o $@

# Default rule
all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean :
	@rm -f $(TARGET)

fclean : clean
	@rm -f $(TARGET)

re : fclean all

.PHONY: all clean fclean re
