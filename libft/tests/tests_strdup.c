#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_strdup.c"

int main(void)
{
    // Test 1: normal string
	const char	*src1 = "hello";
	char		*dup1 = ft_strdup(src1);
	if (!dup1)
		printf("dup1 is null\n");
	else
	{
		assert(strcmp(dup1, src1) == 0);
		assert(memcmp(dup1, src1, 5) == 0);
	}
	free(dup1);
	
	//Test 2: empty string

	const char	*src2 = "";
	char		*dup2 = ft_strdup(src2);
	if(!dup2)
		printf("dup2 is null\n");
	else
		assert(strcmp(dup2, src2) == 0);
	free(dup2);

	// Test 3: String with spaces
	const char	*src3 = "a b c";
	char		*dup3 = ft_strdup(src3);
	if(!dup3)
		printf("dup3 is null\n");
	else
		assert(strcmp(dup3, src3) == 0);
	free(dup3);

	// Test 4: String with special chars
	const char	*src4 = "Hi!\n\t";
	char		*dup4 = ft_strdup(src4);
	if(!dup4)
		printf("dup4 is null\n");
	else
		assert(strcmp(dup4, src4) == 0);
	free(dup4);

	// Test 5: Long string
	const char	*src5 = "this is a very long string just to test this";
	char		*dup5 = ft_strdup(src5);
	if(!dup5)
		printf("dup5 is null\n");
	else
		assert(strcmp(dup5, src5) == 0);
	free(dup5);


    printf("All tests passed!\n");
    return 0;
}