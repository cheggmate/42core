#include <stdio.h>
#include <assert.h>
#include "../ft_memcmp.c"

int main(void)
{
    // Test 1: Equal strings
	char	str1a[] = "abc";
	char	str1b[] = "abc";
	int		result1 = ft_memcmp(str1a, str1b, 3);
	assert(result1 == 0);

	// Test 2: Different strings, same length
	char	str2a[] = "abc";
	char	str2b[] = "abd";
	int		result2 = ft_memcmp(str2a, str2b, 3);
	assert(result2 < 0);

	// Test 3: First is greater
	char	str3a[] = "abd";
	char	str3b[] = "abc";
	int		result3 = ft_memcmp(str3a, str3b, 3);
	assert(result3 > 0);

	// Test 4: n < the length of the string
	char	str4a[] = "abcdef";
	char	str4b[] = "abcxyz";
	int		result4 = ft_memcmp(str4a, str4b, 3);
	assert(result4 == 0);

	// Test 5: n is 0
	char	str5a[] = "abc";
	char	str5b[] = "xyz";
	int		result5 = ft_memcmp(str5a, str5b, 0);
	assert(result5 == 0);

	// Test 6: Empty strings
	char	str6a[] = "";
	char	str6b[] = "";
	int		result6 = ft_memcmp(str6a, str6b, 0);
	assert(result6 == 0);

	// Test 7: Binary data
	unsigned char	str7a[] = {0x00, 0x01, 0x02};
	unsigned char	str7b[] = {0x00, 0x01, 0x03};
	int				result7 = ft_memcmp(str7a, str7b, 3);
	assert(result7 < 0);

	// Test 8: Non-null terminated memory
	char	str8a[] = {'a', 'b', 'c'};
	char	str8b[] = {'a', 'b', 'c'};
	int		result8 = ft_memcmp(str8a, str8b, 3);
	assert(result8 == 0);

	// Test 9: Case sensitivity
	char	str9a[] = "abc";
	char	str9b[] = "ABC";
	int		result9 = ft_memcmp(str9a, str9b, 3);
	assert(result9 > 0);

	// Test 10: Longer strings with match in first n
	char	str10a[] = "abc123";
	char	str10b[] = "abcXYZ";
	int		result10 = ft_memcmp(str10a, str10b, 3);
	assert(result10 == 0);
    
    printf("All tests passed!\n");
    return 0;
}