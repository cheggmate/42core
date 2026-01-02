#!/bin/bash
# Save as ex00/test.sh

echo "--- Compiling ex00 ---"
make re > /dev/null

echo -e "\n--- Running Valgrind (Check Stack vs Heap Destructors) ---"
# Tests newZombie (heap) and randomChump (stack) [cite: 358, 360]
valgrind --leak-check=full --show-leak-kinds=all ./zombie

make fclean > /dev/null