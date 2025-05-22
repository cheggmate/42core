/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_return_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:00:00 by                   #+#    #+#             */
/*   Updated: 2025/05/18 12:30:45 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"

static void log_result(const char *test_name, int ft_result, int io_result)
{
	if (ft_result == io_result)
		printf("[correct] %s: Both returned %d\n", test_name, ft_result);
	else
		printf("[ERROR] %s: ft_printf returned %d, printf returned %d\n", 
			test_name, ft_result, io_result);
}

static void test_char_return(void)
{
	int ft_res, io_res;
	char buffer[1024]; // Buffer to redirect output
	FILE *devnull;

	print_test_subheader("Character return values");
	
	devnull = fopen("/dev/null", "w");
	if (!devnull)
		return;
	
	// Basic char
	ft_res = ft_printf("%c", 'A');
	io_res = fprintf(devnull, "%c", 'A');
	log_result("Basic char", ft_res, io_res);
	
	// Char with width
	ft_res = ft_printf("%5c", 'A');
	io_res = fprintf(devnull, "%5c", 'A');
	log_result("Char with width", ft_res, io_res);
	
	// Char with left-alignment
	ft_res = ft_printf("%-5c", 'A');
	io_res = fprintf(devnull, "%-5c", 'A');
	log_result("Char with left-alignment", ft_res, io_res);
	
	// Multiple chars
	ft_res = ft_printf("%c%c%c", 'A', 'B', 'C');
	io_res = fprintf(devnull, "%c%c%c", 'A', 'B', 'C');
	log_result("Multiple chars", ft_res, io_res);
	
	// Null char
	ft_res = ft_printf("%c", '\0');
	io_res = fprintf(devnull, "%c", '\0');
	log_result("Null char", ft_res, io_res);
	
	fclose(devnull);
}

static void test_string_return(void)
{
	int ft_res, io_res;
	FILE *devnull;

	print_test_subheader("String return values");
	
	devnull = fopen("/dev/null", "w");
	if (!devnull)
		return;
	
	// Basic string
	ft_res = ft_printf("%s", "Hello");
	io_res = fprintf(devnull, "%s", "Hello");
	log_result("Basic string", ft_res, io_res);
	
	// Empty string
	ft_res = ft_printf("%s", "");
	io_res = fprintf(devnull, "%s", "");
	log_result("Empty string", ft_res, io_res);
	
	// NULL string
	ft_res = ft_printf("%s", NULL);
	io_res = fprintf(devnull, "%s", NULL);
	log_result("NULL string", ft_res, io_res);
	
	// String with width
	ft_res = ft_printf("%10s", "Hello");
	io_res = fprintf(devnull, "%10s", "Hello");
	log_result("String with width", ft_res, io_res);
	
	// String with precision
	ft_res = ft_printf("%.3s", "Hello");
	io_res = fprintf(devnull, "%.3s", "Hello");
	log_result("String with precision", ft_res, io_res);
	
	// String with width and precision
	ft_res = ft_printf("%10.3s", "Hello");
	io_res = fprintf(devnull, "%10.3s", "Hello");
	log_result("String with width and precision", ft_res, io_res);
	
	// String with left-alignment
	ft_res = ft_printf("%-10s", "Hello");
	io_res = fprintf(devnull, "%-10s", "Hello");
	log_result("String with left-alignment", ft_res, io_res);
	
	// String with left-alignment and precision
	ft_res = ft_printf("%-10.3s", "Hello");
	io_res = fprintf(devnull, "%-10.3s", "Hello");
	log_result("String with left-alignment and precision", ft_res, io_res);
	
	fclose(devnull);
}

static void test_pointer_return(void)
{
	int ft_res, io_res;
	void *ptr = (void *)0x12345678;
	void *null_ptr = NULL;
	FILE *devnull;

	print_test_subheader("Pointer return values");
	
	devnull = fopen("/dev/null", "w");
	if (!devnull)
		return;
	
	// Basic pointer
	ft_res = ft_printf("%p", ptr);
	io_res = fprintf(devnull, "%p", ptr);
	log_result("Basic pointer", ft_res, io_res);
	
	// NULL pointer
	ft_res = ft_printf("%p", null_ptr);
	io_res = fprintf(devnull, "%p", null_ptr);
	log_result("NULL pointer", ft_res, io_res);
	
	// Pointer with width
	ft_res = ft_printf("%20p", ptr);
	io_res = fprintf(devnull, "%20p", ptr);
	log_result("Pointer with width", ft_res, io_res);
	
	// Pointer with left-alignment
	ft_res = ft_printf("%-20p", ptr);
	io_res = fprintf(devnull, "%-20p", ptr);
	log_result("Pointer with left-alignment", ft_res, io_res);
	
	fclose(devnull);
}

static void test_decimal_return(void)
{
	int ft_res, io_res;
	FILE *devnull;

	print_test_subheader("Decimal return values");
	
	devnull = fopen("/dev/null", "w");
	if (!devnull)
		return;
	
	// Basic decimal
	ft_res = ft_printf("%d", 42);
	io_res = fprintf(devnull, "%d", 42);
	log_result("Basic decimal", ft_res, io_res);
	
	// Negative decimal
	ft_res = ft_printf("%d", -42);
	io_res = fprintf(devnull, "%d", -42);
	log_result("Negative decimal", ft_res, io_res);
	
	// Zero
	ft_res = ft_printf("%d", 0);
	io_res = fprintf(devnull, "%d", 0);
	log_result("Zero decimal", ft_res, io_res);
	
	// Decimal with width
	ft_res = ft_printf("%5d", 42);
	io_res = fprintf(devnull, "%5d", 42);
	log_result("Decimal with width", ft_res, io_res);
	
	// Decimal with precision
	ft_res = ft_printf("%.5d", 42);
	io_res = fprintf(devnull, "%.5d", 42);
	log_result("Decimal with precision", ft_res, io_res);
	
	// Decimal with width and precision
	ft_res = ft_printf("%8.5d", 42);
	io_res = fprintf(devnull, "%8.5d", 42);
	log_result("Decimal with width and precision", ft_res, io_res);
	
	// Decimal with left-alignment
	ft_res = ft_printf("%-5d", 42);
	io_res = fprintf(devnull, "%-5d", 42);
	log_result("Decimal with left-alignment", ft_res, io_res);
	
	// Decimal with plus sign
	ft_res = ft_printf("%+d", 42);
	io_res = fprintf(devnull, "%+d", 42);
	log_result("Decimal with plus sign", ft_res, io_res);
	
	// Decimal with space
	ft_res = ft_printf("% d", 42);
	io_res = fprintf(devnull, "% d", 42);
	log_result("Decimal with space", ft_res, io_res);
	
	// Decimal with zero padding
	ft_res = ft_printf("%05d", 42);
	io_res = fprintf(devnull, "%05d", 42);
	log_result("Decimal with zero padding", ft_res, io_res);
	
	// Decimal with all flags
	ft_res = ft_printf("%+- 08.5d", 42);
	io_res = fprintf(devnull, "%+- 08.5d", 42);
	log_result("Decimal with all flags", ft_res, io_res);
	
	// INT_MIN and INT_MAX
	ft_res = ft_printf("%d", INT_MIN);
	io_res = fprintf(devnull, "%d", INT_MIN);
	log_result("INT_MIN", ft_res, io_res);
	
	ft_res = ft_printf("%d", INT_MAX);
	io_res = fprintf(devnull, "%d", INT_MAX);
	log_result("INT_MAX", ft_res, io_res);
	
	// Test with %i
	ft_res = ft_printf("%i", 42);
	io_res = fprintf(devnull, "%i", 42);
	log_result("Basic integer (i)", ft_res, io_res);
	
	fclose(devnull);
}

static void test_unsigned_return(void)
{
	int ft_res, io_res;
	FILE *devnull;

	print_test_subheader("Unsigned return values");
	
	devnull = fopen("/dev/null", "w");
	if (!devnull)
		return;
	
	// Basic unsigned
	ft_res = ft_printf("%u", 42);
	io_res = fprintf(devnull, "%u", 42);
	log_result("Basic unsigned", ft_res, io_res);
	
	// Zero
	ft_res = ft_printf("%u", 0);
	io_res = fprintf(devnull, "%u", 0);
	log_result("Zero unsigned", ft_res, io_res);
	
	// UINT_MAX
	ft_res = ft_printf("%u", UINT_MAX);
	io_res = fprintf(devnull, "%u", UINT_MAX);
	log_result("UINT_MAX", ft_res, io_res);
	
	// Unsigned with width
	ft_res = ft_printf("%10u", 42);
	io_res = fprintf(devnull, "%10u", 42);
	log_result("Unsigned with width", ft_res, io_res);
	
	// Unsigned with precision
	ft_res = ft_printf("%.10u", 42);
	io_res = fprintf(devnull, "%.10u", 42);
	log_result("Unsigned with precision", ft_res, io_res);
	
	// Unsigned with width and precision
	ft_res = ft_printf("%15.10u", 42);
	io_res = fprintf(devnull, "%15.10u", 42);
	log_result("Unsigned with width and precision", ft_res, io_res);
	
	// Unsigned with left-alignment
	ft_res = ft_printf("%-10u", 42);
	io_res = fprintf(devnull, "%-10u", 42);
	log_result("Unsigned with left-alignment", ft_res, io_res);
	
	// Unsigned with zero padding
	ft_res = ft_printf("%010u", 42);
	io_res = fprintf(devnull, "%010u", 42);
	log_result("Unsigned with zero padding", ft_res, io_res);
	
	// Zero value with zero precision
	ft_res = ft_printf("%.0u", 0);
	io_res = fprintf(devnull, "%.0u", 0);
	log_result("Zero value with zero precision", ft_res, io_res);
	
	fclose(devnull);
}

static void test_hex_return(void)
{
	int ft_res, io_res;
	FILE *devnull;

	print_test_subheader("Hexadecimal return values");
	
	devnull = fopen("/dev/null", "w");
	if (!devnull)
		return;
	
	// Basic lowercase hex
	ft_res = ft_printf("%x", 0xabc);
	io_res = fprintf(devnull, "%x", 0xabc);
	log_result("Basic lowercase hex", ft_res, io_res);
	
	// Basic uppercase hex
	ft_res = ft_printf("%X", 0xabc);
	io_res = fprintf(devnull, "%X", 0xabc);
	log_result("Basic uppercase hex", ft_res, io_res);
	
	// Zero
	ft_res = ft_printf("%x", 0);
	io_res = fprintf(devnull, "%x", 0);
	log_result("Zero hex", ft_res, io_res);
	
	// Hex with width
	ft_res = ft_printf("%10x", 0xabc);
	io_res = fprintf(devnull, "%10x", 0xabc);
	log_result("Hex with width", ft_res, io_res);
	
	// Hex with precision
	ft_res = ft_printf("%.10x", 0xabc);
	io_res = fprintf(devnull, "%.10x", 0xabc);
	log_result("Hex with precision", ft_res, io_res);
	
	// Hex with width and precision
	ft_res = ft_printf("%15.10x", 0xabc);
	io_res = fprintf(devnull, "%15.10x", 0xabc);
	log_result("Hex with width and precision", ft_res, io_res);
	
	// Hex with left-alignment
	ft_res = ft_printf("%-10x", 0xabc);
	io_res = fprintf(devnull, "%-10x", 0xabc);
	log_result("Hex with left-alignment", ft_res, io_res);
	
	// Hex with zero padding
	ft_res = ft_printf("%010x", 0xabc);
	io_res = fprintf(devnull, "%010x", 0xabc);
	log_result("Hex with zero padding", ft_res, io_res);
	
	// Hex with hash flag (lowercase)
	ft_res = ft_printf("%#x", 0xabc);
	io_res = fprintf(devnull, "%#x", 0xabc);
	log_result("Hex with hash flag (lowercase)", ft_res, io_res);
	
	// Hex with hash flag (uppercase)
	ft_res = ft_printf("%#X", 0xabc);
	io_res = fprintf(devnull, "%#X", 0xabc);
	log_result("Hex with hash flag (uppercase)", ft_res, io_res);
	
	// Hex with all flags
	ft_res = ft_printf("%#-010x", 0xabc);
	io_res = fprintf(devnull, "%#-010x", 0xabc);
	log_result("Hex with all flags", ft_res, io_res);
	
	// Zero value with zero precision
	ft_res = ft_printf("%.0x", 0);
	io_res = fprintf(devnull, "%.0x", 0);
	log_result("Zero value with zero precision", ft_res, io_res);
	
	// Zero value with hash flag
	ft_res = ft_printf("%#x", 0);
	io_res = fprintf(devnull, "%#x", 0);
	log_result("Zero value with hash flag", ft_res, io_res);
	
	fclose(devnull);
}

static void test_percent_return(void)
{
	int ft_res, io_res;
	FILE *devnull;

	print_test_subheader("Percent sign return values");
	
	devnull = fopen("/dev/null", "w");
	if (!devnull)
		return;
	
	// Basic percent
	ft_res = ft_printf("%%");
	io_res = fprintf(devnull, "%%");
	log_result("Basic percent", ft_res, io_res);
	
	// Multiple percent
	ft_res = ft_printf("%%%%%%");
	io_res = fprintf(devnull, "%%%%%%");
	log_result("Multiple percent", ft_res, io_res);
	
	// Percent with width
	ft_res = ft_printf("%5%");
	io_res = fprintf(devnull, "%5%");
	log_result("Percent with width", ft_res, io_res);
	
	// Percent with left-alignment
	ft_res = ft_printf("%-5%");
	io_res = fprintf(devnull, "%-5%");
	log_result("Percent with left-alignment", ft_res, io_res);
	
	// Percent with zero padding
	ft_res = ft_printf("%05%");
	io_res = fprintf(devnull, "%05%");
	log_result("Percent with zero padding", ft_res, io_res);
	
	fclose(devnull);
}

static void test_mixed_format_return(void)
{
	int ft_res, io_res;
	FILE *devnull;

	print_test_subheader("Mixed format return values");
	
	devnull = fopen("/dev/null", "w");
	if (!devnull)
		return;
	
	// Basic mixed
	ft_res = ft_printf("Char: %c, String: %s, Int: %d", 'A', "Hello", 42);
	io_res = fprintf(devnull, "Char: %c, String: %s, Int: %d", 'A', "Hello", 42);
	log_result("Basic mixed", ft_res, io_res);
	
	// Mixed with all formats
	ft_res = ft_printf("%c %s %p %d %i %u %x %X %%", 'A', "Hello", (void *)0x12345678, -42, 42, 42, 0xabc, 0xABC);
	io_res = fprintf(devnull, "%c %s %p %d %i %u %x %X %%", 'A', "Hello", (void *)0x12345678, -42, 42, 42, 0xabc, 0xABC);
	log_result("Mixed with all formats", ft_res, io_res);
	
	// Mixed with various flags
	ft_res = ft_printf("%-5c %10s %+d %#x", 'A', "Hello", 42, 0xabc);
	io_res = fprintf(devnull, "%-5c %10s %+d %#x", 'A', "Hello", 42, 0xabc);
	log_result("Mixed with various flags", ft_res, io_res);
	
	// Edge cases
	ft_res = ft_printf("%c %s %d", '\0', NULL, 0);
	io_res = fprintf(devnull, "%c %s %d", '\0', NULL, 0);
	log_result("Edge cases mixed", ft_res, io_res);
	
	fclose(devnull);
}

static void test_edge_cases_return(void)
{
	int ft_res, io_res;
	FILE *devnull;

	print_test_subheader("Edge cases return values");
	
	devnull = fopen("/dev/null", "w");
	if (!devnull)
		return;
	
	// Empty format string
	ft_res = ft_printf("");
	io_res = fprintf(devnull, "");
	log_result("Empty format string", ft_res, io_res);
	
	// Format string with no specifiers
	ft_res = ft_printf("Hello, World!");
	io_res = fprintf(devnull, "Hello, World!");
	log_result("No specifiers", ft_res, io_res);
	
	// Only percent signs
	ft_res = ft_printf("%%%%%%%%%%");
	io_res = fprintf(devnull, "%%%%%%%%%%");
	log_result("Only percent signs", ft_res, io_res);
	
	// Zero precision with zero value
	ft_res = ft_printf("%.0d", 0);
	io_res = fprintf(devnull, "%.0d", 0);
	log_result("Zero precision with zero value", ft_res, io_res);
	
	// Very large width
	ft_res = ft_printf("%100d", 42);
	io_res = fprintf(devnull, "%100d", 42);
	log_result("Very large width", ft_res, io_res);
	
	// Very large precision
	ft_res = ft_printf("%.100d", 42);
	io_res = fprintf(devnull, "%.100d", 42);
	log_result("Very large precision", ft_res, io_res);
	
	// Special combinations of flags
	ft_res = ft_printf("%+- 0#15.10d", 42);
	io_res = fprintf(devnull, "%+- 0#15.10d", 42);
	log_result("Special combinations of flags", ft_res, io_res);
	
	// INT_MIN and INT_MAX with flags
	ft_res = ft_printf("%+d %+d", INT_MIN, INT_MAX);
	io_res = fprintf(devnull, "%+d %+d", INT_MIN, INT_MAX);
	log_result("INT_MIN and INT_MAX with flags", ft_res, io_res);
	
	fclose(devnull);
}

void test_return_values(void)
{
	print_test_header("RETURN VALUES");
	
	printf("\n=== Testing return values (number of characters printed) ===\n");
	printf("Comparing ft_printf vs printf return values:\n\n");

	test_char_return();
	test_string_return();
	test_pointer_return();
	test_decimal_return();
	test_unsigned_return();
	test_hex_return();
	test_percent_return();
	test_mixed_format_return();
	test_edge_cases_return();
	
	printf("\n=== Return value tests completed ===\n\n");
}