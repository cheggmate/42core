/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ft_printf_tester                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17                              #+#    #+#             */
/*   Updated: 2025/05/17                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"

void	test_hex_basic(void)
{
	print_test_subheader("HEXADECIMAL - BASIC TESTS");
	
	// Basic lowercase hex tests
	ft_printf("(FT) Basic lowercase hex: %x\n", 42);
	printf("(IO) Basic lowercase hex: %x\n", 42);
	ft_printf("(FT) Zero lowercase hex: %x\n", 0);
	printf("(IO) Zero lowercase hex: %x\n", 0);
	ft_printf("(FT) Max int lowercase hex: %x\n", INT_MAX);
	printf("(IO) Max int lowercase hex: %x\n", INT_MAX);
	ft_printf("(FT) Multiple lowercase hex: %x %x %x\n", 42, 0, 255);
	printf("(IO) Multiple lowercase hex: %x %x %x\n", 42, 0, 255);
	
	// Basic uppercase hex tests
	ft_printf("(FT) Basic uppercase hex: %X\n", 42);
	printf("(IO) Basic uppercase hex: %X\n", 42);
	ft_printf("(FT) Zero uppercase hex: %X\n", 0);
	printf("(IO) Zero uppercase hex: %X\n", 0);
	ft_printf("(FT) Max int uppercase hex: %X\n", INT_MAX);
	printf("(IO) Max int uppercase hex: %X\n", INT_MAX);
	ft_printf("(FT) Multiple uppercase hex: %X %X %X\n", 42, 0, 255);
	printf("(IO) Multiple uppercase hex: %X %X %X\n", 42, 0, 255);
	
	// Mix of lowercase and uppercase
	ft_printf("(FT) Mixed case hex: %x %X %x %X\n", 10, 11, 12, 13);
	printf("(IO) Mixed case hex: %x %X %x %X\n", 10, 11, 12, 13);
	
	// Special values, good for testing
	ft_printf("(FT) Value 10 (a/A): Lowercase: %x, Uppercase: %X\n", 10, 10);
	printf("(IO) Value 10 (a/A): Lowercase: %x, Uppercase: %X\n", 10, 10);
	ft_printf("(FT) Value 15 (f/F): Lowercase: %x, Uppercase: %X\n", 15, 15);
	printf("(IO) Value 15 (f/F): Lowercase: %x, Uppercase: %X\n", 15, 15);
	ft_printf("(FT) Value 255 (ff/FF): Lowercase: %x, Uppercase: %X\n", 255, 255);
	printf("(IO) Value 255 (ff/FF): Lowercase: %x, Uppercase: %X\n", 255, 255);
	ft_printf("(FT) Value 4096 (1000): Lowercase: %x, Uppercase: %X\n", 4096, 4096);
	printf("(IO) Value 4096 (1000): Lowercase: %x, Uppercase: %X\n", 4096, 4096);
}

void	test_hex_width(void)
{
	print_test_subheader("HEXADECIMAL - WIDTH TESTS");
	
	// Width tests for lowercase hex
	ft_printf("(FT) Width 10 lowercase: '%10x'\n", 42);
	printf("(IO) Width 10 lowercase: '%10x'\n", 42);
	ft_printf("(FT) Width 10, zero lowercase: '%10x'\n", 0);
	printf("(IO) Width 10, zero lowercase: '%10x'\n", 0);
	ft_printf("(FT) Width 2 (smaller than value) lowercase: '%2x'\n", 255);
	printf("(IO) Width 2 (smaller than value) lowercase: '%2x'\n", 255);
	ft_printf("(FT) Width 10, large value lowercase: '%10x'\n", 0xABCDEF);
	printf("(IO) Width 10, large value lowercase: '%10x'\n", 0xABCDEF);
	
	// Width tests for uppercase hex
	ft_printf("(FT) Width 10 uppercase: '%10X'\n", 42);
	printf("(IO) Width 10 uppercase: '%10X'\n", 42);
	ft_printf("(FT) Width 10, zero uppercase: '%10X'\n", 0);
	printf("(IO) Width 10, zero uppercase: '%10X'\n", 0);
	ft_printf("(FT) Width 2 (smaller than value) uppercase: '%2X'\n", 255);
	printf("(IO) Width 2 (smaller than value) uppercase: '%2X'\n", 255);
	ft_printf("(FT) Width 10, large value uppercase: '%10X'\n", 0xABCDEF);
	printf("(IO) Width 10, large value uppercase: '%10X'\n", 0xABCDEF);
	
	// Width with left justification for lowercase
	ft_printf("(FT) Width 10, left-justified lowercase: '%-10x'\n", 42);
	printf("(IO) Width 10, left-justified lowercase: '%-10x'\n", 42);
	ft_printf("(FT) Width 10, left-justified, zero lowercase: '%-10x'\n", 0);
	printf("(IO) Width 10, left-justified, zero lowercase: '%-10x'\n", 0);
	ft_printf("(FT) Width 10, left-justified, large value lowercase: '%-10x'\n", 0xABCDEF);
	printf("(IO) Width 10, left-justified, large value lowercase: '%-10x'\n", 0xABCDEF);
	
	// Width with left justification for uppercase
	ft_printf("(FT) Width 10, left-justified uppercase: '%-10X'\n", 42);
	printf("(IO) Width 10, left-justified uppercase: '%-10X'\n", 42);
	ft_printf("(FT) Width 10, left-justified, zero uppercase: '%-10X'\n", 0);
	printf("(IO) Width 10, left-justified, zero uppercase: '%-10X'\n", 0);
	ft_printf("(FT) Width 10, left-justified, large value uppercase: '%-10X'\n", 0xABCDEF);
	printf("(IO) Width 10, left-justified, large value uppercase: '%-10X'\n", 0xABCDEF);
	
	// Width with zero padding for lowercase
	ft_printf("(FT) Width 10, zero-padded lowercase: '%010x'\n", 42);
	printf("(IO) Width 10, zero-padded lowercase: '%010x'\n", 42);
	ft_printf("(FT) Width 10, zero-padded, zero lowercase: '%010x'\n", 0);
	printf("(IO) Width 10, zero-padded, zero lowercase: '%010x'\n", 0);
	ft_printf("(FT) Width 10, zero-padded, large value lowercase: '%010x'\n", 0xABCDEF);
	printf("(IO) Width 10, zero-padded, large value lowercase: '%010x'\n", 0xABCDEF);
	
	// Width with zero padding for uppercase
	ft_printf("(FT) Width 10, zero-padded uppercase: '%010X'\n", 42);
	printf("(IO) Width 10, zero-padded uppercase: '%010X'\n", 42);
	ft_printf("(FT) Width 10, zero-padded, zero uppercase: '%010X'\n", 0);
	printf("(IO) Width 10, zero-padded, zero uppercase: '%010X'\n", 0);
	ft_printf("(FT) Width 10, zero-padded, large value uppercase: '%010X'\n", 0xABCDEF);
	printf("(IO) Width 10, zero-padded, large value uppercase: '%010X'\n", 0xABCDEF);
	
	// Zero padding with left justification (left justification should take precedence)
	ft_printf("(FT) Width 10, zero-padded, left-justified lowercase: '%-010x'\n", 42);
	printf("(IO) Width 10, zero-padded, left-justified lowercase: '%-010x'\n", 42);
	ft_printf("(FT) Width 10, zero-padded, left-justified uppercase: '%-010X'\n", 42);
	printf("(IO) Width 10, zero-padded, left-justified uppercase: '%-010X'\n", 42);
}

void	test_hex_precision(void)
{
	print_test_subheader("HEXADECIMAL - PRECISION TESTS");
	
	// Precision tests for lowercase hex
	ft_printf("(FT) Precision 5 lowercase: '%.5x'\n", 42);
	printf("(IO) Precision 5 lowercase: '%.5x'\n", 42);
	ft_printf("(FT) Precision 5, zero lowercase: '%.5x'\n", 0);
	printf("(IO) Precision 5, zero lowercase: '%.5x'\n", 0);
	ft_printf("(FT) Precision 2 (smaller than value) lowercase: '%.2x'\n", 255);
	printf("(IO) Precision 2 (smaller than value) lowercase: '%.2x'\n", 255);
	ft_printf("(FT) Precision 10, large value lowercase: '%.10x'\n", 0xABCDEF);
	printf("(IO) Precision 10, large value lowercase: '%.10x'\n", 0xABCDEF);
	
	// Precision tests for uppercase hex
	ft_printf("(FT) Precision 5 uppercase: '%.5X'\n", 42);
	printf("(IO) Precision 5 uppercase: '%.5X'\n", 42);
	ft_printf("(FT) Precision 5, zero uppercase: '%.5X'\n", 0);
	printf("(IO) Precision 5, zero uppercase: '%.5X'\n", 0);
	ft_printf("(FT) Precision 2 (smaller than value) uppercase: '%.2X'\n", 255);
	printf("(IO) Precision 2 (smaller than value) uppercase: '%.2X'\n", 255);
	ft_printf("(FT) Precision 10, large value uppercase: '%.10X'\n", 0xABCDEF);
	printf("(IO) Precision 10, large value uppercase: '%.10X'\n", 0xABCDEF);
	
	// Precision 0
	ft_printf("(FT) Precision 0, non-zero lowercase: '%.0x'\n", 42);
	printf("(IO) Precision 0, non-zero lowercase: '%.0x'\n", 42);
	ft_printf("(FT) Precision 0, zero lowercase: '%.0x'\n", 0);  // Should print nothing for 0 value
	printf("(IO) Precision 0, zero lowercase: '%.0x'\n", 0);  // Should print nothing for 0 value
	ft_printf("(FT) Precision 0, non-zero uppercase: '%.0X'\n", 42);
	printf("(IO) Precision 0, non-zero uppercase: '%.0X'\n", 42);
	ft_printf("(FT) Precision 0, zero uppercase: '%.0X'\n", 0);  // Should print nothing for 0 value
	printf("(IO) Precision 0, zero uppercase: '%.0X'\n", 0);  // Should print nothing for 0 value
	
	// Precision 0 with explicitly specified value (just a dot)
	ft_printf("(FT) Precision 0, non-zero with explicit dot lowercase: '%.x'\n", 42);
	printf("(IO) Precision 0, non-zero with explicit dot lowercase: '%.x'\n", 42);
	ft_printf("(FT) Precision 0, zero with explicit dot lowercase: '%.x'\n", 0);
	printf("(IO) Precision 0, zero with explicit dot lowercase: '%.x'\n", 0);
	ft_printf("(FT) Precision 0, non-zero with explicit dot uppercase: '%.X'\n", 42);
	printf("(IO) Precision 0, non-zero with explicit dot uppercase: '%.X'\n", 42);
	ft_printf("(FT) Precision 0, zero with explicit dot uppercase: '%.X'\n", 0);
	printf("(IO) Precision 0, zero with explicit dot uppercase: '%.X'\n", 0);
}

void	test_hex_width_precision(void)
{
	print_test_subheader("HEXADECIMAL - WIDTH AND PRECISION TESTS");
	
	// Width and precision for lowercase hex
	ft_printf("(FT) Width 10, Precision 5 lowercase: '%10.5x'\n", 42);
	printf("(IO) Width 10, Precision 5 lowercase: '%10.5x'\n", 42);
	ft_printf("(FT) Width 10, Precision 5, zero lowercase: '%10.5x'\n", 0);
	printf("(IO) Width 10, Precision 5, zero lowercase: '%10.5x'\n", 0);
	ft_printf("(FT) Width 5, Precision 10 lowercase: '%5.10x'\n", 42);
	printf("(IO) Width 5, Precision 10 lowercase: '%5.10x'\n", 42);
	ft_printf("(FT) Width 10, Precision 0, non-zero lowercase: '%10.0x'\n", 42);
	printf("(IO) Width 10, Precision 0, non-zero lowercase: '%10.0x'\n", 42);
	ft_printf("(FT) Width 10, Precision 0, zero lowercase: '%10.0x'\n", 0);
	printf("(IO) Width 10, Precision 0, zero lowercase: '%10.0x'\n", 0);
	
	// Width and precision for uppercase hex
	ft_printf("(FT) Width 10, Precision 5 uppercase: '%10.5X'\n", 42);
	printf("(IO) Width 10, Precision 5 uppercase: '%10.5X'\n", 42);
	ft_printf("(FT) Width 10, Precision 5, zero uppercase: '%10.5X'\n", 0);
	printf("(IO) Width 10, Precision 5, zero uppercase: '%10.5X'\n", 0);
	ft_printf("(FT) Width 5, Precision 10 uppercase: '%5.10X'\n", 42);
	printf("(IO) Width 5, Precision 10 uppercase: '%5.10X'\n", 42);
	ft_printf("(FT) Width 10, Precision 0, non-zero uppercase: '%10.0X'\n", 42);
	printf("(IO) Width 10, Precision 0, non-zero uppercase: '%10.0X'\n", 42);
	ft_printf("(FT) Width 10, Precision 0, zero uppercase: '%10.0X'\n", 0);
	printf("(IO) Width 10, Precision 0, zero uppercase: '%10.0X'\n", 0);
	
	// Width and precision with left justification for lowercase
	ft_printf("(FT) Width 10, Precision 5, left-justified lowercase: '%-10.5x'\n", 42);
	printf("(IO) Width 10, Precision 5, left-justified lowercase: '%-10.5x'\n", 42);
	ft_printf("(FT) Width 10, Precision 5, left-justified, zero lowercase: '%-10.5x'\n", 0);
	printf("(IO) Width 10, Precision 5, left-justified, zero lowercase: '%-10.5x'\n", 0);
	ft_printf("(FT) Width 5, Precision 10, left-justified lowercase: '%-5.10x'\n", 42);
	printf("(IO) Width 5, Precision 10, left-justified lowercase: '%-5.10x'\n", 42);
	
	// Width and precision with left justification for uppercase
	ft_printf("(FT) Width 10, Precision 5, left-justified uppercase: '%-10.5X'\n", 42);
	printf("(IO) Width 10, Precision 5, left-justified uppercase: '%-10.5X'\n", 42);
	ft_printf("(FT) Width 10, Precision 5, left-justified, zero uppercase: '%-10.5X'\n", 0);
	printf("(IO) Width 10, Precision 5, left-justified, zero uppercase: '%-10.5X'\n", 0);
	ft_printf("(FT) Width 5, Precision 10, left-justified uppercase: '%-5.10X'\n", 42);
	printf("(IO) Width 5, Precision 10, left-justified uppercase: '%-5.10X'\n", 42);
	
	// Width, precision and zero padding (precision should override zero padding)
	ft_printf("(FT) Width 10, Precision 5, zero-padded lowercase: '%010.5x'\n", 42);
	printf("(IO) Width 10, Precision 5, zero-padded lowercase: '%010.5x'\n", 42);
	ft_printf("(FT) Width 10, Precision 5, zero-padded uppercase: '%010.5X'\n", 42);
	printf("(IO) Width 10, Precision 5, zero-padded uppercase: '%010.5X'\n", 42);
}

void	test_hex_hash_flag(void)
{
	print_test_subheader("HEXADECIMAL - HASH FLAG TESTS");
	
	// Hash flag adds "0x" prefix for lowercase hex
	ft_printf("(FT) Hash flag lowercase: '%#x'\n", 42);
	printf("(IO) Hash flag lowercase: '%#x'\n", 42);
	ft_printf("(FT) Hash flag, zero lowercase: '%#x'\n", 0);  // No prefix for zero
	printf("(IO) Hash flag, zero lowercase: '%#x'\n", 0);  // No prefix for zero
	ft_printf("(FT) Hash flag uppercase: '%#X'\n", 42);       // Should add "0X"
	printf("(IO) Hash flag uppercase: '%#X'\n", 42);       // Should add "0X"
	ft_printf("(FT) Hash flag, zero uppercase: '%#X'\n", 0);  // No prefix for zero
	printf("(IO) Hash flag, zero uppercase: '%#X'\n", 0);  // No prefix for zero
	
	// Hash flag with width
	ft_printf("(FT) Hash flag with width 10 lowercase: '%#10x'\n", 42);
	printf("(IO) Hash flag with width 10 lowercase: '%#10x'\n", 42);
	ft_printf("(FT) Hash flag with width 10 uppercase: '%#10X'\n", 42);
	printf("(IO) Hash flag with width 10 uppercase: '%#10X'\n", 42);
	ft_printf("(FT) Hash flag with width 10, zero lowercase: '%#10x'\n", 0);
	printf("(IO) Hash flag with width 10, zero lowercase: '%#10x'\n", 0);
	ft_printf("(FT) Hash flag with width 10, zero uppercase: '%#10X'\n", 0);
	printf("(IO) Hash flag with width 10, zero uppercase: '%#10X'\n", 0);
	
	// Hash flag with left-justification
	ft_printf("(FT) Hash flag with width 10, left-justified lowercase: '%#-10x'\n", 42);
	printf("(IO) Hash flag with width 10, left-justified lowercase: '%#-10x'\n", 42);
	ft_printf("(FT) Hash flag with width 10, left-justified uppercase: '%#-10X'\n", 42);
	printf("(IO) Hash flag with width 10, left-justified uppercase: '%#-10X'\n", 42);
	
	// Hash flag with zero padding
	ft_printf("(FT) Hash flag with width 10, zero-padded lowercase: '%#010x'\n", 42);
	printf("(IO) Hash flag with width 10, zero-padded lowercase: '%#010x'\n", 42);
	ft_printf("(FT) Hash flag with width 10, zero-padded uppercase: '%#010X'\n", 42);
	printf("(IO) Hash flag with width 10, zero-padded uppercase: '%#010X'\n", 42);
	
	// Hash flag with precision
	ft_printf("(FT) Hash flag with precision 5 lowercase: '%#.5x'\n", 42);
	printf("(IO) Hash flag with precision 5 lowercase: '%#.5x'\n", 42);
	ft_printf("(FT) Hash flag with precision 5 uppercase: '%#.5X'\n", 42);
	printf("(IO) Hash flag with precision 5 uppercase: '%#.5X'\n", 42);
	ft_printf("(FT) Hash flag with precision 0, non-zero lowercase: '%#.0x'\n", 42);
	printf("(IO) Hash flag with precision 0, non-zero lowercase: '%#.0x'\n", 42);
	ft_printf("(FT) Hash flag with precision 0, zero lowercase: '%#.0x'\n", 0);
	printf("(IO) Hash flag with precision 0, zero lowercase: '%#.0x'\n", 0);
	
	// Hash flag with width and precision
	ft_printf("(FT) Hash flag with width 10, precision 5 lowercase: '%#10.5x'\n", 42);
	printf("(IO) Hash flag with width 10, precision 5 lowercase: '%#10.5x'\n", 42);
	ft_printf("(FT) Hash flag with width 10, precision 5 uppercase: '%#10.5X'\n", 42);
	printf("(IO) Hash flag with width 10, precision 5 uppercase: '%#10.5X'\n", 42);
	ft_printf("(FT) Hash flag with width 10, precision 0, zero lowercase: '%#10.0x'\n", 0);
	printf("(IO) Hash flag with width 10, precision 0, zero lowercase: '%#10.0x'\n", 0);
	ft_printf("(FT) Hash flag with width 10, precision 0, zero uppercase: '%#10.0X'\n", 0);
	printf("(IO) Hash flag with width 10, precision 0, zero uppercase: '%#10.0X'\n", 0);
}

void	test_hex_flag_combinations(void)
{
	print_test_subheader("HEXADECIMAL - FLAG COMBINATIONS");
	
	// Testing valid flag combinations for hex
	// Note: '+' and ' ' flags are not applicable for hex values
	// but let's test them anyway to ensure they are properly ignored
	
	// Plus and space flags (should be ignored)
	ft_printf("(FT) Plus flag (should be ignored) lowercase: '%+x'\n", 42);
	printf("(IO) Plus flag (should be ignored) lowercase: '%+x'\n", 42);
	ft_printf("(FT) Space flag (should be ignored) lowercase: '% x'\n", 42);
	printf("(IO) Space flag (should be ignored) lowercase: '% x'\n", 42);
	ft_printf("(FT) Plus flag (should be ignored) uppercase: '%+X'\n", 42);
	printf("(IO) Plus flag (should be ignored) uppercase: '%+X'\n", 42);
	ft_printf("(FT) Space flag (should be ignored) uppercase: '% X'\n", 42);
	printf("(IO) Space flag (should be ignored) uppercase: '% X'\n", 42);
	
	// Zero flag
	ft_printf("(FT) Zero flag with width lowercase: '%05x'\n", 42);
	printf("(IO) Zero flag with width lowercase: '%05x'\n", 42);
	ft_printf("(FT) Zero flag with width uppercase: '%05X'\n", 42);
	printf("(IO) Zero flag with width uppercase: '%05X'\n", 42);
	
	// Zero flag with hash flag
	ft_printf("(FT) Zero flag with hash and width lowercase: '%#05x'\n", 42);
	printf("(IO) Zero flag with hash and width lowercase: '%#05x'\n", 42);
	ft_printf("(FT) Zero flag with hash and width uppercase: '%#05X'\n", 42);
	printf("(IO) Zero flag with hash and width uppercase: '%#05X'\n", 42);
	
	// Zero flag with precision (precision should override zero flag)
	ft_printf("(FT) Zero flag with width and precision lowercase: '%05.3x'\n", 42);
	printf("(IO) Zero flag with width and precision lowercase: '%05.3x'\n", 42);
	ft_printf("(FT) Zero flag with width and precision uppercase: '%05.3X'\n", 42);
	printf("(IO) Zero flag with width and precision uppercase: '%05.3X'\n", 42);
	
	// Minus flag (left justification)
	ft_printf("(FT) Minus flag with width lowercase: '%-5x'\n", 42);
	printf("(IO) Minus flag with width lowercase: '%-5x'\n", 42);
	ft_printf("(FT) Minus flag with width uppercase: '%-5X'\n", 42);
	printf("(IO) Minus flag with width uppercase: '%-5X'\n", 42);
	
	// Minus and zero flags together (minus should override zero)
	ft_printf("(FT) Minus and zero flags with width lowercase: '%-05x'\n", 42);
	printf("(IO) Minus and zero flags with width lowercase: '%-05x'\n", 42);
	ft_printf("(FT) Minus and zero flags with width uppercase: '%-05X'\n", 42);
	printf("(IO) Minus and zero flags with width uppercase: '%-05X'\n", 42);
	
	// Minus flag with hash flag
	ft_printf("(FT) Minus flag with hash and width lowercase: '%#-10x'\n", 42);
	printf("(IO) Minus flag with hash and width lowercase: '%#-10x'\n", 42);
	ft_printf("(FT) Minus flag with hash and width uppercase: '%#-10X'\n", 42);
	printf("(IO) Minus flag with hash and width uppercase: '%#-10X'\n", 42);
	
	// Multiple flags
	ft_printf("(FT) All flags lowercase: '%+-0# 10.5x'\n", 42);
	printf("(IO) All flags lowercase: '%+-0# 10.5x'\n", 42);
	ft_printf("(FT) All flags uppercase: '%+-0# 10.5X'\n", 42);
	printf("(IO) All flags uppercase: '%+-0# 10.5X'\n", 42);
}

void	test_hex_edge_cases(void)
{
	print_test_subheader("HEXADECIMAL - EDGE CASES");
	
	// Edge cases
	ft_printf("(FT) INT_MAX lowercase: '%x'\n", INT_MAX);
	printf("(IO) INT_MAX lowercase: '%x'\n", INT_MAX);
	ft_printf("(FT) INT_MAX uppercase: '%X'\n", INT_MAX);
	printf("(IO) INT_MAX uppercase: '%X'\n", INT_MAX);
	ft_printf("(FT) UINT_MAX lowercase: '%x'\n", UINT_MAX);
	printf("(IO) UINT_MAX lowercase: '%x'\n", UINT_MAX);
	ft_printf("(FT) UINT_MAX uppercase: '%X'\n", UINT_MAX);
	printf("(IO) UINT_MAX uppercase: '%X'\n", UINT_MAX);
	
	// INT_MAX with formatting
	ft_printf("(FT) INT_MAX with width lowercase: '%15x'\n", INT_MAX);
	printf("(IO) INT_MAX with width lowercase: '%15x'\n", INT_MAX);
	ft_printf("(FT) INT_MAX with precision lowercase: '%.15x'\n", INT_MAX);
	printf("(IO) INT_MAX with precision lowercase: '%.15x'\n", INT_MAX);
	ft_printf("(FT) INT_MAX with hash flag lowercase: '%#x'\n", INT_MAX);
	printf("(IO) INT_MAX with hash flag lowercase: '%#x'\n", INT_MAX);
	ft_printf("(FT) INT_MAX with width, precision, hash lowercase: '%#20.15x'\n", INT_MAX);
	printf("(IO) INT_MAX with width, precision, hash lowercase: '%#20.15x'\n", INT_MAX);
	
	// UINT_MAX with formatting
	ft_printf("(FT) UINT_MAX with width uppercase: '%15X'\n", UINT_MAX);
	printf("(IO) UINT_MAX with width uppercase: '%15X'\n", UINT_MAX);
	ft_printf("(FT) UINT_MAX with precision uppercase: '%.15X'\n", UINT_MAX);
	printf("(IO) UINT_MAX with precision uppercase: '%.15X'\n", UINT_MAX);
	ft_printf("(FT) UINT_MAX with hash flag uppercase: '%#X'\n", UINT_MAX);
	printf("(IO) UINT_MAX with hash flag uppercase: '%#X'\n", UINT_MAX);
	ft_printf("(FT) UINT_MAX with width, precision, hash uppercase: '%#20.15X'\n", UINT_MAX);
	printf("(IO) UINT_MAX with width, precision, hash uppercase: '%#20.15X'\n", UINT_MAX);
	
	// Small hex value with large precision
	ft_printf("(FT) Small value with large precision lowercase: '%.20x'\n", 42);
	printf("(IO) Small value with large precision lowercase: '%.20x'\n", 42);
	ft_printf("(FT) Small value with large precision uppercase: '%.20X'\n", 42);
	printf("(IO) Small value with large precision uppercase: '%.20X'\n", 42);
	
	// Zero with different formats
	ft_printf("(FT) Zero with width lowercase: '%5x'\n", 0);
	printf("(IO) Zero with width lowercase: '%5x'\n", 0);
	ft_printf("(FT) Zero with precision lowercase: '%.5x'\n", 0);
	printf("(IO) Zero with precision lowercase: '%.5x'\n", 0);
	ft_printf("(FT) Zero with hash flag lowercase: '%#x'\n", 0);  // Should not add prefix for 0
	printf("(IO) Zero with hash flag lowercase: '%#x'\n", 0);  // Should not add prefix for 0
	ft_printf("(FT) Zero with width, precision, hash lowercase: '%#10.5x'\n", 0);
	printf("(IO) Zero with width, precision, hash lowercase: '%#10.5x'\n", 0);
	
	// Same tests for uppercase
	ft_printf("(FT) Zero with width uppercase: '%5X'\n", 0);
	printf("(IO) Zero with width uppercase: '%5X'\n", 0);
	ft_printf("(FT) Zero with precision uppercase: '%.5X'\n", 0);
	printf("(IO) Zero with precision uppercase: '%.5X'\n", 0);
	ft_printf("(FT) Zero with hash flag uppercase: '%#X'\n", 0);  // Should not add prefix for 0
	printf("(IO) Zero with hash flag uppercase: '%#X'\n", 0);  // Should not add prefix for 0
	ft_printf("(FT) Zero with width, precision, hash uppercase: '%#10.5X'\n", 0);
	printf("(IO) Zero with width, precision, hash uppercase: '%#10.5X'\n", 0);
	
	// Unusual combinations
	ft_printf("(FT) Width 0, Precision 0, zero value lowercase: '%0.0x'\n", 0);
	printf("(IO) Width 0, Precision 0, zero value lowercase: '%0.0x'\n", 0);
	ft_printf("(FT) Width 1, Precision 0, zero value lowercase: '%1.0x'\n", 0);
	printf("(IO) Width 1, Precision 0, zero value lowercase: '%1.0x'\n", 0);
	ft_printf("(FT) Width 0, Precision 0, zero value uppercase: '%0.0X'\n", 0);
	printf("(IO) Width 0, Precision 0, zero value uppercase: '%0.0X'\n", 0);
	ft_printf("(FT) Width 1, Precision 0, zero value uppercase: '%1.0X'\n", 0);
	printf("(IO) Width 1, Precision 0, zero value uppercase: '%1.0X'\n", 0);
}

void	test_hex(void)
{
	test_hex_basic();
	test_hex_width();
	test_hex_precision();
	test_hex_width_precision();
	test_hex_hash_flag();
	test_hex_flag_combinations();
	test_hex_edge_cases();
}
