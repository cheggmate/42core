#include <stdio.h>
#include <assert.h>
#include "../ft_isprint.c"

int main(void)
{
    // Test 1: Uppercase letter
	int	input1 = 'A';
	int	result1;
	result1 = ft_isprint(input1);
	assert(result1 == 1);

	// Test 2: Lowercase letter
	int	input2 = '5';
	int	result2;
	result2 = ft_isprint(input2);
	assert(result2 == 1);

	// Test 3: Digit
	int	input3 = '0';
	int	result3;
	result3 = ft_isprint(input3);
	assert(result3 == 1);

	// Test 4: Space
	int	input4 = ' ';
	int	result4;
	result4 = ft_isprint(input4);
	assert(result4 == 1);

	// Test 5: Last printable character
	int	input5 = '~';
	int	result5;
	result5 = ft_isprint(input5);
	assert(result5 == 1);

	// Test 6: Newline
	int	input6 = '\n';
	int	result6;
	result6 = ft_isprint(input6);
	assert(result6 == 0);

	// Test 7: Tab
	int	input7 = '\t';
	int	result7;
	result7 = ft_isprint(input7);
	assert(result7 == 0);

	// Test 8: DEL
	int	input8 = 127;
	int	result8;
	result8 = ft_isprint(input8);
	assert(result8 == 0);

	// Test 9: Control character
	int	input9 = 31;
	int	result9;
	result9 = ft_isprint(input9);
	assert(result9 == 0);
    
    printf("All tests passed!\n");
    return 0;
}