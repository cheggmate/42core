# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 20:51:39 by jotong            #+#    #+#              #
#    Updated: 2025/10/31 20:53:25 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = c++

# Compiler flags
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror

# Program name
TARGET = unnecessary_violence

# Source files
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
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