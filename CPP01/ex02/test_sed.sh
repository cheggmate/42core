#!/bin/bash
EXE="./sed_is_for_losers"
TEST_FILE="test.txt"

echo "compiling..."

make re > /dev/null
echo "This is a test file. Test test test." > $TEST_FILE

# Test 1: Standard replacement
$EXE $TEST_FILE "test" "SUCCESS"
echo "Result of 'test' -> 'SUCCESS':"
cat test.txt.replace

# Test 2: Empty string replacement (s1 is empty)
$EXE $TEST_FILE "" "NONE"

# Test 3: Non-existent file
$EXE "missing_file.txt" "s1" "s2"

# Test 4: File with no permissions
touch no_perm.txt && chmod 000 no_perm.txt
$EXE no_perm.txt "s1" "s2"
rm -f no_perm.txt test.txt

make fclean