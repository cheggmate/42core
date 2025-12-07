#!/bin/bash

# Advanced Minishell Test Script with options
# Usage: ./test_minishell.sh [options]
#   -v, --verbose     Show detailed output for all tests
#   -f, --fast        Skip slow tests
#   -c, --category    Run specific category (echo, export, wildcards, all)
#   -s, --stop        Stop on first failure
#   -h, --help        Show this help message

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m'

# Configuration
MINISHELL="./minishell"
BASH="/bin/bash"
VERBOSE=0
STOP_ON_FAIL=0
CATEGORY="all"
FAST_MODE=0

# Counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Arrays to store failed tests
declare -a FAILED_TEST_NAMES
declare -a FAILED_TEST_COMMANDS

# Temp files
MINISHELL_OUT=$(mktemp)
BASH_OUT=$(mktemp)
TEST_INPUT=$(mktemp)

cleanup() {
    rm -f "$MINISHELL_OUT" "$BASH_OUT" "$TEST_INPUT"
}
trap cleanup EXIT

show_help() {
    echo "Usage: $0 [options]"
    echo ""
    echo "Options:"
    echo "  -v, --verbose     Show detailed output for all tests"
    echo "  -f, --fast        Skip slow tests (large ranges)"
    echo "  -c, --category    Run specific category: echo, export, wildcards, variables, all"
    echo "  -s, --stop        Stop on first failure"
    echo "  -h, --help        Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0                    # Run all tests"
    echo "  $0 -v                 # Run with verbose output"
    echo "  $0 -c echo            # Run only echo tests"
    echo "  $0 -s -v              # Stop on first failure with verbose output"
    exit 0
}

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -v|--verbose)
            VERBOSE=1
            shift
            ;;
        -f|--fast)
            FAST_MODE=1
            shift
            ;;
        -c|--category)
            CATEGORY="$2"
            shift 2
            ;;
        -s|--stop)
            STOP_ON_FAIL=1
            shift
            ;;
        -h|--help)
            show_help
            ;;
        *)
            echo "Unknown option: $1"
            show_help
            ;;
    esac
done

run_test() {
    local test_name="$1"
    local command="$2"
    local category="$3"
    local is_slow="${4:-0}"
    
    # Skip if not in selected category
    if [ "$CATEGORY" != "all" ] && [ "$CATEGORY" != "$category" ]; then
        return 0
    fi
    
    # Skip slow tests in fast mode
    if [ "$FAST_MODE" = "1" ] && [ "$is_slow" = "1" ]; then
        return 0
    fi
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    # Run in bash
    echo "$command" > "$TEST_INPUT"
    timeout 5 bash < "$TEST_INPUT" > "$BASH_OUT" 2>&1
    local bash_exit=$?
    
    # Run in minishell
    timeout 5 $MINISHELL < "$TEST_INPUT" > "$MINISHELL_OUT" 2>&1
    local minishell_exit=$?
    
    # Compare outputs
    if diff -q "$BASH_OUT" "$MINISHELL_OUT" > /dev/null 2>&1; then
        echo -e "${GREEN}✓${NC} [$category] $test_name"
        PASSED_TESTS=$((PASSED_TESTS + 1))
        
        if [ "$VERBOSE" = "1" ]; then
            echo -e "  ${CYAN}Command:${NC} $command"
            echo -e "  ${CYAN}Output:${NC}"
            cat "$MINISHELL_OUT" | sed 's/^/    /'
        fi
        return 0
    else
        echo -e "${RED}✗${NC} [$category] $test_name"
        FAILED_TESTS=$((FAILED_TESTS + 1))
        FAILED_TEST_NAMES+=("$test_name")
        FAILED_TEST_COMMANDS+=("$command")
        
        echo -e "  ${YELLOW}Command:${NC} $command"
        echo -e "  ${YELLOW}Expected (bash):${NC}"
        cat "$BASH_OUT" | head -5 | sed 's/^/    /'
        echo -e "  ${YELLOW}Got (minishell):${NC}"
        cat "$MINISHELL_OUT" | head -5 | sed 's/^/    /'
        
        if [ "$bash_exit" != "$minishell_exit" ]; then
            echo -e "  ${YELLOW}Exit codes differ:${NC} bash=$bash_exit, minishell=$minishell_exit"
        fi
        echo ""
        
        if [ "$STOP_ON_FAIL" = "1" ]; then
            echo -e "${RED}Stopping on first failure (--stop flag)${NC}"
            exit 1
        fi
        return 1
    fi
}

