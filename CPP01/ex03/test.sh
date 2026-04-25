#!/bin/bash
# Save as ex03/test.sh

echo "--- Compiling ex03 ---"
make re > /dev/null

echo -e "\n--- Running Attack Logic Test ---"
# Should show attacks with "crude spiked club" then "some other type of club"
valgrind --leak-check=full ./unnecessaryViolence

make fclean > /dev/null