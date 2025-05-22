/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/05/18 10:38:52 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"

static void	test_basic_decimal(void)
{
	print_test_subheader("Basic decimal tests");
	
	ft_printf("(FT) Test 1: Zero: [%d]\n", 0);
	printf("(IO) Test 1: Zero: [%d]\n", 0);
	ft_printf("(FT) Test 2: Positive number: [%d]\n", 42);
	printf("(IO) Test 2: Positive number: [%d]\n", 42);
	ft_printf("(FT) Test 3: Negative number: [%d]\n", -42);
	printf("(IO) Test 3: Negative number: [%d]\n", -42);
	ft_printf("(FT) Test 4: INT_MAX: [%d]\n", INT_MAX);
	printf("(IO) Test 4: INT_MAX: [%d]\n", INT_MAX);
	ft_printf("(FT) Test 5: INT_MIN: [%d]\n", INT_MIN);
	printf("(IO) Test 5: INT_MIN: [%d]\n", INT_MIN);
	ft_printf("(FT) Test 6: Multiple numbers: [%d %d %d]\n", 1, -2, 3);
	printf("(IO) Test 6: Multiple numbers: [%d %d %d]\n", 1, -2, 3);
	
	// Testing %i as well
	ft_printf("(FT) Test 7: Zero with %%i: [%i]\n", 0);
	printf("(IO) Test 7: Zero with %%i: [%i]\n", 0);
	ft_printf("(FT) Test 8: Positive with %%i: [%i]\n", 42);
	printf("(IO) Test 8: Positive with %%i: [%i]\n", 42);
	ft_printf("(FT) Test 9: Negative with %%i: [%i]\n", -42);
	printf("(IO) Test 9: Negative with %%i: [%i]\n", -42);
}

static void	test_decimal_with_width(void)
{
	print_test_subheader("Decimal with width");
	
	ft_printf("(FT) Test 1: Width exact fit: [%2d]\n", 42);
	printf("(IO) Test 1: Width exact fit: [%2d]\n", 42);
	ft_printf("(FT) Test 2: Width larger: [%5d]\n", 42);
	printf("(IO) Test 2: Width larger: [%5d]\n", 42);
	ft_printf("(FT) Test 3: Width smaller: [%1d]\n", 42);
	printf("(IO) Test 3: Width smaller: [%1d]\n", 42);
	ft_printf("(FT) Test 4: Width with negative number: [%5d]\n", -42);
	printf("(IO) Test 4: Width with negative number: [%5d]\n", -42);
	ft_printf("(FT) Test 5: Width with zero: [%5d]\n", 0);
	printf("(IO) Test 5: Width with zero: [%5d]\n", 0);
	ft_printf("(FT) Test 6: Zero width: [%0d]\n", 42);
	printf("(IO) Test 6: Zero width: [%0d]\n", 42);
	
	// Test with %i
	ft_printf("(FT) Test 7: %%i with width: [%5i]\n", 42);
	printf("(IO) Test 7: %%i with width: [%5i]\n", 42);
	ft_printf("(FT) Test 8: %%i negative with width: [%5i]\n", -42);
	printf("(IO) Test 8: %%i negative with width: [%5i]\n", -42);
}

static void	test_decimal_with_precision(void)
{
	print_test_subheader("Decimal with precision");
	
	ft_printf("(FT) Test 1: Precision exact fit: [%.2d]\n", 42);
	printf("(IO) Test 1: Precision exact fit: [%.2d]\n", 42);
	ft_printf("(FT) Test 2: Precision larger: [%.5d]\n", 42);
	printf("(IO) Test 2: Precision larger: [%.5d]\n", 42);
	ft_printf("(FT) Test 3: Precision smaller: [%.1d]\n", 42);
	printf("(IO) Test 3: Precision smaller: [%.1d]\n", 42);
	ft_printf("(FT) Test 4: Precision with negative: [%.5d]\n", -42);
	printf("(IO) Test 4: Precision with negative: [%.5d]\n", -42);
	ft_printf("(FT) Test 5: Precision with zero: [%.5d]\n", 0);
	printf("(IO) Test 5: Precision with zero: [%.5d]\n", 0);
	ft_printf("(FT) Test 6: Zero precision non-zero: [%.0d]\n", 42);
	printf("(IO) Test 6: Zero precision non-zero: [%.0d]\n", 42);
	ft_printf("(FT) Test 7: Zero precision with zero: [%.0d]\n", 0);
	printf("(IO) Test 7: Zero precision with zero: [%.0d]\n", 0);
	
	// Test with %i
	ft_printf("(FT) Test 8: %%i with precision: [%.5i]\n", 42);
	printf("(IO) Test 8: %%i with precision: [%.5i]\n", 42);
	ft_printf("(FT) Test 9: %%i negative with precision: [%.5i]\n", -42);
	printf("(IO) Test 9: %%i negative with precision: [%.5i]\n", -42);
	ft_printf("(FT) Test 10: %%i zero with zero precision: [%.0i]\n", 0);
	printf("(IO) Test 10: %%i zero with zero precision: [%.0i]\n", 0);
}

