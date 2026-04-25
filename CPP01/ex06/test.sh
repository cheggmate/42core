#!/bin/bash

EXE="./harlFilter"
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# 1. Compile
echo -e "${YELLOW}Compiling ex06...${NC}"
make re > /dev/null

if [ ! -f "$EXE" ]; then
    echo -e "${RED}Error: Executable '$EXE' not found. Check your Makefile.${NC}"
    exit 1
fi

# Function to run test and display output
run_harl_test() {
    local label=$1
    shift
    local args=("$@")
    
    echo -e "\n${YELLOW}--- Testing: $label ---${NC}"
    echo "Command: $EXE ${args[@]}"
    
    # Capture your program's output
    # We use 2>&1 to capture both standard output and error messages
    MY_OUTPUT=$($EXE "${args[@]}" 2>&1)
    
    echo -e "Your Output:\n\"$MY_OUTPUT\""
    
    # Validation logic
    if [[ "$label" == "Invalid" ]] || [[ "$label" == "Too Many Args" ]]; then
        if [[ "$MY_OUTPUT" == *"[ Probably complaining about insignificant problems ]"* ]]; then
            echo -e "Status: ${GREEN}✅ PASS${NC}"
        else
            echo -e "Status: ${RED}❌ FAIL (Missing default message)${NC}"
        fi
    else
        # Check for hierarchy (e.g., WARNING should contain WARNING and ERROR)
        if [[ "$MY_OUTPUT" == *"$label"* ]]; then
            echo -e "Status: ${GREEN}✅ PASS${NC}"
        else
            echo -e "Status: ${RED}❌ FAIL (Level $label not found)${NC}"
        fi
    fi
}

# 2. Run the tests
run_harl_test "DEBUG" "DEBUG"
run_harl_test "INFO" "INFO"
run_harl_test "WARNING" "WARNING"
run_harl_test "ERROR" "ERROR"
run_harl_test "Invalid" "I am bored"
run_harl_test "Too Many Args" "WARNING" "ERROR"

# 3. Cleanup
make fclean > /dev/null