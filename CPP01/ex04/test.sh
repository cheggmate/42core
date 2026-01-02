#!/bin/bash
# Save this in your ex04/ directory

EXE="./sed_is_for_losers"
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# 1. Compile
echo -e "${YELLOW}Compiling ex04...${NC}"
make re > /dev/null
if [ ! -f "$EXE" ]; then
    echo -e "${RED}Error: Compilation failed.${NC}"
    exit 1
fi

# Function to run a test case
# Usage: run_test "Test Name" "Input Content" "s1" "s2" "Expected Result"
run_test() {
    local name=$1
    local content=$2
    local s1=$3
    local s2=$4
    local expected=$5
    local filename="test_input.txt"

    echo -e "\n${YELLOW}Running: $name${NC}"
    echo -n "$content" > "$filename"
    
    # Run the program
    $EXE "$filename" "$s1" "$s2"
    
    # Check if the replace file was created
    if [ ! -f "${filename}.replace" ]; then
        echo -e "Status: ${RED}❌ FAIL (replace file not created)${NC}"
        return
    fi

    # Compare results
    ACTUAL=$(cat "${filename}.replace")
    if [ "$ACTUAL" == "$expected" ]; then
        echo -e "Status: ${GREEN}✅ PASS${NC}"
    else
        echo -e "Status: ${RED}❌ FAIL${NC}"
        echo "  Expected: [$expected]"
        echo "  Actual  : [$ACTUAL]"
    fi
    
    # Cleanup temporary test files
    rm -f "$filename" "${filename}.replace"
}

# 2. Test Cases [cite: 457, 460]
run_test "Standard Replace" "hello world" "world" "42" "hello 42"
run_test "Multiple Occurrences" "aaa" "a" "b" "bbb"
run_test "Empty s2" "delete me" "me" "" "delete "
run_test "Words with spaces" "test this" "test this" "success" "success"
run_test "No match found" "nothing changes" "apple" "orange" "nothing changes"

# 3. Error Case: File Permissions
echo -e "\n${YELLOW}Running: Permission Denied Test${NC}"
touch secret.txt && chmod 000 secret.txt
OUTPUT=$($EXE secret.txt "a" "b" 2>&1)
if [[ $OUTPUT == *"Error"* ]] || [[ $OUTPUT == *"permission"* ]]; then
    echo -e "Status: ${GREEN}✅ PASS (Error handled)${NC}"
else
    echo -e "Status: ${RED}❌ FAIL (Should have shown an error)${NC}"
fi
rm -f secret.txt

make fclean > /dev/null