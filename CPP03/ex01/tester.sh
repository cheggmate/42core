#!/bin/bash

# Configuration
NAME="scavtrap_test"
CC="c++"
FLAGS="-Wall -Wextra -Werror -std=c++98"
SRCS="main.cpp ClapTrap.cpp ScavTrap.cpp"

echo "--- Step 1: Compiling ---"
$CC $FLAGS $SRCS -o $NAME

if [ $? -eq 0 ]; then
    echo "Compilation successful!"
else
    echo "Compilation failed!"
    exit 1
fi

echo -e "\n--- Step 2: Running Tests ---"
./$NAME

echo -e "\n--- Step 3: Checking for Memory Leaks ---"
# Check if valgrind is installed
if command -v valgrind &> /dev/null; then
    valgrind --leak-check=full ./$NAME
else
    echo "Valgrind not found. If on Mac, use: leaks -atExit -- ./$NAME"
fi

# Clean up
rm $NAME
