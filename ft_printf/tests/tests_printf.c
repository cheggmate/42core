#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../ft_printf.c"

int	main(void)
{
	// Test 1: print a string without any special handlers
	printf("Test 1\n");
	ft_printf("ft_p : hello world\n");
	printf("print: hello world\n");
	printf("\n-----------\n");

	printf("print numbers\n");
	printf("\n-----------\n");

	// Test2: print a number
	printf("Test 2\n");
	fflush(stdout);
	int	val2 = 10890834;
	write(1, "ft_p : ", 7);
	ft_printf("hello %i world", val2);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello %i world", val2);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 3: print a number with i at the beginning
	printf("Test 3\n");
	fflush(stdout);
	int	val3 = 10890834;
	write(1, "ft_p : ", 7);
	ft_printf("%ihello world", val3);
	write(1, "\n", 1);
	printf("print: ");
	printf("%ihello world", val3);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 4: print a number with i at the end
	printf("Test 4\n");
	fflush(stdout);
	int	val4 = 10890834;
	write(1, "ft_p : ", 7);
	ft_printf("hello world%i", val4);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world%i", val4);
	write(1, "\n", 1);

	printf("\n-----------\n");
	printf("print decimals\n");
	printf("\n-----------\n");

	// Test 5: print number with d at the beginning
	printf("Test 5\n");
	fflush(stdout);
	int	val5 = 10890834;
	write(1, "ft_p : ", 7);
	ft_printf("hello world%d", val5);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world%d", val5);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 6: print number with d at the middle
	printf("Test 6\n");
	fflush(stdout);
	int	val6 = 10890834;
	write(1, "ft_p : ", 7);
	ft_printf("hello %d world", val6);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello %d world", val6);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 7: print number with d at the end.
	printf("Test 7\n");
	fflush(stdout);
	int	val7 = 10890834;
	write(1, "ft_p : ", 7);
	ft_printf("hello world%d", val7);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world%d", val7);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 8: print number with d close to another special char
	printf("Test 8\n");
	fflush(stdout);
	int	val8 = 10890834;
	write(1, "ft_p : ", 7);
	ft_printf("hello world%d*", val8);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world%d*", val8);
	write(1, "\n", 1);
	printf("\n-----------\n");

	printf("Test 8a\n");
	int	val8a = '\200';
	write(1, "ft_p : ", 7);
	ft_printf("hello world%d*", val8a);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world%d*", val8a);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 9: print string with s at the start
	printf("Test 9\n");
	fflush(stdout);
	char	val9[] = "super*";
	write(1, "ft_p : ", 7);
	ft_printf("%s, hello world", val9);
	write(1, "\n", 1);
	printf("print: ");
	printf("%s, hello world", val9);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 10: print string with s in the middle
	printf("Test 10\n");
	fflush(stdout);
	char	val10[] = "super*";
	write(1, "ft_p : ", 7);
	ft_printf("hello %sworld", val10);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello %sworld", val10);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 11: print string with s at the end
	printf("Test 11\n");
	fflush(stdout);
	char	val11[] = "super*";
	write(1, "ft_p : ", 7);
	ft_printf("hello world%s", val11);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world%s", val11);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 12: print string with s close to another special char
	printf("Test 12\n");
	fflush(stdout);
	char	val12[] = "super*";
	write(1, "ft_p : ", 7);
	ft_printf("hello world%s(&*(^))", val12);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world%s(&*(^))", val12);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 13: print char with c at the start
	printf("Test 13\n");
	fflush(stdout);
	char	val13 = '&';
	write(1, "ft_p : ", 7);
	ft_printf("%c, hello world", val13);
	write(1, "\n", 1);
	printf("print: ");
	printf("%c, hello world", val13);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 14: print char with c at the middle
	printf("Test 14\n");
	fflush(stdout);
	char	val14 = '&';
	write(1, "ft_p : ", 7);
	ft_printf("hello %c world", val14);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello %c world", val14);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 15: print char with c at the end
	
	// Test 16: print char with c close to another special char

	// Test 17: print number with u at the beginning

	// Test 18: print number with u at the middle

	// Test 19: print number with u at the end

	// Test 20: print number with u near another special character

	// Test 21: print number with x at the start

	// Test 22: print number with x at the middle

	// Test 23: print number with x at the end

	// Test 24: print number with X at the start

	// Test 25: print number with X at the middle

	// Test 26: print number with X at the end.

	// Test 27: print %

	// Test 28: print multiple strings using s

	// Test 29: print multiple strings using s and c

	// Test 30: print multiple string using s, i , d, c

	// Test 40: print multiple strings using bytes??

	// Test 41: printg multiple special characters %%

}
