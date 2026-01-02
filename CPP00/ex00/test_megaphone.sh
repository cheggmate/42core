#!/bin/bash

# Configuration
EXE="./megaphone"
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Ensure program is compiled
make re > /dev/null

echo -e "${YELLOW}--- Running CPP00 Megaphone Tests ---${NC}"

# Test 1: No Arguments [cite: 132-133]
echo -e "\n${YELLOW}Test 1: No Arguments${NC}"
ACTUAL=$($EXE)
EXPECTED="* LOUD AND UNBEARABLE FEEDBACK NOISE *"
if [ "$ACTUAL" == "$EXPECTED" ]; then echo -e "Status: ${GREEN}✅ PASS${NC}"; else echo -e "Status: ${RED}❌ FAIL${NC}"; fi
echo "Actual:   [$ACTUAL]"

# Test 2: Single long string [cite: 128-129]
echo -e "\n${YELLOW}Test 2: Single String Input${NC}"
INPUT="shhhhh... I think the students are asleep..."
ACTUAL=$($EXE "$INPUT")
EXPECTED="SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
if [ "$ACTUAL" == "$EXPECTED" ]; then echo -e "Status: ${GREEN}✅ PASS${NC}"; else echo -e "Status: ${RED}❌ FAIL${NC}"; fi
echo "Actual:   [$ACTUAL]"

# Test 3: Multiple arguments [cite: 130-131]
# This tests if you are accidentally adding spaces between arguments
echo -e "\n${YELLOW}Test 3: Multiple Inputs (Concatenation Test)${NC}"
# We pass these as 3 separate arguments to argv
ACTUAL=$($EXE "Damnit" " ! " "Sorry students, I thought this thing was off.")
EXPECTED="DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
if [ "$ACTUAL" == "$EXPECTED" ]; then echo -e "Status: ${GREEN}✅ PASS${NC}"; else echo -e "Status: ${RED}❌ FAIL${NC}"; fi
echo "Actual:   [$ACTUAL]"
echo "Expected: [$EXPECTED]"

echo -e "\n${YELLOW}--------------------------------------${NC}"