print_section() {
    echo ""
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
}

# Check if minishell exists
if [ ! -f "$MINISHELL" ]; then
    echo -e "${RED}Error: minishell not found at $MINISHELL${NC}"
    echo "Please compile your minishell first or update MINISHELL path"
    exit 1
fi

echo -e "${BLUE}╔════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║   MINISHELL AUTOMATED TEST SUITE      ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════╝${NC}"
echo ""
echo -e "Mode: ${CYAN}$CATEGORY${NC}"
if [ "$VERBOSE" = "1" ]; then echo -e "Verbose: ${CYAN}enabled${NC}"; fi
if [ "$FAST_MODE" = "1" ]; then echo -e "Fast mode: ${CYAN}enabled${NC}"; fi
if [ "$STOP_ON_FAIL" = "1" ]; then echo -e "Stop on fail: ${CYAN}enabled${NC}"; fi

# ============================================================================
# BASIC ECHO TESTS
# ============================================================================
print_section "Basic Echo Tests"

run_test "Simple echo" "echo hello" "echo"
run_test "Echo multiple words" "echo hello world" "echo"
run_test "Echo with double quotes" 'echo "hello world"' "echo"
run_test "Echo with single quotes" "echo 'hello world'" "echo"
run_test "Empty echo" "echo" "echo"
run_test "Echo empty double quotes" 'echo ""' "echo"
run_test "Echo empty single quotes" "echo ''" "echo"
run_test "Echo with tab" 'echo "hello	world"' "echo"

# ============================================================================
# ECHO WITH -n FLAG
# ============================================================================
print_section "Echo with -n Flag"

run_test "Echo -n basic" "echo -n hello" "echo"
run_test "Echo -n multiple words" "echo -n hello world" "echo"
run_test "Echo multiple -n flags" "echo -n -n -n hello" "echo"
run_test "Echo combined -n" "echo -nnnn hello" "echo"
run_test "Echo -n only" "echo -n" "echo"
run_test "Echo invalid flag -na" "echo -na hello" "echo"
run_test "Echo invalid flag -n-n" "echo -n-n hello" "echo"
run_test "Echo -n with quotes" 'echo -n "hello world"' "echo"

# ============================================================================
# VARIABLE EXPANSION
# ============================================================================
print_section "Variable Expansion"

run_test "Basic variable" 'export VAR=test; echo $VAR' "variables"
run_test "Variable in double quotes" 'export VAR=test; echo "$VAR"' "variables"
run_test "Variable in single quotes" "export VAR=test; echo '\$VAR'" "variables"
run_test "Multiple variables" 'export VAR=test; echo $VAR$VAR' "variables"
run_test "Undefined variable" 'unset UNDEF 2>/dev/null; echo $UNDEF' "variables"
run_test "Empty variable" 'export EMPTY=""; echo $EMPTY' "variables"
run_test "Variable with spaces" 'export SPACES="  hello  "; echo "$SPACES"' "variables"
run_test "Variable concatenation" 'export A=hello; export B=world; echo $A$B' "variables"

# ============================================================================
# EXPORT TESTS
# ============================================================================
print_section "Export Tests"

