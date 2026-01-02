#!/bin/bash
# Save as ex04/test.sh

echo "--- Compiling ex04 ---"
make re > /dev/null

FILENAME="test_file.txt"
echo "apple banana apple cherry apple" > $FILENAME

echo -e "\n--- Test 1: Standard Replace (apple -> ORANGE) ---"
./sed_is_for_losers $FILENAME "apple" "ORANGE"
echo "Result:"
cat ${FILENAME}.replace

echo -e "\n--- Test 2: Error Handling (Missing File) ---"
./sed_is_for_losers non_existent.txt "s1" "s2"

echo -e "\n--- Test 3: Error Handling (Empty String s1) ---"
./sed_is_for_losers $FILENAME "" "FAIL"

rm -f $FILENAME ${FILENAME}.replace
make fclean > /dev/null