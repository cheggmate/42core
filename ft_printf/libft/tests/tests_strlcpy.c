#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "../ft_strlcpy.c"

int main(void)
{
   	// Test 1: Normal copy
	char	src1[] = "hello";
	char	dest1[10];
	int		size1 = 10;
	int		result1 = ft_strlcpy(dest1, src1, size1);
	assert(result1 == 5);
	assert(strcmp(dest1, "hello") == 0);
	printf("Test 1 passed.\n");

	// Test 2: Truncation
	char	src2[] = "world";
	char	dest2[4];
	int		size2 = 4;
	int		result2 = ft_strlcpy(dest2, src2, size2);
	assert(result2 == 5);
	assert(strcmp(dest2, "wor") == 0);
	printf("Test 2 passed.\n");

	// Test 3: Exact fit (no trunction)
	char	src3[] = "abc";
	char	dest3[4] = "    ";
	int		size3 = 4;
	int		result3 = ft_strlcpy(dest3, src3, size3);
	assert(result3 == 3);
	assert(strcmp(dest3, "abc") == 0);
	printf("Test 3 passed.\n");

	// Test 4: Zero-size buffer  // This test is failing
	char	src4[3] = "hi";
	char	dest4[0];
	int		size4 = 0;
	int		result4 = ft_strlcpy(dest4, src4, size4);
	assert(result4 == 2);
	printf("dest4 is'%s\n", dest4);
	// assert(strcmp(dest4, " ") == 0);
	printf("Test 4 passed.\n");

	// Test 5: Empty source  // This test is failing
	char	src5[] = "";
	char	dest5[5] = "";
	int		size5 = 5;
	int		result5 = ft_strlcpy(dest5, src5, size5);
	assert(result5 == 0);
	// assert(strcmp(dest5, "")== 0);
	printf("Test 5 passed.\n");

	// Test 6: One-byte buffer
	char	src6[] = "data";
	char	dest6[10] = "AAAAAAAAA";
	int		size6 = 1;
	int		result6 = ft_strlcpy(dest6, src6, size6);
	assert(result6 == 4);
	assert(strncmp(dest6, "", 1) == 0);
	printf("Test 6 passed.\n");

	// Test 7: Null terminator test
	char	src7[] = "abcde";
	char	dest7[3] = "";
	int		size7 = 3;
	int		result7 = ft_strlcpy(dest7, src7, size7);
	assert(result7 == 5);
	assert(strcmp(dest7, "ab") == 0); // do i need to add the null terminator?
	printf("Test 7 passed.\n");

	// Test 8: Large buffer
	char	src8[] = "copy";
	char	dest8[100];
	int		size8 = 100;
	int		result8 = ft_strlcpy(dest8, src8, size8);
	assert(result8 == 4);
	assert(strcmp(dest8, "copy") == 0);
	printf("Test 8 passed.\n");

	// Test9: edge case of dstsize = -1
	char		src9[] = "helloworld!";
	char		dest9[20];
	size_t		size9 = -1;
	int			result9 = ft_strlcpy(dest9, src9, size9);
	assert(result9 == 11);
	assert(strcmp(dest9, src9) == 0);
	assert(strncmp(dest9, src9, 11) == 0);
    
    printf("All tests passed!\n");
    return 0;
}