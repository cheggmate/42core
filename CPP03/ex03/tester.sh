#!/bin/bash

# Configuration
NAME="diamondtrap_test"
CC="c++"
# -Wshadow is specifically recommended for this exercise
FLAGS="-Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98"
SRCS="main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp"

echo "--- Step 1: Compiling DiamondTrap ---"
$CC $FLAGS $SRCS -o $NAME

if [ $? -eq 0 ]; then
    echo "Compilation successful!"
else
    echo "Compilation failed!"
    exit 1
fi

echo -e "\n--- Step 2: Running Tests ---"
./$NAME

echo -e "\n--- Step 3: Leak Check ---"
valgrind --leak-check=full ./$NAME

rm $NAME