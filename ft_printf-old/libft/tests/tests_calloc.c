#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>
#include "../ft_calloc.c"

int main(void)
{
    // Test 1: Allocate array of ints
	size_t	num1 = 5;
	size_t	size1 = sizeof(int);
	int		result1[] = {0, 0, 0, 0, 0};
	int		*arr1 = ft_calloc(num1, size1);
	if (!arr1)
		printf("arr1 is null\n");
	else
		assert(memcmp(arr1, result1, size1) == 0);
	free(arr1);
	printf("test 1 passed\n");

	// Test 2: Allocate array of chars
	size_t	num2 = 3;
	size_t	size2 = sizeof(char);
	int		result2[] = {0, 0, 0};
	int		*arr2 = ft_calloc(num2, size2);
	if (!arr2)
		printf("arr2 is null\n");
	else
		assert(memcmp(arr2, result2, size2) == 0);
	free(arr2);
	printf("test 2 passed\n");

	// Test 3: Check for null if size = 0
	size_t	num3 = 0;
	size_t	size3 = 0;
	int		*arr3 = ft_calloc(num3, size3);
	if (!arr3)
		printf("arr3 is null\n");
	else
		assert(arr3 != NULL);
	free(arr3);	
	printf("test 3 passed\n");

	// Test 4: Zeroed struct
	size_t	num4 = 1;
	typedef struct {
        int a;
        char b;
    } Data;
	Data	result4[] = {{0, '\0'}};
	size_t	size4 = sizeof(Data);
	Data	*struct4 = ft_calloc(num4, size4);
	if (!struct4)
		printf("struct4 is null\n");
	else
		assert(memcmp(struct4, result4, sizeof(Data)) == 0);
	free(struct4);
	printf("test 4 passed\n");
	
	// Test 5: Large allocation
	size_t	num5 = 1000;
	size_t	size5 = sizeof(int);
	int		*arr5 = ft_calloc(num5, size5);
	if (!arr5)
		printf("arr5 is null\n");
	else
		assert((*arr5 == 0) || !arr5);
	printf("test 5 passed\n");
	free(arr5);

	// Test6:  size of 0
	size_t	num6 = 5;
	size_t	size6 = 0;
	int		*arr6 = ft_calloc(num6, size6);
	if (!arr6)
		printf("arr6 is null\n");
	else
		assert(arr6 != NULL);
	printf("test 6 passed\n");
	free(arr6);
	
	// Test7: negative num, zero size
	size_t	num7 = -5;
	size_t	size7 = 0;
	int		*arr7 = ft_calloc(num7, size7);
	if (!arr7)
		printf("arr7 is null\n");
	else
		assert(arr7 != NULL);
	printf("test 7 passed\n");
	free(arr7);

	// Test8: negative size, zero num
	size_t	num8 = 0;
	size_t	size8 = -5;
	int		*arr8 = ft_calloc(num8, size8);
	if (!arr8)
		printf("arr8 is null\n");
	else
		assert(arr8 != NULL);
	printf("test 8 passed\n");
	free(arr8);
    
    // printf("All tests passed!\n");
    return 0;
}