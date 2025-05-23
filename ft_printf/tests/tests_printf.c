#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <stdarg.h>
#include "../ft_printf.c"


void	print_test_header(const char *test_name)
{
	ft_printf("\n\n==================================================\n");
	ft_printf("              TESTING %%%s FORMAT                ", test_name);
	ft_printf("\n==================================================\n");
}

void	print_test_subheader(const char *subheader)
{
	ft_printf("\n--------------------------------------------------\n");
	ft_printf(" %s ", subheader);
	ft_printf("\n--------------------------------------------------\n");
}

static void	test_percent(void)
{
	print_test_subheader("PERCENT SIGN TESTS");
	
	ft_printf("(FT) Test 1: Single percent: [%%]\n");
	printf("(IO) Test 1: Single percent: [%%]\n");
	ft_printf("(FT) Test 2: Multiple percent: [%%%%%%]\n");
	printf("(IO) Test 2: Multiple percent: [%%%%%%]\n");
	ft_printf("(FT) Test 3: Percent with text: [Hello %% World]\n");
	printf("(IO) Test 3: Percent with text: [Hello %% World]\n");
}

static void	test_char_basic(void)
{
	print_test_subheader("CHARACTER TESTS");
	
	ft_printf("(FT) Test 1: Simple character: [%c]\n", 'a');
	printf("(IO) Test 1: Simple character: [%c]\n", 'a');
	ft_printf("(FT) Test 2: Digit character: [%c]\n", '0');
	printf("(IO) Test 2: Digit character: [%c]\n", '0');
	ft_printf("(FT) Test 3: Special character: [%c]\n", '*');
	printf("(IO) Test 3: Special character: [%c]\n", '*');
	ft_printf("(FT) Test 4: Space character: [%c]\n", ' ');
	printf("(IO) Test 4: Space character: [%c]\n", ' ');
	ft_printf("(FT) Test 5: Null character: [%c]\n", '\0');
	printf("(IO) Test 5: Null character: [%c]\n", '\0');
	ft_printf("(FT) Test 6: ASCII value: [%c]\n", 65); // 'A'
	printf("(IO) Test 6: ASCII value: [%c]\n", 65); // 'A'
}

static void	test_string_basic(void)
{	
	print_test_subheader("STRING TESTS");
	
	ft_printf("(FT) Test 1: Simple string: [%s]\n", "Hello");
	printf("(IO) Test 1: Simple string: [%s]\n", "Hello");
	ft_printf("(FT) Test 2: Empty string: [%s]\n", "");
	printf("(IO) Test 2: Empty string: [%s]\n", "");
	ft_printf("(FT) Test 3: String with spaces: [%s]\n", "Hello World");
	printf("(IO) Test 3: String with spaces: [%s]\n", "Hello World");
	ft_printf("(FT) Test 4: String with special chars: [%s]\n", "Hello\tWorld\n");
	printf("(IO) Test 4: String with special chars: [%s]\n", "Hello\tWorld\n");
	
	char	*null_ptr = NULL;
	ft_printf("(FT) Test 5: NULL string: [%s]\n", null_ptr);
	printf("(IO) Test 5: NULL string: [%s]\n", (char *)NULL);
}

static void	test_pointer_basic(void)
{
	print_test_subheader("POINTER TESTS");
	
	int num = 42;
	char c = 'a';
	void *ptr1 = &num;
	void *ptr2 = &c;
	void *ptr3 = NULL;
	
	ft_printf("(FT) Test 1: Integer pointer: [%p]\n", ptr1);
	printf("(IO) Test 1: Integer pointer: [%p]\n", ptr1);
	ft_printf("(FT) Test 2: Character pointer: [%p]\n", ptr2);
	printf("(IO) Test 2: Character pointer: [%p]\n", ptr2);
	ft_printf("(FT) Test 3: NULL pointer: [%p]\n", ptr3);
	printf("(IO) Test 3: NULL pointer: [%p]\n", ptr3);
	ft_printf("(FT) Test 4: Literal address: [%p]\n", (void *)0x12345678);
	printf("(IO) Test 4: Literal address: [%p]\n", (void *)0x12345678);
	ft_printf("(FT) Test 5: Function pointer: [%p]\n", (void *)&test_pointer_basic);
	printf("(IO) Test 5: Function pointer: [%p]\n", (void *)&test_pointer_basic);
}

