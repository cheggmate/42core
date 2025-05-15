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
	printf("test 1 passed\n");
	printf("-------\n");

	// Test 2: Byte is not present
	char	data2[] = "abcdef";
	char	*result2;
	result2 = ft_memchr(data2, 'x', 6);
	assert(!result2);
	printf("test 2 passed\n");
	printf("-------\n");

	// Test 3: Search only part of array
	char	data3[] = "abcdef";
	char	*result3;
	result3 = ft_memchr(data3, 'e', 4);
	assert(!result3);
	printf("test 3 passed\n");
	printf("-------\n");

	// Test 4: Byte at the last position
	char	data4[] = "abcdef";
	char	*result4;
	result4 = ft_memchr(data4, 'f', 6);
	assert(memcmp(result4, &data4[5], 6) == 0);
	printf("test 4 passed\n");
	printf("-------\n");

	// Test 5: Searching for null byte
/* 	char	data5[] = {'A', 'B', '\0', 'C'};
	char	*result5;
	result5 = ft_memchr(data5, '\0', 4);
	assert(memcmp(result5, &data5[2], 4) == 0);
	printf("test 5 passed\n");
	printf("-------\n"); */

	// Test 6: Empty buffer (n = 0)
	char	data6[] = "test"; // can be anything
	char	*result6;
	result6 = ft_memchr(data6, 'a', 0);
	assert(!result6);
	printf("test 6 passed\n");
	printf("-------\n");

	// Test 7: Search a buffer with repeated values
	char	data7[] = {1, 2, 3, 2, 1};
	char	*result7;
	result7 = ft_memchr(data7, 2, 5);
	assert(memcmp(result7, &data7[1], 2) == 0);
	printf("test 7 passed\n");
	printf("-------\n");

	// Test 8: nums (Test from libft)
	char	data8[] = {0, 1, 2, 3, 4, 5};
	char	*result8;
	result8 = ft_memchr(data8, 0, 1);
	assert(memcmp(result8, &data8[0], 1) == 0);
	printf("test 8 passed\n");
	printf("-------\n");

	// Test 9: check cast (Test from libft)
	char	data9[] = {0, 1, 2, 3, 4, 5};
	char	*result9;
	result9 = ft_memchr(data9, 2+256, 3);
	assert(memcmp(result9, &data9[2], 1) == 0);
	
	printf("all tests passed.\n");
    //printf("All tests passed!\n");
    return 0;
}