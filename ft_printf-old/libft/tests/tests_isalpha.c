#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_isalpha.c"

int main(void)
{
    // Test 1: Uppercase letter
	int	letter1 = 'A';
	int	result1;
	result1 = ft_isalpha(letter1);
	assert(result1 == 1);

	// Test 2: Uppercase letter
	int	letter2 = 'Z';
	int	result2;
	result2 = ft_isalpha(letter2);
	assert(result2 == 1);

	// Test 3: Lowercase letter
	int	letter3 = 'a';
	int	result3;
	result3 = ft_isalpha(letter3);
	assert(result3 == 1);

	// Test 4: Lowercase letter
	int	letter4 = 'z';
	int	result4;
	result4 = ft_isalpha(letter4);
	assert(result4 == 1);

	// Test 5: Middle uppercase
	int	letter5 = 'M';
	int	result5;
	result5 = ft_isalpha(letter5);
	assert(result5 == 1);

	// Test 6: Middle lowercase
	int	letter6 = 'm';
	int	result6;
	result6 = ft_isalpha(letter6);
	assert(result6 == 1);

	// Test 7: Digit
	int	letter7 = '0';
	int	result7;
	result7 = ft_isalpha(letter7);
	assert(result7 == 0);

	// Test 8: Special character
	int	letter8 = '@';
	int	result8;
	result8 = ft_isalpha(letter8);
	assert(result8 == 0);

	// Test 9: Space
	int	letter9 = ' ';
	int	result9;
	result9 = ft_isalpha(letter9);
	assert(result9 == 0);

	// Test 10: Newline
	int	letter10 = '\n';
	int	result10;
	result10 = ft_isalpha(letter10);
	assert(result10 == 0);
    
    printf("All tests passed!\n");
    return 0;
}