static void	test_decimal_with_width_and_precision(void)
{
	print_test_subheader("Decimal with width and precision");
	
	// Width > Precision > Digits
	ft_printf("(FT) Test 1: Width > Precision > Digits: [%8.5d]\n", 42);
	printf("(IO) Test 1: Width > Precision > Digits: [%8.5d]\n", 42);
	
	// Width > Digits > Precision
	ft_printf("(FT) Test 2: Width > Digits > Precision: [%8.1d]\n", 42);
	printf("(IO) Test 2: Width > Digits > Precision: [%8.1d]\n", 42);
	
	// Precision > Width > Digits
	ft_printf("(FT) Test 3: Precision > Width > Digits: [%3.8d]\n", 42);
	printf("(IO) Test 3: Precision > Width > Digits: [%3.8d]\n", 42);
	
	// Precision > Digits > Width
	ft_printf("(FT) Test 4: Precision > Digits > Width: [%1.8d]\n", 42);
	printf("(IO) Test 4: Precision > Digits > Width: [%1.8d]\n", 42);
	
	// Digits > Width > Precision
	ft_printf("(FT) Test 5: Digits > Width > Precision: [%2.1d]\n", 12345);
	printf("(IO) Test 5: Digits > Width > Precision: [%2.1d]\n", 12345);
	
	// Digits > Precision > Width
	ft_printf("(FT) Test 6: Digits > Precision > Width: [%1.2d]\n", 12345);
	printf("(IO) Test 6: Digits > Precision > Width: [%1.2d]\n", 12345);
	
	// Negative numbers
	ft_printf("(FT) Test 7: Negative with width & precision: [%8.5d]\n", -42);
	printf("(IO) Test 7: Negative with width & precision: [%8.5d]\n", -42);
	ft_printf("(FT) Test 8: Negative, precision > width: [%3.8d]\n", -42);
	printf("(IO) Test 8: Negative, precision > width: [%3.8d]\n", -42);
	
	// Zero
	ft_printf("(FT) Test 9: Zero with width & precision: [%8.5d]\n", 0);
	printf("(IO) Test 9: Zero with width & precision: [%8.5d]\n", 0);
	ft_printf("(FT) Test 10: Zero, zero precision: [%8.0d]\n", 0);
	printf("(IO) Test 10: Zero, zero precision: [%8.0d]\n", 0);
	
	// Test with %i
	ft_printf("(FT) Test 11: %%i with width & precision: [%8.5i]\n", 42);
	printf("(IO) Test 11: %%i with width & precision: [%8.5i]\n", 42);
	ft_printf("(FT) Test 12: %%i negative with width & precision: [%8.5i]\n", -42);
	printf("(IO) Test 12: %%i negative with width & precision: [%8.5i]\n", -42);
}

