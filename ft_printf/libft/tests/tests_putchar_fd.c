#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include "../ft_putchar_fd.c"

int main(void)
{
    // Test case 1: write to standard output
	ft_putchar_fd('B', 1);
	printf("\n");
	printf("expected: 'B' \n");

	// Test case 2: write to standard error
	ft_putchar_fd('E', 2);
	printf("\n");
	printf("expected: 'E' \n");

	// Test case 3: write to a file
	int	fd = open("test3_purchar_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('F', fd);
	close(fd);
	printf("\n");
	printf("expected output in the file: 'F' \n");

	// Test case 4: write multiple letters
	char	str4[] = "This is a test";
	int		count = 0;
	while (count < 14)
	{
		ft_putchar_fd(str4[count], 1);
		count++;
	}
    
    // printf("All tests passed!\n");
    return 0;
}