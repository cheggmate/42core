#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_memmove.c"

int main(void)
{
    // Test 1: Non overlapping copy
	char	src1[] = "ABCDEFG";
	char	dest1[10] = "";
	unsigned int	len1 = 4;
	ft_memmove(dest1, src1, len1);
	assert(strcmp(dest1, "ABCD") == 0);
	// printf("test 1 passed\n");

	// Test 2: Overlapping: dest before src - shiftleft
	char	src2[] = "123456789";
	unsigned int	len2 = 5;
	ft_memmove(src2, src2 + 2, len2);
	assert(strcmp(src2, "345676789") == 0);
	// printf("test 2 passed\n");

	// Test 3: Overlapping: src before dest - shiftright
	char	src3[] = "abcdef";
	unsigned int	len3 = 4;
	ft_memmove(src3 + 2, src3, len3);
	assert(strcmp(src3, "ababcd") == 0);
	// printf("test 3 passed\n");

	// Test 4: Zero length move
	char	src4[] = "test";
	char	dest4[10] = "";
	unsigned int	len4 = 0;
	ft_memmove(dest4, src4, len4);
	assert(strcmp(dest4, "") == 0);
	// printf("test 4 passed\n");

	// Test 5: Full array copy
	char	src5[] = "data";
	char	dest5[10] = "          ";
	unsigned int	len5 = 5;
	ft_memmove(dest5, src5, len5);
	assert(strcmp(dest5, "data") == 0);
	// printf("test 5 passed\n");
	
	// Test 6: src = dest (self copy)
	char src6[] = "noop";
	unsigned int	len6 = 4;
	ft_memmove(src6, src6, len6);
	assert(strcmp(src6, "noop") == 0);
	// printf("test 6 passed\n");

	// Test 7: copy with embedded nulls - is this a valid test case?
	// unsigned char	src7[] = {1, 0, 2, 0, 3};
	// unsigned char	dest7[5] = {0};
	// unsigned char	dest7check[5] = {1, 0, 2, 0, 3};
	// unsigned int	len7 = 5;
	// ft_memmove(src7, src7, len7);
	// printf("dest7 is %c\n", dest7[0]);
	// assert(memcmp(dest7, dest7check, len7) == 0);

    
    printf("All tests passed!\n");
    return 0;
}