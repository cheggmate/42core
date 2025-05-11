#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_strchr.c"

int main(void)
{
    // Test 1: match at the beginning
	int		input1 = 'a';
	char	search1[] = "apple";
	char	*result1 = ft_strchr(search1, input1);
	assert(memcmp(result1, &search1[0], 5) == 0);

	// Test 2: match at the middle
	int		input2 = 'l';
	char	search2[] = "hello";
	char	*result2 = ft_strchr(search2, input2);
	assert(memcmp(result2, &search2[2], 5) == 0);

	// Test 3: match at the end
	int		input3 = 'o';
	char	search3[] = "hello";
	char	*result3 = ft_strchr(search3, input3);
	assert(memcmp(result3, &search3[4], 5) == 0);

	// Test 4: character not in the string
	int		input4 = 'x';
	char	search4[] = "hello";
	char	*result4 = ft_strchr(search4, input4);
	assert(!result4);

	// Test 5:  null terminator
	int		input5 = '\0';
	char	search5[] = "hello";
	char	*result5 = ft_strchr(search5, input5);
	assert(memcmp(result5, &search5[6], 5) == 0);

	// Test 6: repeated character
	int		input6 = 'a';
	char	search6[] = "banana";
	char	*result6 = ft_strchr(search6, input6);
	assert(memcmp(result6, &search6[1], 6) == 0);

	// Test 7: Case sensitive search
	int		input7 = 'b';
	char	search7[] = "Banana";
	char	*result7 = ft_strchr(search7, input7);
	assert(!result7);

	// Test 8: Empty string
	int		input8 = 'a';
	char	search8[] = "";
	char	*result8 = ft_strchr(search8, input8);
	assert(!result8);

	// Test 9: Search for digit
	int		input9 = '1';
	char	search9[] = "abc123";
	char	*result9 = ft_strchr(search9, input9);
	assert(memcmp(result9, &search9[3], 6) == 0);

	// Test 10: Special character
	int		input10 = '!';
	char	search10[] = "C is fun!";
	char	*result10 = ft_strchr(search10, input10);
	assert(memcmp(result10, &search10[8], 9) == 0);
    
    printf("All tests passed!\n");
    return 0;
}