static void	test_decimal_with_flags(void)
{
	print_test_subheader("Decimal with flags");
	
	// Left justification flag (-)
	ft_printf("(FT) Test 1: Left-aligned: [%-5d]\n", 42);
	printf("(IO) Test 1: Left-aligned: [%-5d]\n", 42);
	ft_printf("(FT) Test 2: Left-aligned negative: [%-5d]\n", -42);
	printf("(IO) Test 2: Left-aligned negative: [%-5d]\n", -42);
	
	// Plus flag (+)
	ft_printf("(FT) Test 3: With plus sign: [%+d]\n", 42);
	printf("(IO) Test 3: With plus sign: [%+d]\n", 42);
	ft_printf("(FT) Test 4: Negative with plus sign: [%+d]\n", -42);
	printf("(IO) Test 4: Negative with plus sign: [%+d]\n", -42);
	ft_printf("(FT) Test 5: Plus with width: [%+5d]\n", 42);
	printf("(IO) Test 5: Plus with width: [%+5d]\n", 42);
	
	// Space flag ( )
	ft_printf("(FT) Test 6: With space: [% d]\n", 42);
	printf("(IO) Test 6: With space: [% d]\n", 42);
	ft_printf("(FT) Test 7: Negative with space: [% d]\n", -42);
	printf("(IO) Test 7: Negative with space: [% d]\n", -42);
	ft_printf("(FT) Test 8: Space with width: [% 5d]\n", 42);
	printf("(IO) Test 8: Space with width: [% 5d]\n", 42);
	
	// Zero flag (0)
	ft_printf("(FT) Test 9: Zero-padded: [%05d]\n", 42);
	printf("(IO) Test 9: Zero-padded: [%05d]\n", 42);
	ft_printf("(FT) Test 10: Zero-padded negative: [%05d]\n", -42);
	printf("(IO) Test 10: Zero-padded negative: [%05d]\n", -42);
	
	// Hash flag (#) - doesn't affect decimal but test anyway
	ft_printf("(FT) Test 11: With hash: [%#d]\n", 42);
	printf("(IO) Test 11: With hash: [%#d]\n", 42);
	
	// Test some combinations
	ft_printf("(FT) Test 12: Left-aligned with plus: [%-+5d]\n", 42);
	printf("(IO) Test 12: Left-aligned with plus: [%-+5d]\n", 42);
	ft_printf("(FT) Test 13: Zero-padded with plus: [%+05d]\n", 42);
	printf("(IO) Test 13: Zero-padded with plus: [%+05d]\n", 42);
	ft_printf("(FT) Test 14: Space with zero-padding: [% 05d]\n", 42);
	printf("(IO) Test 14: Space with zero-padding: [% 05d]\n", 42);
	ft_printf("(FT) Test 15: Left-aligned with zero (left wins): [%-05d]\n", 42);
	printf("(IO) Test 15: Left-aligned with zero (left wins): [%-05d]\n", 42);
	ft_printf("(FT) Test 16: Plus with space (plus wins): [%+ d]\n", 42);
	printf("(IO) Test 16: Plus with space (plus wins): [%+ d]\n", 42);
	
	// Test with %i
	ft_printf("(FT) Test 17: %%i with flags: [%-+05i]\n", 42);
	printf("(IO) Test 17: %%i with flags: [%-+05i]\n", 42);
}

static void	test_decimal_with_flags_and_precision(void)
{
	print_test_subheader("Decimal with flags and precision");
	
	// Precision with different flags
	ft_printf("(FT) Test 1: Left-aligned with precision: [%-8.5d]\n", 42);
	printf("(IO) Test 1: Left-aligned with precision: [%-8.5d]\n", 42);
	ft_printf("(FT) Test 2: Plus with precision: [%+8.5d]\n", 42);
	printf("(IO) Test 2: Plus with precision: [%+8.5d]\n", 42);
	ft_printf("(FT) Test 3: Space with precision: [% 8.5d]\n", 42);
	printf("(IO) Test 3: Space with precision: [% 8.5d]\n", 42);
	
	// Zero flag with precision (precision wins for padding)
	ft_printf("(FT) Test 4: Zero-padded with precision: [%08.5d]\n", 42);
	printf("(IO) Test 4: Zero-padded with precision: [%08.5d]\n", 42);
	
	// Hash with precision
	ft_printf("(FT) Test 5: Hash with precision: [%#8.5d]\n", 42);
	printf("(IO) Test 5: Hash with precision: [%#8.5d]\n", 42);
	
	// Negative numbers
	ft_printf("(FT) Test 6: Left-aligned negative with precision: [%-8.5d]\n", -42);
	printf("(IO) Test 6: Left-aligned negative with precision: [%-8.5d]\n", -42);
	ft_printf("(FT) Test 7: Plus with negative and precision: [%+8.5d]\n", -42);
	printf("(IO) Test 7: Plus with negative and precision: [%+8.5d]\n", -42);
	ft_printf("(FT) Test 8: Space with negative and precision: [% 8.5d]\n", -42);
	printf("(IO) Test 8: Space with negative and precision: [% 8.5d]\n", -42);
	ft_printf("(FT) Test 9: Zero-padded negative with precision: [%08.5d]\n", -42);
	printf("(IO) Test 9: Zero-padded negative with precision: [%08.5d]\n", -42);
	
	// Multiple flags
	ft_printf("(FT) Test 10: Multiple flags with precision: [%-+8.5d]\n", 42);
	printf("(IO) Test 10: Multiple flags with precision: [%-+8.5d]\n", 42);
	ft_printf("(FT) Test 11: All flags with precision: [%-+0# 8.5d]\n", 42);
	printf("(IO) Test 11: All flags with precision: [%-+0# 8.5d]\n", 42);
	
	// Zero value
	ft_printf("(FT) Test 12: Zero with flags and precision: [%+8.5d]\n", 0);
	printf("(IO) Test 12: Zero with flags and precision: [%+8.5d]\n", 0);
	ft_printf("(FT) Test 13: Zero with flags and zero precision: [%+8.0d]\n", 0);
	printf("(IO) Test 13: Zero with flags and zero precision: [%+8.0d]\n", 0);
	
	// Test with %i
	ft_printf("(FT) Test 14: %%i with flags and precision: [%-+8.5i]\n", 42);
	printf("(IO) Test 14: %%i with flags and precision: [%-+8.5i]\n", 42);
	ft_printf("(FT) Test 15: %%i zero with flags and zero precision: [%+8.0i]\n", 0);
	printf("(IO) Test 15: %%i zero with flags and zero precision: [%+8.0i]\n", 0);
}

