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
	assert(*result1 ==  'c');
	assert(memcmp(result1, &data1[2], 6) == 0);

	// Test 2: Byte is not present
	char	data2[] = "abcdef";
	char	*result2;
	result2 = ft_memchr(data2, 'x', 6);
	assert(!result2);

	// Test 3: Search only part of array
	char	data3[] = "abcdef";
	char	*result3;
	result3 = ft_memchr(data3, 'e', 4);
	assert(!result3);

	// Test 4: Byte at the last position
	char	data4[] = "abcdef";
	char	*result4;
	result4 = ft_memchr(data4, 'f', 6);
	assert(memcmp(result4, &data4[5], 6) == 0);

	// Test 5: Searching for null byte
	char	data5[] = {'A', 'B', '\0', 'C'};
	char	*result5;
	result5 = ft_memchr(data5, '\0', 4);
	assert(memcmp(result5, &data5[2], 4) == 0);

	// Test 6: Empty buffer (n = 0)
	char	data6[] = "test"; // can be anything
	char	*result6;
	result6 = ft_memchr(data6, 'a', 0);
	assert(!result6);

	// Test 7: Search a buffer with repeated values
	char	data7[] = {1, 2, 3, 2, 1};
	char	*result7;
	result7 = ft_memchr(data7, 2, 5);
	assert(memcmp(result7, &data7[1], 5) == 0);

	printf("all tests passed.\n");
    //printf("All tests passed!\n");
    return 0;
}