#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_strlen.c"

int main(void)
{
    // Test 1: Empty string
	char	str1[] = "";
	int		len1 = ft_strlen(str1);
	assert(len1 == 0);

	// Test 2: Single character string
	char	str2[] = "a";
	int		len2 = ft_strlen(str2);
	assert(len2 == 1);

	// Test 3: Simple word
	char	str3[] = "hello";
	int		len3 = ft_strlen(str3);
	assert(len3 == 5);

	// Test 4: String with spaces
	char	str4[] = "hello world";
	int		len4 = ft_strlen(str4);
	assert(len4 == 11);

	// Test 5: String with special charcters
	char	str5[] = "abs123!@#";
	int		len5 = ft_strlen(str5);
	assert(len5 == 9);

	// Test 6: Numeric string
	char	str6[] = "1234567890";
	int		len6 = ft_strlen(str6);
	assert(len6 == 10);
    
    printf("All tests passed!\n");
    return 0;
}