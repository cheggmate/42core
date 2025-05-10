#include <stdio.h>
#include <assert.h>
#include "../ft_isdigit.c"

int main(void)
{
    // Test 1: Lower bound of digits
	int	digit1 = '0';
	int	result1;
	result1 = ft_isdigit(digit1);
	assert(result1 == 1);

	// Test 2: Mid range digit
	int	digit2 = '5';
	int	result2;
	result2 = ft_isdigit(digit2);
	assert(result2 == 1);

	// Test 3: Upper bound of digits
	int	digit3 = '9';
	int	result3;
	result3 = ft_isdigit(digit3);
	assert(result3 == 1);

	// Test 4: Lowercacse letter
	int	digit4 = 'a';
	int	result4;
	result4 = ft_isdigit(digit4);
	assert(result4 == 0);

	// Test 5: Uppercase letter
	int	digit5 = 'A';
	int	result5;
	result5 = ft_isdigit(digit5);
	assert(result5 == 0);

	// Test 6: Special character
	int	digit6 = '-';
	int	result6;
	result6 = ft_isdigit(digit6);
	assert(result6 == 0);

	// Test 7: Space
	int	digit7 = ' ';
	int	result7;
	result7 = ft_isdigit(digit7);
	assert(result7 == 0);

	// Test 8: Newline
	int	digit8 = '\n';
	int	result8;
	result8 = ft_isdigit(digit8);
	assert(result8 == 0);

	// Test 9 Outside ASCII Range
	int	digit9 = 128;
	int	result9;
	result9 = ft_isdigit(digit9);
	assert(result9 == 0);

    printf("All tests passed!\n");
    return 0;
}