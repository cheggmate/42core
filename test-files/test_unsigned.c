/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ft_printf_tester                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17                              #+#    #+#             */
/*   Updated: 2025/05/17                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"

void	test_unsigned_basic(void)
{
	print_test_subheader("UNSIGNED INTEGER - BASIC TESTS");
	
	// Basic unsigned integer tests
	ft_printf("(FT) Basic unsigned: %u\n", 42);
	printf("(IO) Basic unsigned: %u\n", 42);
	ft_printf("(FT) Zero unsigned: %u\n", 0);
	printf("(IO) Zero unsigned: %u\n", 0);
	ft_printf("(FT) Max unsigned int: %u\n", UINT_MAX);
	printf("(IO) Max unsigned int: %u\n", UINT_MAX);
	ft_printf("(FT) Multiple unsigned: %u %u %u\n", 42, 0, 4242);
	printf("(IO) Multiple unsigned: %u %u %u\n", 42, 0, 4242);
	
	// Basic with larger values
	ft_printf("(FT) Large value: %u\n", 999999999);
	printf("(IO) Large value: %u\n", 999999999);
	ft_printf("(FT) Large value: %u\n", 4294967295u); // UINT_MAX for 32-bit systems
	printf("(IO) Large value: %u\n", 4294967295u); // UINT_MAX for 32-bit systems

}

void	test_unsigned_width(void)
{
	print_test_subheader("UNSIGNED INTEGER - WIDTH TESTS");
	
	// Width tests
	ft_printf("(FT) Width 10: '%10u'\n", 42);
	printf("(IO) Width 10: '%10u'\n", 42);
	ft_printf("(FT) Width 10, zero: '%10u'\n", 0);
	printf("(IO) Width 10, zero: '%10u'\n", 0);
	ft_printf("(FT) Width 2 (smaller than value): '%2u'\n", 42);
	printf("(IO) Width 2 (smaller than value): '%2u'\n", 42);
	ft_printf("(FT) Width 20: '%20u'\n", 12345);
	printf("(IO) Width 20: '%20u'\n", 12345);
	ft_printf("(FT) Width 20, large value: '%20u'\n", 4294967295u);
	printf("(IO) Width 20, large value: '%20u'\n", 4294967295u);
	
	// Width with left justification
	ft_printf("(FT) Width 10, left-justified: '%-10u'\n", 42);
	printf("(IO) Width 10, left-justified: '%-10u'\n", 42);
	ft_printf("(FT) Width 10, left-justified, zero: '%-10u'\n", 0);
	printf("(IO) Width 10, left-justified, zero: '%-10u'\n", 0);
	ft_printf("(FT) Width 20, left-justified: '%-20u'\n", 12345);
	printf("(IO) Width 20, left-justified: '%-20u'\n", 12345);
	
	// Width with zero padding
	ft_printf("(FT) Width 10, zero-padded: '%010u'\n", 42);
	printf("(IO) Width 10, zero-padded: '%010u'\n", 42);
	ft_printf("(FT) Width 10, zero-padded, zero value: '%010u'\n", 0);
	printf("(IO) Width 10, zero-padded, zero value: '%010u'\n", 0);
	ft_printf("(FT) Width 20, zero-padded: '%020u'\n", 12345);
	printf("(IO) Width 20, zero-padded: '%020u'\n", 12345);
	
	// Zero padding with left justification (left justification should take precedence)
	ft_printf("(FT) Width 10, zero-padded, left-justified: '%-010u'\n", 42);
	printf("(IO) Width 10, zero-padded, left-justified: '%-010u'\n", 42);
	ft_printf("(FT) Width 20, zero-padded, left-justified: '%-020u'\n", 12345);
	printf("(IO) Width 20, zero-padded, left-justified: '%-020u'\n", 12345);

}

void	test_unsigned_precision(void)
{
	print_test_subheader("UNSIGNED INTEGER - PRECISION TESTS");
	
	// Precision tests
	ft_printf("(FT) Precision 5: '%.5u'\n", 42);
	printf("(IO) Precision 5: '%.5u'\n", 42);
	ft_printf("(FT) Precision 5, zero: '%.5u'\n", 0);
	printf("(IO) Precision 5, zero: '%.5u'\n", 0);
	ft_printf("(FT) Precision 2 (smaller than value): '%.2u'\n", 42);
	printf("(IO) Precision 2 (smaller than value): '%.2u'\n", 42);
	ft_printf("(FT) Precision 10: '%.10u'\n", 12345);
	printf("(IO) Precision 10: '%.10u'\n", 12345);
	
	// Precision 0
	ft_printf("(FT) Precision 0, non-zero: '%.0u'\n", 42);
	printf("(IO) Precision 0, non-zero: '%.0u'\n", 42);
	ft_printf("(FT) Precision 0, zero: '%.0u'\n", 0);  // Should print nothing for 0 value
	printf("(IO) Precision 0, zero: '%.0u'\n", 0);  // Should print nothing for 0 value
	
	// Precision 0 with explicitly specified value
	ft_printf("(FT) Precision 0, non-zero with explicit dot: '%.u'\n", 42);
	printf("(IO) Precision 0, non-zero with explicit dot: '%.u'\n", 42);
	ft_printf("(FT) Precision 0, zero with explicit dot: '%.u'\n", 0);  // Should print nothing for 0 value
	printf("(IO) Precision 0, zero with explicit dot: '%.u'\n", 0);  // Should print nothing for 0 value

}

void	test_unsigned_width_precision(void)
{
	print_test_subheader("UNSIGNED INTEGER - WIDTH AND PRECISION TESTS");
	
	// Width and precision
	ft_printf("(FT) Width 10, Precision 5: '%10.5u'\n", 42);
	printf("(IO) Width 10, Precision 5: '%10.5u'\n", 42);
	ft_printf("(FT) Width 10, Precision 5, zero: '%10.5u'\n", 0);
	printf("(IO) Width 10, Precision 5, zero: '%10.5u'\n", 0);
	ft_printf("(FT) Width 5, Precision 10: '%5.10u'\n", 42);
	printf("(IO) Width 5, Precision 10: '%5.10u'\n", 42);
	ft_printf("(FT) Width 10, Precision 0, non-zero: '%10.0u'\n", 42);
	printf("(IO) Width 10, Precision 0, non-zero: '%10.0u'\n", 42);
	ft_printf("(FT) Width 10, Precision 0, zero: '%10.0u'\n", 0);  // Should print 10 spaces
	printf("(IO) Width 10, Precision 0, zero: '%10.0u'\n", 0);  // Should print 10 spaces
	
	// Width and precision with left justification
	ft_printf("(FT) Width 10, Precision 5, left-justified: '%-10.5u'\n", 42);
	printf("(IO) Width 10, Precision 5, left-justified: '%-10.5u'\n", 42);
	ft_printf("(FT) Width 10, Precision 5, left-justified, zero: '%-10.5u'\n", 0);
	printf("(IO) Width 10, Precision 5, left-justified, zero: '%-10.5u'\n", 0);
	ft_printf("(FT) Width 5, Precision 10, left-justified: '%-5.10u'\n", 42);
	printf("(IO) Width 5, Precision 10, left-justified: '%-5.10u'\n", 42);
	
	// Width, precision and zero padding (precision should overrule zero padding)
	ft_printf("(FT) Width 10, Precision 5, zero-padded: '%010.5u'\n", 42);
	printf("(IO) Width 10, Precision 5, zero-padded: '%010.5u'\n", 42);
	ft_printf("(FT) Width 10, Precision 0, zero-padded, non-zero: '%010.0u'\n", 42);
	printf("(IO) Width 10, Precision 0, zero-padded, non-zero: '%010.0u'\n", 42);
	ft_printf("(FT) Width 10, Precision 0, zero-padded, zero: '%010.0u'\n", 0);
	printf("(IO) Width 10, Precision 0, zero-padded, zero: '%010.0u'\n", 0);

}

void	test_unsigned_edge_cases(void)
{
	print_test_subheader("UNSIGNED INTEGER - EDGE CASES");
	
	// Edge cases
	ft_printf("(FT) UINT_MAX: '%u'\n", UINT_MAX);
	printf("(IO) UINT_MAX: '%u'\n", UINT_MAX);
	ft_printf("(FT) UINT_MAX with width: '%20u'\n", UINT_MAX);
	printf("(IO) UINT_MAX with width: '%20u'\n", UINT_MAX);
	ft_printf("(FT) UINT_MAX with precision: '%.20u'\n", UINT_MAX);
	printf("(IO) UINT_MAX with precision: '%.20u'\n", UINT_MAX);
	ft_printf("(FT) UINT_MAX with width and precision: '%25.20u'\n", UINT_MAX);
	printf("(IO) UINT_MAX with width and precision: '%25.20u'\n", UINT_MAX);
	
	// Small unsigned value with large precision
	ft_printf("(FT) Small value with large precision: '%.30u'\n", 42);
	printf("(IO) Small value with large precision: '%.30u'\n", 42);
	
	// Zero with different formats
	ft_printf("(FT) Zero with width 5: '%5u'\n", 0);
	printf("(IO) Zero with width 5: '%5u'\n", 0);
	ft_printf("(FT) Zero with precision 5: '%.5u'\n", 0);
	printf("(IO) Zero with precision 5: '%.5u'\n", 0);
	ft_printf("(FT) Zero with width 5, precision 0: '%5.0u'\n", 0);
	printf("(IO) Zero with width 5, precision 0: '%5.0u'\n", 0);
	ft_printf("(FT) Zero with width 5, precision 0 (dot only): '%5.u'\n", 0);
	printf("(IO) Zero with width 5, precision 0 (dot only): '%5.u'\n", 0);
	
	// Unusual combinations
	ft_printf("(FT) Width 0, Precision 0, zero value: '%0.0u'\n", 0);
	printf("(IO) Width 0, Precision 0, zero value: '%0.0u'\n", 0);
	ft_printf("(FT) Width 1, Precision 0, zero value: '%1.0u'\n", 0);
	printf("(IO) Width 1, Precision 0, zero value: '%1.0u'\n", 0);

}

void	test_unsigned_flag_combinations(void)
{
	print_test_subheader("UNSIGNED INTEGER - FLAG COMBINATIONS");
	
	// Testing valid flag combinations for unsigned
	// Note: '+' and ' ' flags are not applicable for unsigned values
	// but let's test them anyway to ensure they are properly ignored
	
	ft_printf("(FT) Plus flag (should be ignored): '%+u'\n", 42);
	printf("(IO) Plus flag (should be ignored): '%+u'\n", 42);
	ft_printf("(FT) Space flag (should be ignored): '% u'\n", 42);
	printf("(IO) Space flag (should be ignored): '% u'\n", 42);
	
	// Zero flag
	ft_printf("(FT) Zero flag with width: '%05u'\n", 42);
	printf("(IO) Zero flag with width: '%05u'\n", 42);
	ft_printf("(FT) Zero flag with width, zero value: '%05u'\n", 0);
	printf("(IO) Zero flag with width, zero value: '%05u'\n", 0);
	
	// Zero flag with precision (precision should override zero flag)
	ft_printf("(FT) Zero flag with width and precision: '%010.5u'\n", 42);
	printf("(IO) Zero flag with width and precision: '%010.5u'\n", 42);
	
	// Minus flag (left justification)
	ft_printf("(FT) Minus flag with width: '%-10u'\n", 42);
	printf("(IO) Minus flag with width: '%-10u'\n", 42);
	
	// Minus and zero flags together (minus should override zero)
	ft_printf("(FT) Minus and zero flags with width: '%-010u'\n", 42);
	printf("(IO) Minus and zero flags with width: '%-010u'\n", 42);
	
	// Hash flag (should be ignored for unsigned decimal)
	ft_printf("(FT) Hash flag (should be ignored): '%#u'\n", 42);
	printf("(IO) Hash flag (should be ignored): '%#u'\n", 42);
	ft_printf("(FT) Hash flag with width (should be ignored): '%#10u'\n", 42);
	printf("(IO) Hash flag with width (should be ignored): '%#10u'\n", 42);
	ft_printf("(FT) Hash flag with precision (should be ignored): '%#.10u'\n", 42);
	printf("(IO) Hash flag with precision (should be ignored): '%#.10u'\n", 42);
	
	// Multiple flags
	ft_printf("(FT) All flags (many should be ignored): '%+-0# 10.5u'\n", 42);
	printf("(IO) All flags (many should be ignored): '%+-0# 10.5u'\n", 42);

}

void	test_unsigned(void)
{
	test_unsigned_basic();
	test_unsigned_width();
	test_unsigned_precision();
	test_unsigned_width_precision();
	test_unsigned_edge_cases();
	test_unsigned_flag_combinations();
}
