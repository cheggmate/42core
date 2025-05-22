#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../ft_printf.c"

int	main(void)
{
	// Test 1: print a string without any special handlers
	printf("Test 1: print a string without any special handlers\n");
	printf("ownfunc: ");
	ft_printf("hello world");
	printf("\n");
	printf("control: 'hello world'\n");
	printf("-----------");

	// Test 2: print a number
	printf("Test 2: print a number\n");
	printf("ownfunc: ");
	ft_printf("123");
	printf("\n");
	printf("control: '123'\n");
	printf("-----------");

	// Test 3: print special characters
	printf("Test 3: print special characters\n");
	printf("ownfunc: ");
	ft_printf("tab\t and newline\n");
	printf("\n");
	printf("control: 'tab\t and newline'\n");
	printf("\n");
	printf("-----------");

	// Test 4: print string with escaped slash
	printf("Test 4: print string with escaped slash\n");
	printf("ownfunc: ");
	ft_printf("\\");
	printf("\n");
	printf("control: '\\");
	printf("\n");
	printf("-----------");

	// Test 5: print string with embedded integer using %i
	printf("Test 5: print string with embedded integer using %%i\n");
	int	num5 = 2;
	printf("ownfunc: ");
	ft_printf("i have %i new keyboards", num5);
	printf("\n");
	printf("control: 'i have %i new keyboards'", num5);
	printf("\n");
	printf("-----------");

	// Test 6: print string with embedded integer using %d
	printf("Test 6: print string with embedded integer using %%d\n");
	int	num6 = 3;
	printf("ownfunc: ");
	ft_printf("i have %d new pairs of shoes", num6);
	printf("\n");
	printf("control: 'i have %d new pairs of shoes'", num6);
	printf("\n");
	printf("-----------");

	// Test 7: print string with embedded float using %f
	printf("Test 7: print string with embedded float using %%f");
	float	num7 = 12.34567890;
	printf("ownfunc: ");
	ft_printf("i have %f new pairs of socks", num7);
	printf("\n");
	printf("control: 'i have %f new pairs of socks'", num7);
	printf("\n");
	printf("-----------");

	// Test 8: print string with embedded char using %c
	printf("Test 8: print string with embedded char using %%c");
	char	val8 = 'a';
	printf("ownfunc: ");
	ft_printf("i got a %c in my exam", val8);
	printf("\n");
	printf("control: 'i got a %c in my exam'", val8);
	printf("\n");
	printf("-----------");
	
	// Test 9: print string with embedded string using %s
	printf("Test 9: print string with embedded string using %%s");
	char	val9[] = "abcdefg";
	printf("ownfunc: ");
	ft_printf("i live on %s street", val9);
	printf("\n");
	printf("control: 'i live on %s street'", val9);
	printf("\n");
	printf("-----------");

	// Test 10: print string with embedded unisigned integer using %u
	printf("Test 10: print string with embedded unisigned integer using %%u");
	unsigned int	val10 = 12345;
	printf("ownfunc: ");
	ft_printf("i got %u oranges", val10);
	printf("\n");
	printf("control: 'i got %u oranges'", val10);
	printf("\n");
	printf("-----------");

	// Test 11: print string using embedded pointer (to an int) using %p
	printf("Test 11: print string using embeedded pointer using %%p");
	int		val11 = 12345;
	void	*ptr11 = &val11;
	printf("ownfunc: ");
	ft_printf("i got %p oranges", ptr11);
	printf("\n");
	printf("control: 'i got %p oranges'", ptr11);
	printf("\n");
	printf("-----------");

	// Test 12: print string using embedded pointer (to a char) using %p
	printf("Test 12: print string using embedded pointer (to a char) using %%p");
	char	val12 = 's';
	void	*ptr12 = &val12;
	printf("ownfunc: ");
	ft_printf("i got %p oranges", ptr12);
	printf("\n");
	printf("control: 'i got %p oranges'", ptr12);
	printf("\n");
	printf("-----------");

	// Test 13: Print a number in hexadecimal base 16 lowercase format using %x
	printf("Test 13: Print a number in hexadecimal base 16 lowercase format using %%x");
	int		val13 = 100;
	printf("ownfunc: ");
	ft_printf("i got %x oranges", val13);
	printf("\n");
	printf("control: 'i got %x oranges'", val13);
	printf("\n");
	printf("-----------");

	// Test 14: Print a number in hexadecimal base 16 uppercase format using %X
	printf("Test 14: Print a number in hexadecimal base 16 uppercase format using %%X");
	int		val14 = 100;
	printf("ownfunc: ");
	ft_printf("i got %X oranges", val14);
	printf("\n");
	printf("control: 'i got %X oranges'", val14);
	printf("\n");
	printf("-----------");

	// Test 15: Print a % sign using %%
	printf("Test 15: Print a %% sign using %%");
	printf("ownfunc: ");
	ft_printf("i see a %% sign");
	printf("\n");
	printf("control: 'i see a %% sign'");
	printf("\n");
	printf("-----------");

	// Test 16: Print a % sign just after a number
	printf("Test 16: Print a %% sign just after a number");
	printf("ownfunc: ");
	ft_printf("i see a 40%% sale");
	printf("\n");
	printf("control: 'i see a 40%% sale'");
	printf("\n");
	printf("-----------");

	// Bonus tests (WIP)
	// 1. Manage any combination of the following flags '-0'. and the field minimum width under all conversions.
	// 2. Manage all the following flags: '# +' (middle char is a space)
}
