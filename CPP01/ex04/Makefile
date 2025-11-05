# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/02 22:23:16 by jotong            #+#    #+#              #
#    Updated: 2025/11/05 22:17:23 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = c++

# Compiler flags
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror

# Program name
TARGET = sed_is_for_losers

# Source files
SRC = main.cpp find_and_replace.cpp checks.cpp tests.cpp 
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