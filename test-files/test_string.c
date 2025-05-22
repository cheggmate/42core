/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/05/18 10:39:22 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"

static void	test_basic_string(void)
{
	print_test_subheader("Basic string tests");
	
	ft_printf("(FT) Test 1: Simple string: [%s]\n", "Hello");
	printf("(IO) Test 1: Simple string: [%s]\n", "Hello");
	ft_printf("(FT) Test 2: Empty string: [%s]\n", "");
	printf("(IO) Test 2: Empty string: [%s]\n", "");
	ft_printf("(FT) Test 3: String with spaces: [%s]\n", "Hello World");
	printf("(IO) Test 3: String with spaces: [%s]\n", "Hello World");
	ft_printf("(FT) Test 4: String with special chars: [%s]\n", "Hello\tWorld\n");
	printf("(IO) Test 4: String with special chars: [%s]\n", "Hello\tWorld\n");
	ft_printf("(FT) Test 5: Multiple strings: [%s %s]\n", "Hello", "World");
	printf("(IO) Test 5: Multiple strings: [%s %s]\n", "Hello", "World");
	ft_printf("(FT) Test 6: NULL string: [%s]\n", NULL);
	printf("(IO) Test 6: NULL string: [%s]\n", NULL);
}

static void	test_string_with_width(void)
{
	print_test_subheader("String with width");
	
	ft_printf("(FT) Test 1: Width equal to length: [%5s]\n", "Hello");
	printf("(IO) Test 1: Width equal to length: [%5s]\n", "Hello");
	ft_printf("(FT) Test 2: Width less than length: [%3s]\n", "Hello");
	printf("(IO) Test 2: Width less than length: [%3s]\n", "Hello");
	ft_printf("(FT) Test 3: Width more than length: [%10s]\n", "Hello");
	printf("(IO) Test 3: Width more than length: [%10s]\n", "Hello");
	ft_printf("(FT) Test 4: Width with empty string: [%5s]\n", "");
	printf("(IO) Test 4: Width with empty string: [%5s]\n", "");
	ft_printf("(FT) Test 5: Width with NULL: [%10s]\n", NULL);
	printf("(IO) Test 5: Width with NULL: [%10s]\n", NULL);
	ft_printf("(FT) Test 6: Width zero: [%0s]\n", "Hello");
	printf("(IO) Test 6: Width zero: [%0s]\n", "Hello");
}

static void	test_string_with_precision(void)
{
	print_test_subheader("String with precision");
	
	ft_printf("(FT) Test 1: Precision less than length: [%.3s]\n", "Hello");
	printf("(IO) Test 1: Precision less than length: [%.3s]\n", "Hello");
	ft_printf("(FT) Test 2: Precision equal to length: [%.5s]\n", "Hello");
	printf("(IO) Test 2: Precision equal to length: [%.5s]\n", "Hello");
	ft_printf("(FT) Test 3: Precision more than length: [%.10s]\n", "Hello");
	printf("(IO) Test 3: Precision more than length: [%.10s]\n", "Hello");
	ft_printf("(FT) Test 4: Precision zero: [%.0s]\n", "Hello");
	printf("(IO) Test 4: Precision zero: [%.0s]\n", "Hello");
	ft_printf("(FT) Test 5: Precision with empty string: [%.5s]\n", "");
	printf("(IO) Test 5: Precision with empty string: [%.5s]\n", "");
	ft_printf("(FT) Test 6: Precision with NULL: [%.3s]\n", NULL);
	printf("(IO) Test 6: Precision with NULL: [%.3s]\n", NULL);
}