static void	test_integer_basic(void)
{
	print_test_subheader("INTEGER TESTS");
	
	ft_printf("(FT) Test 1: Zero: [%d]\n", 0);
	printf("(IO) Test 1: Zero: [%d]\n", 0);
	ft_printf("(FT) Test 2: Positive integer: [%d]\n", 42);
	printf("(IO) Test 2: Positive integer: [%d]\n", 42);
	ft_printf("(FT) Test 3: Negative integer: [%d]\n", -42);
	printf("(IO) Test 3: Negative integer: [%d]\n", -42);
	ft_printf("(FT) Test 4: MAX_INT: [%d]\n", INT_MAX);
	printf("(IO) Test 4: MAX_INT: [%d]\n", INT_MAX);
	ft_printf("(FT) Test 5: MIN_INT: [%d]\n", INT_MIN);
	printf("(IO) Test 5: MIN_INT: [%d]\n", INT_MIN);
	
	// Test %i as well
	ft_printf("(FT) Test 6: Zero with %%i: [%i]\n", 0);
	printf("(IO) Test 6: Zero with %%i: [%i]\n", 0);
	ft_printf("(FT) Test 7: Positive with %%i: [%i]\n", 42);
	printf("(IO) Test 7: Positive with %%i: [%i]\n", 42);
	ft_printf("(FT) Test 8: Negative with %%i: [%i]\n", -42);
	printf("(IO) Test 8: Negative with %%i: [%i]\n", -42);
}

static void	test_unsigned_basic(void)
{
	print_test_subheader("UNSIGNED INTEGER TESTS");
	
	ft_printf("(FT) Test 1: Zero: [%u]\n", 0);
	printf("(IO) Test 1: Zero: [%u]\n", 0);
	ft_printf("(FT) Test 2: Positive unsigned: [%u]\n", 42);
	printf("(IO) Test 2: Positive unsigned: [%u]\n", 42);
	ft_printf("(FT) Test 3: Large unsigned: [%u]\n", 4294967295u); // UINT_MAX for 32-bit
	printf("(IO) Test 3: Large unsigned: [%u]\n", 4294967295u); // UINT_MAX for 32-bit
	ft_printf("(FT) Test 4: Technically negative (wraps around): [%u]\n", -1);
	printf("(IO) Test 4: Technically negative (wraps around): [%u]\n", -1);
}

static void	test_hex_basic(void)
{
	print_test_subheader("HEXADECIMAL TESTS");
	
	// Lowercase hex
	ft_printf("(FT) Test 1: Zero lowercase: [%x]\n", 0);
	printf("(IO) Test 1: Zero lowercase: [%x]\n", 0);
	ft_printf("(FT) Test 2: Simple value lowercase: [%x]\n", 42);
	printf("(IO) Test 2: Simple value lowercase: [%x]\n", 42);
	ft_printf("(FT) Test 3: Larger value lowercase: [%x]\n", 0xabcdef);
	printf("(IO) Test 3: Larger value lowercase: [%x]\n", 0xabcdef);
	ft_printf("(FT) Test 4: UINT_MAX lowercase: [%x]\n", UINT_MAX);
	printf("(IO) Test 4: UINT_MAX lowercase: [%x]\n", UINT_MAX);
	
	// Uppercase hex
	ft_printf("(FT) Test 5: Zero uppercase: [%X]\n", 0);
	printf("(IO) Test 5: Zero uppercase: [%X]\n", 0);
	ft_printf("(FT) Test 6: Simple value uppercase: [%X]\n", 42);
	printf("(IO) Test 6: Simple value uppercase: [%X]\n", 42);
	ft_printf("(FT) Test 7: Larger value uppercase: [%X]\n", 0xabcdef);
	printf("(IO) Test 7: Larger value uppercase: [%X]\n", 0xabcdef);
	ft_printf("(FT) Test 8: UINT_MAX uppercase: [%X]\n", UINT_MAX);
	printf("(IO) Test 8: UINT_MAX uppercase: [%X]\n", UINT_MAX);
}

