#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_split.c"

int compare_split(char **result, const char **expected)
{
    int i = 0;
    while (result[i] && expected[i])
    {
        assert(strcmp(result[i], expected[i]) == 0);
        i++;
    }
    return result[i] == NULL && expected[i] == NULL;
}

int main(void)
{
    // Test 1: Simple case
	printf("starting the tests\n");
	char	str1[] = "a,b,c";
	char	delimit1 = ',';
	printf("setting up delimits\n");
	char	expected1[] = ["a", "b", "c"];
	char	**results1 = ft_split(str1, delimit1);
	if (!results1)
		printf("results1 is null\n");
	else
	{
	
	}
    
    printf("All tests passed!\n");
    return 0;
}