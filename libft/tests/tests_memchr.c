#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include "../ft_memchr.c"

int main(void)
{
    // Test 1: Byte is present
	char	data1[] = "abcdef";
	char	*result1 = ft_memchr(data1, 'c', 6);
	int		result1_val = *result1;
	printf("pointer is pointing to %c\n", result1_val);
	assert(*result1 ==  'c' - '0');
/* 
	// Test 2: Byte is not present
	char	data2[] = "abcdef";
	void	*result2;
	result2 = ft_memchr(data2, 'x', 6);
	assert(*result2);

	// Test 3: Digit
	char	data3 = '0';
	void	*result3;
	result3 = ft_memchr(data3);
	assert(result3 == 1);

	// Test 4: Space
	char	data4 = ' ';
	void	*result4;
	result4 = ft_memchr(data4);
	assert(result4 == 1);

	// Test 5: Last printable character
	char	data5 = '~';
	void	*result5;
	result5 = ft_memchr(data5);
	assert(result5 == 1);

	// Test 6: Newline
	char	data6 = '\n';
	void	*result6;
	result6 = ft_memchr(data6);
	assert(result6 == 0);

	// Test 7: Tab
	char	data7 = '\t';
	void	*result7;
	result7 = ft_memchr(data7);
	assert(result7 == 0);

	// Test 8: DEL
	char	data8 = 127;
	void	*result8;
	result8 = ft_memchr(data8);
	assert(result8 == 0);

	// Test 9: Control character
	char	data9 = 31;
	void	*result9;
	result9 = ft_memchr(data9);
	assert(result9 == 0); */
    
	printf("testing incomplete\n");
    //printf("All tests passed!\n");
    return 0;
}