#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_putendl_fd.c"

int main(void)
{
    // Test 1: Send simple string to stdout
	ft_putendl_fd("Hello world", 1);
	printf("expected: 'Hello world' \n");
	printf("---------\n");

	// Test 2: Send simple string to stderr
	ft_putendl_fd("An error occurred", 2);
	printf("expected: 'An error occurred' \n");
	printf("---------\n");

	// Test 3: Empty string
	ft_putendl_fd("", 1);
	printf("expected: (newline) \n");
	printf("---------\n");

	// Test 4: String containing a newline
	ft_putendl_fd("1.apple\n2.pear", 1);
	
	printf("expected: \n");
	printf("1.apple\n");
	printf("2.pear\n");
	printf("(newline)\n");
	printf("---------\n");

	// Test 5: NULL string
	ft_putendl_fd(NULL, 1);
	printf("expected: (nothing, should not crash)\n");
    
    // printf("All tests passed!\n");
    return 0;
}