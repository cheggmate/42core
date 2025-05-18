#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_split.c"

void	free_all(char **array)
{
	int		i = 0;

	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	printf("all arr freed\n");
}

int main(void)
{
    // Test 1: Simple case
	char	str1[] = "a,b,c";
	char	delimit1 = ',';
	char	**results1 = ft_split(str1, delimit1);
	if (!results1)
		printf("results1 is null\n");
	else
	{
		// printf("results1[2]: %s\n", results1[2]);
		// printf("results1[3]: '%s'\n", results1[3]);
		assert(strcmp(results1[0], "a") == 0);
		assert(strcmp(results1[1], "b") == 0);
		assert(strcmp(results1[2], "c") == 0);
		assert(!results1[3]);
	}
	printf("test 1 passed\n");
	free_all(results1);
	printf("-----------\n");

	// Test 2: Longer string with spaces
	char	str2[] = "this is a test";
	char	delimit2 = ' ';
	char	**results2 = ft_split(str2, delimit2);
	if (!results2)
		printf("results2 is null\n");
	else
	{
		assert(strcmp(results2[0], "this") == 0);
		assert(strcmp(results2[1], "is") == 0);
		assert(strcmp(results2[2], "a") == 0);
		assert(strcmp(results2[3], "test") == 0);
		assert(!(results2[4]));
	}
	printf("test 2 passed\n");
	free_all(results2);
	printf("-----------\n");

	// Test 3: String with multiple consecutive delimiters
	char	str3[] = "hello,,,world";
	char	delimit3 = ',';
	char	**results3 = ft_split(str3, delimit3);
	if (!results3)
		printf("results3 is null\n");
	else
	{
		assert(strcmp(results3[0], "hello") == 0);
		assert(strcmp(results3[1], "world") == 0);
		assert(!(results3[2]));
	}
	printf("test 3 passed\n");
	free_all(results3);
	printf("-----------\n");

	// Test 4: String starting and ending with delimiters
	/* char	str4[] = ",split,this,text,";
	char	delimit4 = ',';
	char	**results4 = ft_split(str4, delimit4);
	if(!results4)
		printf("results4 is null\n");
	else
	{
		printf("results4[0] is %s\n", results4[0]);
		printf("results4[1] is %s\n", results4[1]);
		printf("results4[2] is %s\n", results4[2]);
		printf("results4[3] is %s\n", results4[3]);
		assert(strcmp(results4[0], "split") == 0);
		assert(strcmp(results4[1], "this") == 0);
		assert(strcmp(results4[2], "text") == 0);
		assert(!(results4[3]));
	}
	printf("test 4 passed\n");
	free_all(results4);
	printf("-----------\n"); */

	// Test 5: String with only delimiters
	char	str5[] = ",,,,,,,";
	char	delimit5 = ',';
	char	**results5 = ft_split(str5, delimit5);
	assert(!results5);
	printf("test 5 passed\n");
	printf("no need to free results5\n");
	printf("-----------\n");
		
	// Test 6: Empty string
	char	str6[] = "";
	char	delimit6 = ',';
	char	**results6 = ft_split(str6, delimit6);
	assert(!results6);
	printf("test 6 passed\n");
	printf("no need to free results6\n");
	printf("-----------\n");

	// Test 7: No delimiters in the string
	char	str7[] = "test";
	char	delimit7 = ',';
	char	**results7 = ft_split(str7, delimit7);
	if(!results7)
		printf("results7 is null\n");
	else
	{
		assert(strcmp(results7[0], "test") == 0);
		assert(!results7[1]);
	}
	printf("test 7 passed\n");
	free(results7);
	printf("-----------\n");

	// Test 8: NULL string input
	char	delimit8 = ',';
	char	**results8 = ft_split(NULL, delimit8);
	assert(!results8);
	printf("test 8 passed\n");
	free(results8);
	printf("-----------\n");

	// Test 9: libft test
	char	str9[] = "tripouille";
	char	**results9 = ft_split(str9, 0);
	if (!results9)
		printf("results9 is null\n");
	else
	{
		assert(strcmp((results9[0]), "tripouille") == 0);
		assert(!results9[1]);
	}
	printf("test 9 passed\n");
	free(results9);
	printf("-----------\n");

	// Test 10: libft test
	char	str10[] = "          ";
	char	**results10 = ft_split(str10, ' ');
	assert(!results10);
	printf("test 10 passed\n");
	free(results10);
	printf("-----------\n");

    printf("All tests passed!\n");
    return 0;
}