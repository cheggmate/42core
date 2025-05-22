/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ft_printf_tester                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18                              #+#    #+#             */
/*   Updated: 2025/05/18                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"
#include <limits.h>

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
	ft_printf("(FT) Test 5: NULL string: [%s]\n", NULL);
	printf("(IO) Test 5: NULL string: [%s]\n", NULL);
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

	ft_printf("(FT)Test 10: Empty string and NULL: [%s] and [%s]\n", "", NULL);
	printf("(IO) Test 10: Empty string and NULL: [%s] and [%s]\n", "", NULL);

	ft_printf("(FT) Test 11: Complex case: The character '%c' in string \"%s\" has ASCII value %d (hex: %x)\n", 
		'A', "ABC", 'A', 'A');
	printf("(IO) Test 11: Complex case: The character '%c' in string \"%s\" has ASCII value %d (hex: %x)\n", 
		'A', "ABC", 'A', 'A');
}

int main()
{
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
