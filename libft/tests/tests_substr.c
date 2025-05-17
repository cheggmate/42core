#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>
#include "../ft_substr.c"

int main(void)
{
    // Test 1: Basic functionality - start of str
    char			str1[] = "hello world";
    unsigned int	start1 = 0;
	size_t			len1 = 5;
	char			expected1[] = "hello";
	char			*sub1 = ft_substr(str1, start1, len1);
	if (!sub1)
		printf("sub1 is null\n");
	else
		assert(strcmp(sub1, expected1) == 0);
	free(sub1);
	printf("test 1 passed\n");

	// Test 2: Basic funct - mid of str
	char			str2[] = "hello world";
	unsigned int	start2 = 6;
	size_t			len2 = 5;
	char			expected2[] = "world";
	char			*sub2 = ft_substr(str2, start2, len2);
	printf("substr is %s\n", sub2);
	if (!sub2)
		printf("sub2 is null\n");
	else
		assert(strcmp(sub2, expected2) == 0);
	free(sub2);
	printf("test 2 passed\n");

	// Test 3: Start at the end of string
	char			str3[] = "abc";
	unsigned int	start3 = 3;
	size_t			len3 = 2;
	char			expected3[] = "";
	char			*sub3 = ft_substr(str3, start3, len3);
	if (!sub3)
		printf("sub3 is null\n");
	else
		assert(strcmp(sub3, expected3) == 0);
	free(sub3);
	printf("test 3 passed\n");

	// Test 4: Length longer than the remaining string
	char			str4[] = "abc";
	unsigned int	start4 = 1;
	size_t			len4 = 10;
	char			expected4[] = "bc";
	char			*sub4 = ft_substr(str4, start4, len4);
	if (!sub4)
		printf("sub4 is null\n");
	else
		assert(strcmp(sub4, expected4) == 0);
	free(sub4);
	printf("test 4 passed\n");

	// Test 5: Negative start index - invalid test case
	// char			str5[] = "abcdef";
	// unsigned int	start5 = 2;
	// size_t			len5 = -1;
	// char			expected5[] = "";
	// char			*sub5 = ft_substr(str5, start5, len5);
	// if (!sub5)
	// 	printf("sub5 is null\n");
	// else
	// 	assert(strcmp(sub5, expected5) == 0);
	// free(sub5);
	// printf("test 5 passed\n");

	// Test 6: Zero length
	char			str6[] = "abcdef";
	unsigned int	start6 = 2;
	size_t			len6 = 0;
	char			expected6[] = "";
	char			*sub6 = ft_substr(str6, start6, len6);
	if (!sub6)
		printf("sub6 is null\n");
	else
		assert(strcmp(sub6, expected6) == 0);
	free(sub6);
	printf("test 6 passed\n");

	// Test 7: Empty string input
	char			str7[] = "";
	unsigned int	start7 = 0;
	size_t			len7 = 5;
	char			expected7[] = "";
	char			*sub7 = ft_substr(str7, start7, len7);
	if (!sub7)
		printf("sub7 is null\n");
	else
		assert(strcmp(sub7, expected7) == 0);
	free(sub7);
	printf("test 7 passed\n");

	// Test 8: Start index out of bounds
	char			str8[] = "abc";
	unsigned int	start8 = 10;
	size_t			len8 = 2;
	char			expected8[] = "";
	char			*sub8 = ft_substr(str8, start8, len8);
	if (!sub8)
		printf("sub8 is null\n");
	else
		assert(strcmp(sub8, expected8) == 0);
	free(sub8);
	printf("test 8 passed\n");

	// Test 9: unicode characters
	char			str9[] = "#$@@!";
	unsigned int	start9 = 0;
	size_t			len9 = 2;
	char			expected9[] = "#$";
	char			*sub9 = ft_substr(str9, start9, len9);
	// printf("sub9 is %s.\n", sub9);
	if (!sub9)
		printf("sub9 is null\n");
	else
		assert(strcmp(sub9, expected9) == 0);
	free(sub9);

	// Test 10: libft test
	char			str10[] = "tripouille";
	unsigned int	start10 = 0;
	size_t			len10 = 42000;
	char			expected10[] = "tripouille";
	char			*sub10 = ft_substr(str10, start10, len10);
	if (!sub10)
		printf("sub10 is null\n");
	else
		assert(!strcmp(sub10, expected10));
	free(sub10);

    printf("All tests passed!\n");
    return 0;
}