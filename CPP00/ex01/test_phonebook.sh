#!/bin/bash

# Configuration
EXE="./phonebook" # Ensure this matches your Makefile output name
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# 1. Check for executable
if [ ! -f "$EXE" ]; then
    echo "Compiling..."
    make re > /dev/null
fi

echo -e "${YELLOW}--- Running PhoneBook Capacity & Rotation Test ---${NC}"

# This command string:
# 1. Adds 8 contacts (filling the book)
# 2. Adds a 9th contact (should replace the 1st)
# 3. Searches to verify the list
# 4. Exits
(
echo "ADD"; echo "First1"; echo "Last1"; echo "Nick1"; echo "111"; echo "Secret1"
echo "ADD"; echo "First2"; echo "Last2"; echo "Nick2"; echo "222"; echo "Secret2"
echo "ADD"; echo "First3"; echo "Last3"; echo "Nick3"; echo "333"; echo "Secret3"
echo "ADD"; echo "First4"; echo "Last4"; echo "Nick4"; echo "444"; echo "Secret4"
echo "ADD"; echo "First5"; echo "Last5"; echo "Nick5"; echo "555"; echo "Secret5"
echo "ADD"; echo "First6"; echo "Last6"; echo "Nick6"; echo "666"; echo "Secret6"
echo "ADD"; echo "First7"; echo "Last7"; echo "Nick7"; echo "777"; echo "Secret7"
echo "ADD"; echo "First8"; echo "Last8"; echo "Nick8"; echo "888"; echo "Secret8"
echo "ADD"; echo "NewNine"; echo "Last9"; echo "Nick9"; echo "999"; echo "Secret9"
echo "SEARCH"
echo "EXIT"
) | $EXE > test_output.txt

echo -e "${GREEN}Test complete. Checking output...${NC}"

# Check if 'First1' was successfully replaced by 'NewNine'
if grep -q "NewNine" test_output.txt && ! grep -q "First1" test_output.txt; then
    echo -e "✅ Rotation Test: PASS (9th contact replaced the 1st)"
else
    echo -e "❌ Rotation Test: FAIL (Oldest contact not replaced)"
fi

# Check for truncation (test with a long string)
echo -e "\n${YELLOW}--- Running Truncation Test ---${NC}"
(
echo "ADD"; echo "Margareth-Ann"; echo "Smith"; echo "Maggie"; echo "000"; echo "none"
echo "SEARCH"
echo "EXIT"
) | $EXE | grep "Margareth." > /dev/null

if [ $? -eq 0 ]; then
    echo -e "✅ Truncation Test: PASS (Long name correctly ends with a dot)"
else
    echo -e "❌ Truncation Test: FAIL (Check your 10-char formatting and dot)"
fi

rm test_output.txt