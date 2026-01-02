#!/bin/bash

# Configuration
EXE="./account"
REF_LOG="19920104_091532.log"
MY_LOG="current.log"
DIFF_LOG="diff.log"

# Colors
BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# 1. Check if files exist
if [ ! -f "$REF_LOG" ]; then
    echo -e "${RED}Error: Reference log ($REF_LOG) not found in directory.${NC}"
    exit 1
fi

# 2. Compile
echo -e "${BLUE}Compiling...${NC}"
make re > /dev/null

if [ ! -f "$EXE" ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

# 3. Run and generate log
echo -e "${BLUE}Running program and generating log...${NC}"
$EXE > $MY_LOG

# 4. Compare logs ignoring timestamps
# Timestamps are in format [YYYYMMDD_HHMMSS]
# We use 'cut' to remove the first 17 characters of every line
echo -e "${BLUE}Comparing outputs (ignoring timestamps)...${NC}"

cut -d ' ' -f2- $REF_LOG > ref_no_time.tmp
cut -d ' ' -f2- $MY_LOG > my_no_time.tmp

diff -y --suppress-common-lines ref_no_time.tmp my_no_time.tmp > $DIFF_LOG

if [ ! -s $DIFF_LOG ]; then
    echo -e "${GREEN}✅ SUCCESS: Your output matches the reference perfectly!${NC}"
    rm ref_no_time.tmp my_no_time.tmp $DIFF_LOG $MY_LOG
else
    echo -e "${RED}❌ FAILURE: Differences found!${NC}"
    echo "Check $DIFF_LOG to see the discrepancies."
    echo "Note: Left side is Reference, Right side is Yours."
fi