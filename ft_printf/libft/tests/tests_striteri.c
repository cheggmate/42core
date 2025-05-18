#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "../ft_striteri.c"

void	make_upper(unsigned int i, char *c)
{
	if (i >= 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

void 	add_index(unsigned int i, char *c)
{
	if (i >= 0)
		*c += i;
}

void	num_to_asterisk(unsigned int i, char *c)
{
	if (i >= 0 && *c >= '0' && *c <= '9')
		*c = '*';
}

void	run_striteri_test(char *input, const char *expected, void (*func)(unsigned int, char *))
{
	if (input && func)
	{
		ft_striteri(input, func);
		assert(strcmp(input, expected) == 0);
		printf("passed \"%s\"\n", input);
	}
	else
	{
		ft_striteri(input, func);
		printf("NULL save passed\n");
	}
}

int main(void)
{
    // make uppercase
	char	test1[] = "abc";
	run_striteri_test(test1, "ABC", make_upper);

	// add index
	char	test2[] = "abc";
	run_striteri_test(test2, "ace", add_index);

	// change numbers to asterisks
	char	test3[] = "a1b2c3";
	run_striteri_test(test3, "a*b*c*", num_to_asterisk);

	// empty strings
	char	test4[] = "";
	run_striteri_test(test4, "", make_upper);

	// NULL
	run_striteri_test(NULL, NULL, make_upper);

	// Function is null
	run_striteri_test("abc", NULL, NULL);
    
    printf("All tests passed!\n");
    return 0;
}