static void	test_combinations(void)
{
	print_test_subheader("COMBINATION TESTS");
	
	int num = 42;
	char c = 'Z';
	
	ft_printf("(FT) Test 1: Multiple types: [%c] [%s] [%p] [%d] [%i] [%u] [%x] [%X] [%%]\n", 
		'A', "Hello", &num, 123, -456, 789, 0xabc, 0xDEF);
	printf("(IO) Test 1: Multiple types: [%c] [%s] [%p] [%d] [%i] [%u] [%x] [%X] [%%]\n", 
		'A', "Hello", &num, 123, -456, 789, 0xabc, 0xDEF);
	
	ft_printf("(FT) Test 2: Character and string: Character [%c] and String [%s]\n", 
		'B', "World");
	printf("(IO) Test 2: Character and string: Character [%c] and String [%s]\n", 
		'B', "World");
	
	ft_printf("(FT) Test 3: Integer variants: Decimal [%d], Integer [%i], Unsigned [%u]\n", 
		-42, 42, 42);
	printf("(IO) Test 3: Integer variants: Decimal [%d], Integer [%i], Unsigned [%u]\n", 
		-42, 42, 42);
	
	ft_printf("(FT) Test 4: Hex variants: Lowercase [%x], Uppercase [%X]\n", 
		0xabcdef, 0xabcdef);
	printf("(IO) Test 4: Hex variants: Lowercase [%x], Uppercase [%X]\n", 
		0xabcdef, 0xabcdef);

	ft_printf("(FT) Test 5: Pointer and percent: Pointer [%p] and percent [%%]\n", &c);
	printf("(IO) Test 5: Pointer and percent: Pointer [%p] and percent [%%]\n", &c);

	ft_printf("(FT) Test 6: Alternating format: %c %s %c %s\n", 
		'H', "ello", 'W', "orld");
	printf("(IO) Test 6: Alternating format: %c %s %c %s\n", 
		'H', "ello", 'W', "orld");
	
	ft_printf("(FT) Test 7: Integer sequence: %d %i %u %x %X\n", 
		123, -456, 789, 0xabc, 0xDEF);
	printf("(IO) Test 7: Integer sequence: %d %i %u %x %X\n", 
		123, -456, 789, 0xabc, 0xDEF);
	
	ft_printf("(FT) Test 8: Mixed format string with plain text: The number %d is %s and in hex it's %x\n", 
		42, "positive", 42);
	printf("(IO) Test 8: Mixed format string with plain text: The number %d is %s and in hex it's %x\n", 
		42, "positive", 42);
	
	ft_printf("(FT) Test 9: Special characters: Char: %c String: %s Percent: %%\n", 
		'*', "Special\tCharacters\n");
	printf("(IO) Test 9: Special characters: Char: %c String: %s Percent: %%\n", 
		'*', "Special\tCharacters\n");

	ft_printf("(FT) Test 10: Empty string and NULL: [%s] and [%s]\n", "", (char *)NULL);
	printf("(IO) Test 10: Empty string and NULL: [%s] and [%s]\n", "", (char *)NULL);

	ft_printf("(FT) Test 11: Complex case: The character '%c' in string \"%s\" has ASCII value %d (hex: %x)\n", 
		'A', "ABC", 'A', 'A');
	printf("(IO) Test 11: Complex case: The character '%c' in string \"%s\" has ASCII value %d (hex: %x)\n", 
		'A', "ABC", 'A', 'A');
}

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
	printf("Test 15\n");
	fflush(stdout);
	char	val15 = '*';
	write(1, "ft_p : ", 7);
	ft_printf("hello world %c", val15);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world %c", val15);
	write(1, "\n", 1);
	printf("\n-----------\n");
	
	// Test 16: print char with c close to another special char
	printf("Test 16\n");
	fflush(stdout);
	char	val16 = '*';
	write(1, "ft_p : ", 7);
	ft_printf("hello world +%c$*&", val16);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world +%c$*&", val16);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 17: print number with u at the beginning
	printf("Test 17\n");
	fflush(stdout);
	unsigned int	val17 = 1348;
	write(1, "ft_p : ", 7);
	ft_printf("%u hello world!", val17);
	write(1, "\n", 1);
	printf("print: ");
	printf("%u hello world!", val17);
	write(1, "\n", 1);
	printf("\n-----------\n");

	printf("Test 17b - largest number\n");
	fflush(stdout);
	unsigned int	val17b = 4294967295;
	write(1, "ft_p : ", 7);
	ft_printf("%u hello world!", val17b);
	write(1, "\n", 1);
	printf("print: ");
	printf("%u hello world!", val17b);
	write(1, "\n", 1);
	printf("\n-----------\n");

	printf("Test 17b - zero\n");
	fflush(stdout);
	unsigned int	val17c = 0;
	write(1, "ft_p : ", 7);
	ft_printf("%u hello world!", val17c);
	write(1, "\n", 1);
	printf("print: ");
	printf("%u hello world!", val17c);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 18: print number with u at the middle
	printf("Test 18 - zero\n");
	fflush(stdout);
	unsigned int	val18 = 0;
	write(1, "ft_p : ", 7);
	ft_printf("%u hello world!", val18);
	write(1, "\n", 1);
	printf("print: ");
	printf("%u hello world!", val18);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 19: print number with u at the end
	printf("Test 19\n");
	fflush(stdout);
	unsigned int	val19 = 979822;
	write(1, "ft_p : ", 7);
	ft_printf("hello world! %u", val19);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world! %u", val19);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 20: print number with u near another special character
	printf("Test 20\n");
	fflush(stdout);
	unsigned int	val20 = 979822;
	write(1, "ft_p : ", 7);
	ft_printf("hello world! '%u'$^&", val20);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world! '%u'$^&", val20);
	write(1, "\n", 1);
	printf("\n-----------\n");

	printf("Test 20a - zero\n");
	fflush(stdout);
	unsigned int	val20a = 0;
	write(1, "ft_p : ", 7);
	ft_printf("hello world! '%u'", val20a);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world! '%u'", val20a);
	write(1, "\n", 1);
	printf("\n-----------\n");

	printf("Test 20b - max value\n");
	fflush(stdout);
	unsigned int	val20b = 4294967295;
	write(1, "ft_p : ", 7);
	ft_printf("hello world! '%u'", val20b);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world! '%u'", val20b);
	write(1, "\n", 1);
	printf("\n-----------\n");

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

	// Test 41: print multiple special characters %%

	// Test 42: test NULL
	// printf("tests %s NULL\n", NULL); // undefined behaviour

	// Test 43: test % as last char
	printf("Test 43 %% as last char\n");
	fflush(stdout);
	unsigned int	val43 = 4294967295;
	write(1, "ft_p : ", 7);
	ft_printf("hello world! '%u%%'", val43);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world! '%u%%'", val43);
	write(1, "\n", 1);
	printf("\n-----------\n");

	// Test 44: check max size
	printf("Test 44 check max size number 4294967295");
	fflush(stdout);
	unsigned int	val44 = 4294967295;
	write(1, "ft_p : ", 7);
	ft_printf("hello world! '%u'", val44);
	write(1, "\n", 1);
	printf("print: ");
	printf("hello world! '%u'", val44);
	write(1, "\n", 1);
	printf("\n-----------\n");

	ft_printf("\n===== MANDATORY ft_printf TESTS =====\n\n");
	
	setvbuf(stdout, NULL, _IONBF, 0);	
	
	test_percent();
	ft_printf("\n");
	
	test_char_basic();
	ft_printf("\n");
	
	test_string_basic();
	ft_printf("\n");
	
	test_pointer_basic();
	ft_printf("\n");
	
	test_integer_basic();
	ft_printf("\n");
	
	test_unsigned_basic();
	ft_printf("\n");
	
	test_hex_basic();
	ft_printf("\n");
	
	test_combinations();
	
	ft_printf("\n===== MANDATORY TESTS COMPLETE =====\n\n");
}
