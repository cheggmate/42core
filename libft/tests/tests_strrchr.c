#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_strrchr.c"

int main(void)
{
        // Test 1: match at the beginning
	int		input1 = 'a';
	char	search1[] = "apple";
	char	*result1 = ft_strrchr(search1, input1);
	printf("result1 is pointing to %c\n", *result1);
	assert(result1 == &search1[0]);
	printf("first test passed!\n");

	// Test 2: match at the middle
	int		input2 = 'l';
	char	search2[] = "hello";
	char	*result2 = ft_strrchr(search2, input2);
	assert(result2 == &search2[3]);
	printf("second test passed!\n");

	// Test 3: match at the end
	int		input3 = '!';
	char	search3[] = "hello!";
	char	*result3 = ft_strrchr(search3, input3);
	assert(result3 == &search3[5]);
	printf("third test passed!\n");

	// Test 4: character not in the string
	int		input4 = 'x';
	char	search4[] = "hello";
	char	*result4 = ft_strrchr(search4, input4);
	assert(result4 == NULL);
	printf("fourth test passed!\n");

	// Test 5:  null terminator
	int		input5 = '\0';
	char	search5[] = "hello";
	char	*result5 = ft_strrchr(search5, input5);
	assert(result5 == &search5[6]);
	printf("fifth test passed!\n");

	// Test 6: repeated character
	int		input6 = 'a';
	char	search6[] = "banana";
	char	*result6 = ft_strrchr(search6, input6);
	assert(result6 == &search6[5]);
	printf("sixth test passed!\n");

	// Test 7: Case sensitive search
	int		input7 = 'b';
	char	search7[] = "Banana";
	char	*result7 = ft_strrchr(search7, input7);
	assert(result7 == NULL);
	printf("seventh test passed!\n");

	// Test 8: Empty string
	int		input8 = 'a';
	char	search8[] = "";
	char	*result8 = ft_strrchr(search8, input8);
	assert(result8 == NULL);
	printf("eight test passed!\n");

	// Test 9: Search for digit
	int		input9 = '1';
	char	search9[] = "abc123";
	char	*result9 = ft_strrchr(search9, input9);
	assert(result9 == &search9[3]);
	printf("ninth test passed!\n");

	// Test 10: Special character
	int		input10 = '!';
	char	search10[] = "C is fun!";
	char	*result10 = ft_strrchr(search10, input10);
	assert(result10 == &search10[8]);
	printf("tenth test passed!\n");
    
    printf("All tests passed!\n");
    return 0;
}