#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../libft.h"
#include "../ft_strmapi.c"

char	first_letter_to_upper(unsigned int i, char str)
{
	if	(i == 0 && str >= 'a' && str <= 'z')
		return (str - 32);
	else
		return (str);
}

char	second_letter_to_upper(unsigned int i, char str)
{
	if (i == 1 && str >= 'a' && str <= 'z')
		return (str - 32);
	else
		return (str);
}

char	odd_letters_to_upper(unsigned int i, char str)
{
	if (i % 2 > 0 && str >= 'a' && str <= 'z')
		return (str - 32);
	else
		return (str);
}

char	identity(unsigned int i, char str)
{
	if (i % 1 == 0)
		return (str);
	else
		return (str);
}

char	replace_num_sym(unsigned int i, char str)
{
	if (i > 0 && str >= '0' && str <= '9')
		return ('*');
	else
		return (str);
}

char	replace_alpha_zero(unsigned int i, char str)
{
	if (i > 0 && (str >= 'a' && str <= 'z'))
		return ('0');
	else
		return ('0');
}

int main(void)
{
    // Test 1: return first letter as uppercase
	char	str1[] = "abc";
	char	expected1[] = "Abc";
	char	*result1 = ft_strmapi(str1, first_letter_to_upper);
	if (!result1)
		printf("result1 is null\n");
	else
		assert(strcmp(result1, expected1) == 0);
	printf("test 1 passed\n");
	free(result1);

	// Test 2: return second letter as uppercase
	char		str2[] = "abc";
	char		expected2[] = "aBc";
	char		*result2 = ft_strmapi(str2, second_letter_to_upper);
	if (!result2)
		printf("result2 is null\n");
	else
		assert(strcmp(result2, expected2) == 0);
	printf("test 2 passed\n");
	free(result2);
	
	// Test 3: return odd index letters as uppercase
	char		str3[] = "hello";
	char		expected3[] = "hElLo";
	char		*result3 = ft_strmapi(str3, odd_letters_to_upper);
	if (!result3)
		printf("result3 is null\n");
	else
		assert(strcmp(result3, expected3) == 0);
	printf("test 3 passed\n");
	free(result3);

	// Test 4: identity - return whatever is passed
	char		str4[] = "abc";
	char		expected4[] = "abc";
	char		*result4 = ft_strmapi(str4, identity);
	if (!result4)
		printf("result4 is null\n");
	else
		assert(strcmp(result4, expected4) == 0);
	printf("test 4 passed\n");
	free(result4);

	// Test 5: replace numbers with symbol (*)
	char		str5[] = "a1b2";
	char		expected5[] = "a*b*";
	char		*result5 = ft_strmapi(str5, replace_num_sym);
	if (!result5)
		printf("result5 is empty\n");
	else
		assert(strcmp(result5, expected5) == 0);
	printf("test 5 passed\n");
	free(result5);

	// Test 6: Replace alphabets with zero
	char		str6[] = "hello";
	char		expected6[] = "00000";
	char		*result6 = ft_strmapi(str6, replace_alpha_zero);
	if (!result6)
		printf("result6 is empty\n");
	else
		assert(strcmp(result6, expected6) == 0);
	printf("test 6 passed\n");
	free(result6);
    
    printf("All tests passed!\n");
    return 0;
}