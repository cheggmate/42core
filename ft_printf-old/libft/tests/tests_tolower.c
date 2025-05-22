#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_tolower.c"

int main(void)
{
    // Test 1: Already lowercase letter (early char)
	int	letter1 = 'a';
	int	result1 = ft_tolower(letter1);
	assert(result1 == 'a');

	// Test 2: Already lowercase letter (late char)
	int	letter2 = 'z';
	int	result2 = ft_tolower(letter2);
	assert(result2 == 'z');

	// Test 3: Already lowercase letter (middle char)
	int	letter3 = 'm';
	int	result3 = ft_tolower(letter3);
	assert(result3 == 'm');

	// Test 4: Early uppercase letter
	int	letter4 = 'A';
	int	result4 = ft_tolower(letter4);
	assert(result4 == 'a');

	// Test 5: Late uppercase letter
	int	letter5 = 'Z';
	int	result5 = ft_tolower(letter5);
	assert(result5 == 'z');

	// Test 6: Digit
	int	letter6 = '0';
	int	result6 = ft_tolower(letter6);
	assert(result6 == '0');

	// Test 7: Special character
	int	letter7 = '!';
	int	result7 = ft_tolower(letter7);
	assert(result7 == '!');

	// Test 8: Space
	int	letter8 = ' ';
	int	result8 = ft_tolower(letter8);
	assert(result8 == ' ');

	// Test 9: Newline
	int	letter9 = '\n';
	int	result9 = ft_tolower(letter9);
	assert(result9 == '\n');
    
    printf("All tests passed!\n");
    return 0;
}