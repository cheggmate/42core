#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_toupper.c"

int main(void)
{
    // Test 1: Early lowercase letter 1
	int	letter1 = 'a';
	int	result1 = ft_toupper(letter1);
	assert(result1 == 'A');

	// Test 2: Late lowercase letter
	int	letter2 = 'z';
	int	result2 = ft_toupper(letter2);
	assert(result2 == 'Z');

	// Test 3: Middle lowercase letter
	int	letter3 = 'm';
	int	result3 = ft_toupper(letter3);
	assert(result3 == 'M');

	// Test 4: Already uppercase (early character)
	int	letter4 = 'A';
	int	result4 = ft_toupper(letter4);
	assert(result4 == 'A');

	// Test 5: Already uppercase (late character)
	int	letter5 = 'Z';
	int	result5 = ft_toupper(letter5);
	assert(result5 == 'Z');

	// Test 6: Digit
	int	letter6 = '0';
	int	result6 = ft_toupper(letter6);
	assert(result6 == '0');

	// Test 7: Special character
	int	letter7 = '!';
	int	result7 = ft_toupper(letter7);
	assert(result7 == '!');

	// Test 8: Space
	int	letter8 = ' ';
	int	result8 = ft_toupper(letter8);
	assert(result8 == ' ');

	// Test 9: Newline
	int	letter9 = '\n';
	int	result9 = ft_toupper(letter9);
	assert(result9 == '\n');
    
    printf("All tests passed!\n");
    return 0;
}