static void	test_string_with_width_and_precision(void)
{
	print_test_subheader("String with width and precision");
	
	// Width > Precision > String length
	ft_printf("(FT) Test 1: Width > Precision > Length: [%10.7s]\n", "Hello");
	printf("(IO) Test 1: Width > Precision > Length: [%10.7s]\n", "Hello");
	
	// Width > String length > Precision
	ft_printf("(FT) Test 2: Width > Length > Precision: [%10.3s]\n", "Hello");
	printf("(IO) Test 2: Width > Length > Precision: [%10.3s]\n", "Hello");
	
	// String length > Width > Precision
	ft_printf("(FT) Test 3: Length > Width > Precision: [%7.3s]\n", "HelloWorld");
	printf("(IO) Test 3: Length > Width > Precision: [%7.3s]\n", "HelloWorld");
	
	// String length > Precision > Width
	ft_printf("(FT) Test 4: Length > Precision > Width: [%3.7s]\n", "HelloWorld");
	printf("(IO) Test 4: Length > Precision > Width: [%3.7s]\n", "HelloWorld");
	
	// Precision > Width > String length
	ft_printf("(FT) Test 5: Precision > Width > Length: [%7.10s]\n", "Hello");
	printf("(IO) Test 5: Precision > Width > Length: [%7.10s]\n", "Hello");
	
	// Precision > String length > Width
	ft_printf("(FT) Test 6: Precision > Length > Width: [%3.10s]\n", "Hello");
	printf("(IO) Test 6: Precision > Length > Width: [%3.10s]\n", "Hello");
	
	// Edge cases
	ft_printf("(FT) Test 7: Width = Precision = Length: [%5.5s]\n", "Hello");
	printf("(IO) Test 7: Width = Precision = Length: [%5.5s]\n", "Hello");
	ft_printf("(FT) Test 8: Width = 0, Precision < Length: [%0.3s]\n", "Hello");
	printf("(IO) Test 8: Width = 0, Precision < Length: [%0.3s]\n", "Hello");
	ft_printf("(FT) Test 9: Width > 0, Precision = 0: [%5.0s]\n", "Hello");
	printf("(IO) Test 9: Width > 0, Precision = 0: [%5.0s]\n", "Hello");
	ft_printf("(FT) Test 10: NULL with width and precision: [%10.5s]\n", NULL);
	printf("(IO) Test 10: NULL with width and precision: [%10.5s]\n", NULL);
}

static void	test_string_with_flags(void)
{
	print_test_subheader("String with flags");
	
	// For %s only the minus flag should have an effect
	ft_printf("(FT) Test 1: Left-aligned: [%-10s]\n", "Hello");
	printf("(IO) Test 1: Left-aligned: [%-10s]\n", "Hello");
	ft_printf("(FT) Test 2: Left-aligned (width < length): [%-3s]\n", "Hello");
	printf("(IO) Test 2: Left-aligned (width < length): [%-3s]\n", "Hello");
	
	// Zero flag doesn't apply to strings, but let's test
	ft_printf("(FT) Test 3: With zero flag: [%010s]\n", "Hello");
	printf("(IO) Test 3: With zero flag: [%010s]\n", "Hello");
	
	// Other flags don't apply but should be tested
	ft_printf("(FT) Test 4: With plus flag: [%+10s]\n", "Hello");
	printf("(IO) Test 4: With plus flag: [%+10s]\n", "Hello");
	ft_printf("(FT) Test 5: With space flag: [% 10s]\n", "Hello");
	printf("(IO) Test 5: With space flag: [% 10s]\n", "Hello");
	ft_printf("(FT) Test 6: With hash flag: [%#10s]\n", "Hello");
	printf("(IO) Test 6: With hash flag: [%#10s]\n", "Hello");
	
	// Combining flags
	ft_printf("(FT) Test 7: Left-aligned with zero: [%-010s]\n", "Hello");
	printf("(IO) Test 7: Left-aligned with zero: [%-010s]\n", "Hello");
	ft_printf("(FT) Test 8: All flags: [%-+0# 10s]\n", "Hello");
	printf("(IO) Test 8: All flags: [%-+0# 10s]\n", "Hello");
	
	// Flags with NULL
	ft_printf("(FT) Test 9: NULL left-aligned: [%-10s]\n", NULL);
	printf("(IO) Test 9: NULL left-aligned: [%-10s]\n", NULL);
}

