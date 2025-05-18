#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_strtrim.c"

int main(void)
{
    // Test 1: Basic functionality - space
	char	str1[] = " hello  ";
	char	rm1[] = " ";
	char	expected1[] = "hello";
	char	*result1 = ft_strtrim(str1, rm1);
	printf("result1 is %s\n", result1);
	if (!result1)
		printf("result1 is null\n");
	else
		assert(strcmp(result1, expected1) == 0);
	printf("test 1 passed\n");
	free(result1);

	// Test 2: Basic functionality - char
	char	str2[] = "xxhelloxx";
	char	rm2[] = "x";
	char	expected2[] = "hello";
	char	*result2 = ft_strtrim(str2, rm2);
	if (!result2)
		printf("result2 is null\n");
	else
		assert(strcmp(result2, expected2) == 0);
	printf("test 2 passed\n");
	free(result2);

	// Test 3: Basic functionality - dots
	char	str3[] = ".hellox.";
	char	rm3[] = ".";
	char	expected3[] = "hellox";
	char	*result3 = ft_strtrim(str3, rm3);
	if (!result3)
		printf("result3 is null\n");
	else
		assert(strcmp(result3, expected3) == 0);
	printf("test 3 passed\n");
	free(result3);

	// Test 4: Trimming multiple chars
	char	str4[] = " \t\nhello\t \n";
	char	rm4[] = " \n\t";
	char	expected4[] = "hello";
	char	*result4 = ft_strtrim(str4, rm4);
	if (!result4)
		printf("result4 is null\n");
	else
		assert(strcmp(result4, expected4) == 0);
	printf("test 4 passed\n");
	free(result4);

	// Test 5: No characters to trim
	char	str5[] = "hello";
	char	rm5[] = "";
	char	expected5[] = "hello";
	char	*result5 = ft_strtrim(str5, rm5);
	if (!result5)
		printf("result5 is null\n");
	else
		assert(strcmp(result5, expected5) == 0);
	printf("test 5 passed\n");
	free(result5);

	// Test 6: No trimmable characters present
	char	str6[] = " \t\nhello\t \n";
	char	rm6[] = "xy.";
	char	expected6[] = " \t\nhello\t \n";
	char	*result6 = ft_strtrim(str6, rm6);
	if (!result6)
		printf("result6 is null\n");
	else
		assert(strcmp(result6, expected6) == 0);
	printf("test 6 passed\n");
	free(result6);

	// Test 7: All characters are in the set
	char	str7[] = "xxxxxy";
	char	rm7[] = " xy";
	char	expected7[] = "";
	char	*result7 = ft_strtrim(str7, rm7);
	if (!result7)
		printf("result7 is null\n");
	else
		assert(strcmp(result7, expected7) == 0);
	printf("test 7 passed\n");
	free(result7);

	// Test 8: Empty string inputs
	char	str8[] = "";
	char	rm8[] = "";
	char	expected8[] = "";
	char	*result8 = ft_strtrim(str8, rm8);
	if (!result8)
		printf("result8 is null\n");
	else
		assert(strcmp(result8, expected8) == 0);
	printf("test 8 passed\n");
	free(result8);

	// Test 9: Null inputs
	char	str9[] = "";
	char	rm9[] = "";
	char	expected9[] = "";
	char	*result9 = ft_strtrim(str9, rm9);
	if (!result9)
		printf("result8 is null\n");
	else
		assert(strcmp(result9, expected9) == 0);
	printf("test 9 passed\n");
	free(result9);

    
    printf("All tests passed!\n");
    return 0;
}