static void	test_decimal_edge_cases(void)
{
	print_test_subheader("Decimal edge cases");
	
	ft_printf("(FT) Test 1: INT_MAX: [%d]\n", INT_MAX);
	printf("(IO) Test 1: INT_MAX: [%d]\n", INT_MAX);
	ft_printf("(FT) Test 2: INT_MIN: [%d]\n", INT_MIN);
	printf("(IO) Test 2: INT_MIN: [%d]\n", INT_MIN);
	ft_printf("(FT) Test 3: INT_MAX with width: [%15d]\n", INT_MAX);
	printf("(IO) Test 3: INT_MAX with width: [%15d]\n", INT_MAX);
	ft_printf("(FT) Test 4: INT_MIN with width: [%15d]\n", INT_MIN);
	printf("(IO) Test 4: INT_MIN with width: [%15d]\n", INT_MIN);
	ft_printf("(FT) Test 5: INT_MAX with precision: [%.15d]\n", INT_MAX);
	printf("(IO) Test 5: INT_MAX with precision: [%.15d]\n", INT_MAX);
	ft_printf("(FT) Test 6: INT_MIN with precision: [%.15d]\n", INT_MIN);
	printf("(IO) Test 6: INT_MIN with precision: [%.15d]\n", INT_MIN);
	ft_printf("(FT) Test 7: INT_MAX with flags: [%+d]\n", INT_MAX);
	printf("(IO) Test 7: INT_MAX with flags: [%+d]\n", INT_MAX);
	ft_printf("(FT) Test 8: INT_MIN with flags: [% d]\n", INT_MIN);
	printf("(IO) Test 8: INT_MIN with flags: [% d]\n", INT_MIN);
	ft_printf("(FT) Test 9: INT_MAX everything: [%-+15.10d]\n", INT_MAX);
	printf("(IO) Test 9: INT_MAX everything: [%-+15.10d]\n", INT_MAX);
	ft_printf("(FT) Test 10: INT_MIN everything: [%-+15.10d]\n", INT_MIN);
	printf("(IO) Test 10: INT_MIN everything: [%-+15.10d]\n", INT_MIN);
	
	// Special zero cases
	ft_printf("(FT) Test 11: Zero with zero precision: [%.0d]\n", 0);
	printf("(IO) Test 11: Zero with zero precision: [%.0d]\n", 0);
	ft_printf("(FT) Test 12: Zero with zero precision and width: [%5.0d]\n", 0);
	printf("(IO) Test 12: Zero with zero precision and width: [%5.0d]\n", 0);
	ft_printf("(FT) Test 13: Zero with zero precision and flags: [%+.0d]\n", 0);
	printf("(IO) Test 13: Zero with zero precision and flags: [%+.0d]\n", 0);
	
	// Test with %i
	ft_printf("(FT) Test 14: %%i INT_MAX: [%i]\n", INT_MAX);
	printf("(IO) Test 14: %%i INT_MAX: [%i]\n", INT_MAX);
	ft_printf("(FT) Test 15: %%i INT_MIN: [%i]\n", INT_MIN);
	printf("(IO) Test 15: %%i INT_MIN: [%i]\n", INT_MIN);
	ft_printf("(FT) Test 16: %%i zero edge cases: [%+5.0i]\n", 0);
	printf("(IO) Test 16: %%i zero edge cases: [%+5.0i]\n", 0);
}

void	test_decimal(void)
{
	print_test_header("decimal (d/i)");
	
	test_basic_decimal();
	test_decimal_with_width();
	test_decimal_with_precision();
	test_decimal_with_width_and_precision();
	test_decimal_with_flags();
	test_decimal_with_flags_and_precision();
	test_decimal_edge_cases();
}