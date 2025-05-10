#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_strncmp.c"

int main(void)
{
    // Test 1: Equal strings
	const char		str1_a[] = "abc";
	const char		str1_b[] = "abc";
	unsigned int	len1 = 3;
	int				result1 = ft_strncmp(str1_a, str1_b, len1);
	assert(result1 == 0);

	// Test 2: Partial match
	const char		str2_a[] = "abcdef";
	const char		str2_b[] = "abcxyz";
	unsigned int	len2 = 3;
	int				result2 = ft_strncmp(str2_a, str2_b, len2);
	assert(result2 == 0);

	// Test 3: First less than second
	const char		str3_a[] = "abc";
	const char		str3_b[] = "abd";
	unsigned int	len3 = 3;
	int				result3 = ft_strncmp(str3_a, str3_b, len3);
	assert(result3 < 0);

	// Test 4: First greater than second
	const char		str4_a[] = "abe";
	const char		str4_b[] = "abd";
	unsigned int	len4 = 3;
	int				result4 = ft_strncmp(str4_a, str4_b, len4);
	assert(result4 > 0);

	// Test 5: Different lengths, n smaller
	const char		str5_a[] = "abc";
	const char		str5_b[] = "abcd";
	unsigned int	len5 = 3;
	int				result5 = ft_strncmp(str5_a, str5_b, len5);
	assert(result5 == 0);

	// Test 6: Different lengths, n larger
	const char		str6_a[] = "abc";
	const char		str6_b[] = "abcd";
	unsigned int	len6 = 4;
	int				result6 = ft_strncmp(str6_a, str6_b, len6);
	assert(result6 < 0);

	// Test 7: Case-sensitive difference
	const char		str7_a[] = "Abc";
	const char		str7_b[] = "abc";
	unsigned int	len7 = 3;
	int				result7 = ft_strncmp(str7_a, str7_b, len7);
	assert(result7 < 0);

	// Test 8: n = 0
	const char		str8_a[] = "abc";
	const char		str8_b[] = "xyz";
	unsigned int	len8 = 0;
	int				result8 = ft_strncmp(str8_a, str8_b, len8);
	assert(result8 == 0);

	// Test 9: One string is empty
	const char		str9_a[] = "";
	const char		str9_b[] = "abc";
	unsigned int	len9 = 3;
	int				result9 = ft_strncmp(str9_a, str9_b, len9);
	assert(result9 < 0);

	// Test 10: Both strings are empty
	const char		str10_a[] = "";
	const char		str10_b[] = "";
	unsigned int	len10 = 5;
	int				result10 = ft_strncmp(str10_a, str10_b, len10);
	assert(result10 == 0);

	// Test 11: Early mismatch
	const char		str11_a[] = "abcxyz";
	const char		str11_b[] = "abcyyz";
	unsigned int	len11 = 6;
	int				result11 = ft_strncmp(str11_a, str11_b, len11);
	assert(result11 < 0);

	// Test 12: Null-terminator within range
	const char		str12_a[] = "abc";
	const char		str12_b[] = "abc\0x";
	unsigned int	len12 = 5;
	int				result12 = ft_strncmp(str12_a, str12_b, len12);
	assert(result12 == 0);
    
    printf("All tests passed!\n");
    return 0;
}