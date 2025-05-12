#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_strjoin.c"

int main(void)
{
    // Test 1 Basic concatenation
	char	str1a[] = "Hello, ";
	char	str1b[] = "world";
	char	expected1[] = "Hello, world";
	char	*new_str1 = ft_strjoin(str1a, str1b);
	if (!new_str1)
		printf("new_str1 is null\n");
	else
		assert(strcmp(new_str1, expected1) == 0);
	printf("test 1 passed\n");
	free(new_str1);

	// Test 2 One empty string
	char	str2a[] = "";
	char	str2b[] = "world";
	char	expected2[] = "world";
	char	*new_str2 = ft_strjoin(str2a, str2b);
	if (!new_str2)
		printf("new_str2 is null\n");
	else
		assert(strcmp(new_str2, expected2) == 0);
	printf("test 2 passed\n");
	free(new_str2);

	// Test 3: Both empty strings
	char	str3a[] = "";
	char	str3b[] = "";
	char	expected3[] = "";
	char	*new_str3 = ft_strjoin(str3a, str3b);
	if (!new_str3)
		printf("new_str3 is null\n");
	else
		assert(strcmp(new_str3, expected3) == 0);
	printf("test 3 passed\n");
	free(new_str3);

	// Test 4: Null input
	char	*str4a = (char *)0;
	char	str4b[] = "hello";
	char	expected4[] = "hello";
	char	*new_str4 = ft_strjoin(str4a, str4b);
	if (!new_str4)
		printf("new_str4 is null\n");
	else
		assert(strcmp(new_str4, expected4) == 0);
	printf("test 4 passed\n");
	free(new_str4);

	// Test 5: Other string is null
	char	str5a[] = "hello";
	char	*str5b = (char *)0;
	char	expected5[] = "hello";
	char	*new_str5 = ft_strjoin(str5a, str5b);
	if (!new_str5)
		printf("new_str5 is null\n");
	else
		assert(strcmp(new_str5, expected5) == 0);
	printf("test 5 passed\n");
	free(new_str5);

	// Test 6: Both stri + ft_strlen(s2)ngs are null
	char	*str6a = (char *)0;
	char	*str6b = (char *)0;
	char	expected6[] = "";
	char	*new_str6 = ft_strjoin(str6a, str6b);
	if (!new_str6)
		printf("new_str6 is null\n");
	else
		assert(strcmp(new_str6, expected6) == 0);
	printf("test 6 passed\n");
	free(new_str6);

	// Test 7: Long strings
	char	str7a[1001];
	char	str7b[1001];
	ft_memset(str7a, 'a', 1000);
	str7a[1000] = '\0';
	ft_memset(str7b, 'b', 1000);
	str7b[1000] = '\0';
	char	expected7[2001];
	char	*expected7_subptr;
	int		out = 0;
	out = ft_strlcpy(expected7, str7a, 2001);
	expected7_subptr = expected7 + ft_strlen(str7a);
	out = ft_strlcat(expected7_subptr, str7b, 2001);
	char	*new_str7 = ft_strjoin(str7a, str7b);
	if (!new_str7)
		printf("new_str7 is null\n");
	else
		assert(strcmp(new_str7, expected7) == 0);
	printf("test 7 passed\n");
	free(new_str7);

	// Test 8 : Special characters
	char	str8a[] = "foo\n";
	char	str8b[] = "\tbar";
	char	expected8[] = "foo\n\tbar";
	char	*new_str8 = ft_strjoin(str8a, str8b);
	if (!new_str8)
		printf("new_str8 is null\n");
	else
		assert(strcmp(new_str8, expected8) == 0);
	free(new_str8);

    printf("All tests passed!\n");
    return 0;
}