#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../ft_strlcat.c"


int main(void) {
    // Test 1: Basic concat
    char    dst1[20] = "Hello, ";
    char    src1[] = "World!";
    size_t  result1 = ft_strlcat(dst1, src1, 20);
	printf("dst1: %s\n", dst1);
    assert(strcmp(dst1, "Hello, World!") == 0);
    assert(result1 == 13);
	printf("test 1 passed\n");
	printf("---------\n");

    // Test 2: Truncation
    char    dst2[10] = "Hello, ";
    char    src2[] = "World!";
    size_t  result2 = ft_strlcat(dst2, src2, 10);
    assert(strcmp(dst2, "Hello, Wo") == 0); // Truncated
    assert(result2 == 13);                  // Original length attempted
	printf("test 2 passed\n");
	printf("---------\n");

    // Test 3: Exact fit including NUL terminator
    char    dst3[14] = "Hello, ";
    char    src3[] = "World!";
    size_t  result3 = ft_strlcat(dst3, src3, 14);
    assert(strcmp(dst3, "Hello, World!") == 0);
    assert(result3 == 13);
	printf("test 3 passed\n");
	printf("---------\n");

    // Test 4: Zero size
    char    dst4[20] = "Hello";
    char    src4[] = "World";
    size_t  result4 = ft_strlcat(dst4, src4, 0);
    assert(strcmp(dst4, "Hello") == 0);
    assert(result4 == strlen(src4));
	printf("test 4 passed\n");
	printf("---------\n");

    // Test 5: Empty dst
    char    dst5[10] = "";
    char    src5[] = "abc";
    size_t  result5 = ft_strlcat(dst5, src5, 10);
    assert(strcmp(dst5, "abc") == 0);
    assert(result5 == 3);
	printf("test 5 passed\n");
	printf("---------\n");

    // Test 6: Empty source
    char    dst6[20] = "Carbon";
    char    src6[] = "";
    size_t  result6 = ft_strlcat(dst6, src6, 20);
    assert(strcmp(dst6, "Carbon") == 0);
    assert(result6 == 6);\
	printf("test 6 passed\n");
	printf("---------\n");

	// Test 7: libft test
	char	dst7[30];
	memset(dst7, 0, 30);
	dst7[0] = 'B';
	char 	*src7 = "AAAAAAAAA";
	size_t	result7 = ft_strlcat(dst7, src7, 0);
	assert(!strcmp(dst7, "B"));
	printf("test 7 passed\n");
	printf("---------\n");

	// Test 8: libft test
	char	dst8[30];
	memset(dst8, 0, 30);
	memset(dst8, 'B', 4);
	char	*src8 = "AAAAAAAAA";
	size_t	result8 = ft_strlcat(dst8, src8, 3);
	printf("dst is %s\n", dst8);
	assert(result8 == 3 + strlen(src8));
	assert(!strcmp(dst8, "BBBB"));
	printf("test 8 passed\n");
	printf("---------\n");

	// Test 9: libft test
	char	dst9[30];
	memset(dst9, 0, 30);
	char	*src9 = "AAAAAAAAA";
	memset(dst9, 'C', 5);
	size_t result9 = ft_strlcat(dst9, src9, -1);
	assert(result9 == 14);
	assert(!strcmp(dst9, "CCCCCAAAAAAAAA"));
	printf("test 9 passed\n");
	printf("---------\n");

	// Test 10: libft test
	char	dst10[30];
	memset(dst10, 0, 30);
	char	*src10 = "AAAAAAAAA";
	memset(dst10, '1', 10);
	size_t	result10 = ft_strlcat(dst10, src10, 5);
	char	dst10_ctrl[30];
	memset(dst10_ctrl, 0, 30);
	memset(dst10_ctrl, '1', 10);
	size_t	result10_ctrl = strlcat(dst10_ctrl, src10, 5);
	printf("dst10 is %s\n", dst10);
	printf("dst10_ctrl is %s\n", dst10_ctrl);
	assert(result10 == strlen(src10) + 5);
	assert(!strcmp(dst10, "1111111111"));
	printf("test 10 passed\n");
	printf("---------\n");
 
	// Test 11: libft test
	char	dst11[30];
	memset(dst11, 0, 30); 
	memset(dst11, '1', 10);
	char	*src11 = "AAAAAAAAA";
	size_t	result11 = ft_strlcat(dst11, src11, 5);
	assert(result11 == strlen(src11) + 5);
	assert(!strcmp(dst11, "1111111111"));

    printf("All tests passed!\n");
    return 0;
}
