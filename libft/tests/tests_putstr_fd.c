#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>
#include "../ft_putstr_fd.c"

int main(void)
{
    // Test 1: write to stdout
	ft_putstr_fd("Hello, world!\n", 1);
	printf("expected: 'Hello world!' \n");
	printf("\n");

	// Test 2: write to stderr
	ft_putstr_fd("An error occurred\n", 2);
	printf("expected: 'An error occurred' \n");
	printf("\n");

	// Test 3: write to a file
	int	fd = open("test3_putstr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC , 0644);
	ft_putstr_fd("This is the first string in the file.", fd);
	close(fd);
	printf("expected: 'This is the first string in the file.' \n");
	printf("\n");

	// Test 4: write empty str
	ft_putstr_fd("", 1);
	printf("expected: (nothing) \n");
	printf("\n");

	// Test 5: write a NULL pointer
	ft_putstr_fd(NULL, 1);
	printf("expected: (do nothing) \n");
	printf("\n");

	// Test 6: write a very long sentence
	ft_putstr_fd("On a bright and sunny morning, in a land far, far, away...", 1);
	printf("expected: 'On a bright and sunny morning, in a land far, far, away...' \n");
	printf("\n");
    
    // printf("All tests passed!\n");
    return 0;
}