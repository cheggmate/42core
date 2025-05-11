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
		assert(memcmp(arr2, result2, num2) == 0);
	free(arr2);
	printf("test 2 passed\n");

	// Test 3: Check for null if size = 0
	size_t	num3 = 0;
	size_t	size3 = 0;
	int		*arr3 = ft_calloc(num3, size3);
	if (!arr3)
		printf("arr3 is null\n");
	else
		assert(!arr3);
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
	free(arr5);
    
    printf("All tests passed!\n");
    return 0;
}