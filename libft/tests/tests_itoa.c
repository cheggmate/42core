#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include "../ft_itoa.c"

int main(void)
{
    // Test 1: Positive decimal
	int	num1 = 123;
	char	expected1[] = "123";
	char	*result1 = ft_itoa(num1);
	if (!result1)
		printf("result1 is null\n");
	else
		assert(strcmp(result1, expected1) == 0);
	printf("test 1 passed\n");
	free(result1);

	// Test 2: Negative decimal
	int	num2 = -123;
	char	expected2[] = "-123";
	char	*result2 = ft_itoa(num2);
	if (!result2)
		printf("result2 is null\n");
	else
		assert(strcmp(result2, expected2) == 0);
	printf("test 2 passed\n");
	free(result2);

	// Test 3: Zero
	int	num3 = 0;
	char	expected3[] = "0";
	char	*result3 = ft_itoa(num3);
	if (!result3)
		printf("result3 is null\n");
	else
		assert(strcmp(result3, expected3) == 0);
	printf("test 3 passed\n");
	free(result3);

	// Test 4: MAX_INT
	int	num4 = INT_MAX;
	char	expected4[] = "2147483647";
	char	*result4 = ft_itoa(num4);
	if (!result4)
		printf("result4 is null\n");
	else
		assert(strcmp(result4, expected4) == 0);
	printf("test 4 passed\n");
	free(result4);

	// Test 5: MIN_INT
	int	num5 = INT_MIN;
	char	expected5[] = "-2147483648";
	char	*result5 = ft_itoa(num5);
	if (!result5)
		printf("result5 is null\n");
	else
		assert(strcmp(result5, expected5) == 0);
	printf("test 5 passed\n");
	free(result5);
    
    printf("All tests passed!\n");
    return 0;
}