static void	test_string_with_flags_and_precision(void)
{
	print_test_subheader("String with flags and precision");
	
	// Left alignment with precision
	ft_printf("(FT) Test 1: Left-aligned with precision: [%-10.3s]\n", "Hello");
	printf("(IO) Test 1: Left-aligned with precision: [%-10.3s]\n", "Hello");
	ft_printf("(FT) Test 2: Left-aligned, precision > length: [%-10.7s]\n", "Hello");
	printf("(IO) Test 2: Left-aligned, precision > length: [%-10.7s]\n", "Hello");
	ft_printf("(FT) Test 3: Left-aligned, width < length, with precision: [%-3.7s]\n", "Hello");
	printf("(IO) Test 3: Left-aligned, width < length, with precision: [%-3.7s]\n", "Hello");
	
	// Other flag combinations
	ft_printf("(FT) Test 4: Zero flag with precision: [%010.3s]\n", "Hello");
	printf("(IO) Test 4: Zero flag with precision: [%010.3s]\n", "Hello");
	ft_printf("(FT) Test 5: Plus flag with precision: [%+10.3s]\n", "Hello");
	printf("(IO) Test 5: Plus flag with precision: [%+10.3s]\n", "Hello");
	ft_printf("(FT) Test 6: Space flag with precision: [% 10.3s]\n", "Hello");
	printf("(IO) Test 6: Space flag with precision: [% 10.3s]\n", "Hello");
	ft_printf("(FT) Test 7: Hash flag with precision: [%#10.3s]\n", "Hello");
	printf("(IO) Test 7: Hash flag with precision: [%#10.3s]\n", "Hello");
	
	// All flags with precision
	ft_printf("(FT) Test 8: All flags with precision: [%-+0# 10.3s]\n", "Hello");
	printf("(IO) Test 8: All flags with precision: [%-+0# 10.3s]\n", "Hello");
	
	// NULL cases
	ft_printf("(FT) Test 9: NULL with flags and precision: [%-10.3s]\n", NULL);
	printf("(IO) Test 9: NULL with flags and precision: [%-10.3s]\n", NULL);
}

static void	test_string_edge_cases(void)
{
	print_test_subheader("String edge cases");
	
	char *null_ptr = NULL;
	
ft_printf("(FT) Test 1: Very long string: [%s]\n", 
	"This is a very long string that exceeds the typical buffer size of most implementations");
	printf("(IO) Test 1: Very long string: [%s]\n", 
		"This is a very long string that exceeds the typical buffer size of most implementations");
	ft_printf("(FT) Test 2: String with all special chars: [%s]\n", "\t\n\r\v\f\\\"\'");
	printf("(IO) Test 2: String with all special chars: [%s]\n", "\t\n\r\v\f\\\"\'");
	ft_printf("(FT) Test 3: String with non-printable ASCII: [%s]\n", "\x01\x02\x03\x04\x05");
	printf("(IO) Test 3: String with non-printable ASCII: [%s]\n", "\x01\x02\x03\x04\x05");
	ft_printf("(FT) Test 4: NULL explicitly: [%s]\n", null_ptr);
	printf("(IO) Test 4: NULL explicitly: [%s]\n", null_ptr);
	ft_printf("(FT) Test 5: Huge width: [%100s]\n", "Hello");
	printf("(IO) Test 5: Huge width: [%100s]\n", "Hello");
	ft_printf("(FT) Test 6: Huge precision: [%.100s]\n", "Hello");
	printf("(IO) Test 6: Huge precision: [%.100s]\n", "Hello");
	ft_printf("(FT) Test 7: Zero width, zero precision: [%0.0s]\n", "Hello");
	printf("(IO) Test 7: Zero width, zero precision: [%0.0s]\n", "Hello");
}

void	test_string(void)
{
	print_test_header("string");
	
	test_basic_string();
	test_string_with_width();
	test_string_with_precision();
	test_string_with_width_and_precision();
	test_string_with_flags();
	test_string_with_flags_and_precision();
	test_string_edge_cases();
}