#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <fcntl.h>
#include "../ft_putnbr_fd.c"

int main(void)
{
    // Test 1: write positive number to stdout
	ft_putnbr_fd(12345, 1);
	printf("\n");
	printf("expected: '12345' \n");
	printf("--------\n");

	// Test 2: write negative number to stdout
	ft_putnbr_fd(-1234, 1);
	printf("\n");
	printf("expected: '-1234' \n");
	printf("--------\n");

	// Test 3: zero
	ft_putnbr_fd(0, 1);
	printf("\n");
	printf("expected: '0' \n");
	printf("--------\n");

	// Test 4: INT_MAX
	ft_putnbr_fd(INT_MAX, 1);
	printf("\n");
	printf("expected: '2147483647' \n");
	printf("--------\n");

	// Test 5: INT_MIN
	ft_putnbr_fd(INT_MIN, 1);
	printf("\n");
	printf("expected: '-2147483648' \n");
	printf("--------\n");

	// Test 6: Write to file
	int	fd = open("test6_putnbr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(12345, fd);
	close(fd);
	printf("\n");
	printf("expected in file: '12345' \n");
	printf("--------\n");

	// Test 7: Wwrite negative number to stderr
	ft_putnbr_fd(-1234, 2);
	printf("\n");
	printf("expected: '-1234' \n");
	printf("--------\n");


    // printf("All tests passed!\n");
    return 0;
}