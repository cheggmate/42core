#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

TESTS_RUN=0
TESTS_PASSED=0

echo "compiling..."
make re > /dev/null

test_case() {
	local EXPECTED_CODE="$1"
	local CMD="$2"
	local EXPECTED_OUTPUT="$3"
	local TEST_NAME="Test $((TESTS_RUN + 1)) : $4"

	TESTS_RUN=$((TESTS_RUN + 1))

	ACTUAL_OUTPUT=$(eval "$CMD" 2>&1) #execute command, capture stdout & stderr
	ACTUAL_CODE=$? #capture exit code

	echo -n "-> $TEST_NAME"

	if [ "$ACTUAL_CODE" -ne "$EXPECTED_CODE" ]; then
		echo -e "${RED}FAIL (Code)${NC}"
		echo "	- Command: $CMD"
		echo "	- Expected Exit Code: $EXPECTED_CODE, Actual: $ACTUAL_CODE"
		echo "	- Output was: '$ACTUAL_OUTPUT'"
		return 1
	fi
	
	if [ "$ACTUAL_OUTPUT" != "$EXPECTED_OUTPUT" ]; then
		echo -e "${RED}FAIL (Output)${NC}"
		echo "	- Command: $CMD"
		echo "	- Expected Output: '$EXPECTED_OUTPUT'"
		echo "	- Output was: '$ACTUAL_OUTPUT'"
		return 1
	fi

	echo -e "${GREEN}PASS${NC}"
	TESTS_PASSED=$((TESTS_PASSED + 1))
	return 0

}

# Test case: 
test_case 0 "./harl 'debug'" "(Debug) I love having extra bacon for my7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"

test_case 0 "./harl 'error'" "(Error) This is unacceptable! I want to speak to the manager now."

test_case 0 "./harl 'warning'" "(Warning) I think I deserve to have some extra bacon for free.I’ve been coming for years, whereas you started working here just last month."

test_case 0 "./harl 'info'" "(Info) I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"

test_case 0 "./harl 'exit'" "Unknown input: The provided level does not match the supported levels."

test_case 1 "./harl 'debug' 'error'" "Too many arguments."

test_case 0 "./harl '1'" "Unknown input: The provided level does not match the supported levels."

# --- Summary ---

echo -e "\n----------------------------------------"
echo "TEST SUMMARY"
echo "----------------------------------------"
echo "Total Tests Run: $TESTS_RUN"
if [ "$TESTS_PASSED" -eq "$TESTS_RUN" ]; then
    echo -e "${GREEN}ALL $TESTS_PASSED TESTS PASSED!${NC}"
else
    FAILED=$((TESTS_RUN - TESTS_PASSED))
    echo -e "${RED}$FAILED / $TESTS_RUN TESTS FAILED.${NC}"
fi
echo "----------------------------------------"

# Return overall script status code (0 if all passed, 1 otherwise)
if [ "$TESTS_PASSED" -ne "$TESTS_RUN" ]; then
    exit 1
fi

make fclean > /dev/null
