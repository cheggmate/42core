#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_memset.c"

int main(void)
{
    // Test 1: Fill entire array with zero
	char			buffer1[4] = {1, 2, 3, 4}; // Values before change
	char			expected1[4] = {0, 0, 0, 0};
	unsigned int	len1 = 4;
	ft_memset(buffer1, 0, len1);
	assert(memcmp(buffer1, expected1, len1) == 0);
	printf("test 1 passed\n");

	// Test 2: Fill array with 0xFF
	char			buffer2[4] = {0, 0, 0, 0}; // Values before change
	char			expected2[4] = {255, 255, 255, 255};
	unsigned int	len2 = 4;
	ft_memset(buffer2, 255, len2);
	assert(memcmp(buffer2, expected2, len2) == 0);
	printf("test 2 passed\n");

	// Test 3: partial fill
	char			buffer3[5] = {1, 2, 3, 4, 5}; // Values before change
	char			expected3[5] = {9, 9, 9, 4, 5};
	unsigned int	len3 = 3;
	ft_memset(buffer3, 9, len3);
	assert(memcmp(buffer3, expected3, len3) == 0);
	printf("test 3 passed\n");

	// Test 4: fill string
	char			buffer4[5] = "hello";
	char			expected4[5] = "***lo";
	unsigned int	len4 = 3;
	ft_memset(buffer4, '*', len4);
	assert(memcmp(buffer4, expected4, len4) == 0);
	printf("test 4 passed\n");

	// Test 5: fill unintialised struct with 0
	char			buffer5[5];
	char			expected5[5] = {0, 0, 0, 0, 0};
	unsigned int	len5 = 5;
	ft_memset(buffer5, 0, len5);
	assert(memcmp(buffer5, expected5, len5) == 0);
	printf("test 5 passed\n");

	// Test 6: Size is zero (no effect)
	char			buffer6[3] = {0, 0, 0};
	char			expected6[3] = {0, 0, 0};
	unsigned int	len6 = 0;
	ft_memset(buffer6, 0, len6);
	assert(memcmp(buffer6, expected6, len6) == 0);
	printf("test 6 passed\n");

	// Test 7: Fill with embedded '\0
	char			buffer7[4] = {1, 2, 3, 4};
	char			expected7[4] = {0, 0, 0, 0};
	unsigned int	len7 = 4;
	ft_memset(buffer7, '\0', len7);
	assert(memcmp(buffer7, expected7, len7) == 0);

    printf("All tests passed!\n");
    return 0;
}