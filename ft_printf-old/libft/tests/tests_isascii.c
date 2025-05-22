#include <stdio.h>
#include <assert.h>
#include "../ft_isascii.c"

int main(void)
{
    // Test 1: Uppercase ASCII Letter
	int	letter1 = 'A';
	int	result1;
	result1 = ft_isascii(letter1);
	assert(result1 == 1);

	// Test 2: Lowercae ASCII Letter
	int	letter2 = 'Z';
	int	result2;
	result2 = ft_isascii(letter2);
	assert(result2 == 1);

	// Test 3: ASCII Digit
	int	letter3 = '0';
	int	result3;
	result3 = ft_isascii(letter3);
	assert(result3 == 1);

	// Test 4: Last printable ASCII Character
	int	letter4 = '~';
	int	result4;
	result4 = ft_isascii(letter4);
	assert(result4 == 1);

	// Test 5: Newline
	int	letter5 = '\n';
	int	result5;
	result5 = ft_isascii(letter5);
	assert(result5 == 1);

	// Test 6: Null byte
	int	letter6 = 0;
	int	result6;
	result6 = ft_isascii(letter6);
	assert(result6 == 1);

	// Test 7: Last ASCII char (DEL)
	int	letter7 = 127;
	int	result7;
	result7 = ft_isascii(letter7);
	assert(result7 == 1);

	// Test 8: Just outside ASCII Range
	int	letter8 = 128;
	int	result8;
	result8 = ft_isascii(letter8);
	assert(result8 == 0);

	// Test 9: Negative value
	int	letter9 = -1;
	int	result9;
	result9 = ft_isascii(letter9);
	assert(result9 == 0);
    
    printf("All tests passed!\n");
    return 0;
}