#!/bin/bash
# Save as ex01/test.sh

echo "--- Compiling ex01 ---"
make re > /dev/null

echo -e "\n--- Running Valgrind (Check Single Allocation delete[]) ---"
# Verify if N zombies are announced and then all destroyed [cite: 381, 382]
valgrind --leak-check=full --show-leak-kinds=all ./zombieHorde

make fclean > /dev/null