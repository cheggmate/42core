#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_isalnum.c"

int main(void)
{
    // Test 1: Uppercase letter
    int	letter1 = 'A';
	int		result1;
	result1 = ft_isalnum(letter1);
	assert(result1 == 1);

	// Test 2: Lowercase letter
	int	letter2 = 'z';
	int		result2;
	result2 = ft_isalnum(letter2);
	assert(result2 == 1);

	// Test 3: Digit
	int	letter3 = '5';
	int		result3;
	result3 = ft_isalnum(letter3);
	assert(result3 == 1);

	// Test 4: Special Symbol
	int	letter4 = '@';
	int		result4;
	result4 = ft_isalnum(letter4);
	assert(result4 == 0);

	// Test 5: Space
	int	letter5 = ' ';
	int		result5;
	result5 = ft_isalnum(letter5);
	assert(result5 == 0);

	// Test 6: Newline
	int	letter6 = '\n';
	int		result6;
	result6 = ft_isalnum(letter6);
	assert(result6 == 0);

	// Test 7: Lower bound of digits
	int	letter7 = '0';
	int		result7;
	result7 = ft_isalnum(letter7);
	assert(result7 == 1);

	// Test 8: Upper bound of digits
	int	letter8 = '9';
	int		result8;
	result8 = ft_isalnum(letter8);
	assert(result8 == 1);

	// Test 9: Non-alphanumeric ASCII
	int	letter9 = 'a' - 1;
	int		result9;
	result9 = ft_isalnum(letter9);
	assert(result9 == 0);

    printf("All tests passed!\n");
    return 0;
}