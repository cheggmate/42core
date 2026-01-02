#!/bin/bash
# Test for ex00 and ex01

run_valgrind() {
    echo "--- Testing $1 with Valgrind ---"
    valgrind --leak-check=full --show-leak-kinds=all ./$1
    echo "--------------------------------"
}

# ex00: Check if stack zombies and heap zombies both announce and die
cd ex00 && make re > /dev/null
run_valgrind "zombie"

# ex01: Check if N zombies are allocated in ONE 'new[]' call and 'delete[]'
cd ../ex01 && make re > /dev/null
run_valgrind "zombieHorde"