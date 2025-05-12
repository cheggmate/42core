#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_split.c"

int main(void)
{
    // Test 1: Simple case
	printf("starting the tests\n");
	char	str1[] = "a,b,c";
	char	delimit1 = ',';
	printf("setting up delimits\n");
	char	*expected1[] = {"a", "b", "c"};
	char	**results1 = &expected1;
	printf("trying to fSplit\n");
	// char	**results1 = ft_split(str1, delimit1);
	if (!results1)
		printf("results1 is null\n");
	else
	{
		assert(strcmp(*results1[0], expected1[0]) == 0);
		assert(strcmp(*results1[1], expected1[0]) == 0);
		assert(strcmp(*results1[2], expected1[0]) == 0);
		assert(!(results1[3]));
	}
    
    printf("All tests passed!\n");
    return 0;
}