run_test "Simple export" 'export VAR=value; echo $VAR' "export"
run_test "Export with quotes" 'export VAR="hello world"; echo $VAR' "export"
run_test "Export overwrite" 'export VAR=first; export VAR=second; echo $VAR' "export"
run_test "Export empty" 'export VAR=; echo "[$VAR]"' "export"
run_test "Export with spaces in value" 'export VAR="   test   "; echo "$VAR"' "export"
run_test "Export special chars" 'export VAR="hello*world"; echo "$VAR"' "export"
run_test "Multiple exports" 'export A=1 B=2 C=3; echo $A $B $C' "export"

# ============================================================================
# MIXED QUOTES
# ============================================================================
print_section "Mixed Quotes"

run_test "Double then single" 'export V=x; echo "$V"'\''$V'\''' "variables"
run_test "Nested quotes" 'echo "outer '\''inner'\'' outer"' "echo"
run_test "Quote in variable" 'export V="'\''quoted'\''"; echo $V' "variables"

# ============================================================================
# WILDCARDS
# ============================================================================
print_section "Wildcards"

run_test "Asterisk literal in quotes" 'echo "*"' "wildcards"
run_test "Asterisk in single quotes" "echo '*'" "wildcards"
run_test "Pattern in double quotes" 'echo "*.txt"' "wildcards"
run_test "Question mark in quotes" 'echo "?"' "wildcards"

# ============================================================================
# EDGE CASES
# ============================================================================
print_section "Edge Cases"

run_test "Dollar sign alone" 'echo $' "variables"
run_test "Dollar in quotes" 'echo "$"' "variables"
run_test "Multiple spaces" "echo hello     world" "echo"
run_test "Multiple spaces quoted" 'echo "hello     world"' "echo"
run_test "Backslash" 'echo \hello' "echo"
run_test "Very long word" 'echo "$(printf '\''a%.0s'\'' {1..100})"' "echo" 1
run_test "Underscore variable" 'export _VAR=test; echo $_VAR' "variables"
run_test "Variable with numbers" 'export VAR123=test; echo $VAR123' "variables"

# ============================================================================
# COMPLEX SCENARIOS
# ============================================================================
print_section "Complex Scenarios"

run_test "Multiple commands" 'export A=hello && echo $A && export B=world && echo $B' "all"
run_test "Variable in command" 'export CMD=echo; export MSG=hello' "all"
run_test "Chained exports" 'export A=1 && export B=2 && echo $A $B' "all"

# ============================================================================
# SUMMARY
# ============================================================================
echo ""
echo -e "${BLUE}╔════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║           TEST SUMMARY                 ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════╝${NC}"
echo ""
echo -e "Total tests:  ${BLUE}$TOTAL_TESTS${NC}"
echo -e "Passed:       ${GREEN}$PASSED_TESTS${NC}"
echo -e "Failed:       ${RED}$FAILED_TESTS${NC}"

if [ $FAILED_TESTS -gt 0 ]; then
    echo ""
    echo -e "${YELLOW}Failed tests:${NC}"
    for i in "${!FAILED_TEST_NAMES[@]}"; do
        echo -e "  ${RED}$((i+1)).${NC} ${FAILED_TEST_NAMES[$i]}"
        echo -e "     ${CYAN}${FAILED_TEST_COMMANDS[$i]}${NC}"
    done
fi

echo ""

if [ $FAILED_TESTS -eq 0 ]; then
    echo -e "${GREEN}╔════════════════════════════════════════╗${NC}"
    echo -e "${GREEN}║     ALL TESTS PASSED! 🎉              ║${NC}"
    echo -e "${GREEN}╚════════════════════════════════════════╝${NC}"
    exit 0
else
    PERCENTAGE=$((PASSED_TESTS * 100 / TOTAL_TESTS))
    echo -e "${YELLOW}Success rate: $PERCENTAGE%${NC}"
    echo ""
    echo -e "${RED}Some tests failed. Review the output above.${NC}"
    echo -e "${CYAN}Tip: Run with -v for verbose output${NC}"
    exit 1
fi