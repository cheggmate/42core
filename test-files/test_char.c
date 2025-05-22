/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/05/18 10:38:40 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"

static void	test_basic_char(void)
{
	print_test_subheader("Basic character tests");
	
	ft_printf("(FT) Test 1: Simple character: [%c]\n", 'a');
	printf("(IO) Test 1: Simple character: [%c]\n", 'a');
	ft_printf("(FT) Test 2: Digit character: [%c]\n", '0');
	printf("(IO) Test 2: Digit character: [%c]\n", '0');
	ft_printf("(FT) Test 3: Special character: [%c]\n", '*');
	printf("(IO) Test 3: Special character: [%c]\n", '*');
	ft_printf("(FT) Test 4: Space character: [%c]\n", ' ');
	printf("(IO) Test 4: Space character: [%c]\n", ' ');
	ft_printf("(FT) Test 5: Newline character: [%c]\n", '\n');
	printf("(IO) Test 5: Newline character: [%c]\n", '\n');
	ft_printf("(FT) Test 6: Tab character: [%c]\n", '\t');
	printf("(IO) Test 6: Tab character: [%c]\n", '\t');
	ft_printf("(FT) Test 7: Multiple characters: [%c%c%c]\n", 'a', 'b', 'c');
	printf("(IO) Test 7: Multiple characters: [%c%c%c]\n", 'a', 'b', 'c');
}

static void	test_char_with_width(void)
{
	print_test_subheader("Character with width");
	
	ft_printf("(FT) Test 1: Width 1 (exact fit): [%1c]\n", 'x');
	printf("(IO) Test 1: Width 1 (exact fit): [%1c]\n", 'x');
	ft_printf("(FT) Test 2: Width 5: [%5c]\n", 'x');
	printf("(IO) Test 2: Width 5: [%5c]\n", 'x');
	ft_printf("(FT) Test 3: Width 10: [%10c]\n", 'x');
	printf("(IO) Test 3: Width 10: [%10c]\n", 'x');
	ft_printf("(FT) Test 4: Width 0: [%0c]\n", 'x');
	printf("(IO) Test 4: Width 0: [%0c]\n", 'x');
	ft_printf("(FT) Test 5: Width 0 with null char: [%0c]\n", '\0');
	printf("(IO) Test 5: Width 0 with null char: [%0c]\n", '\0');
}

static void	test_char_with_flags(void)
{
	print_test_subheader("Character with flags");
	
	// For %c only the minus flag should have an effect
	ft_printf("(FT) Test 1: With minus flag (left-align): [%-5c]\n", 'a');
	printf("(IO) Test 1: With minus flag (left-align): [%-5c]\n", 'a');
	ft_printf("(FT) Test 2: With zero flag: [%05c]\n", 'a');
	printf("(IO) Test 2: With zero flag: [%05c]\n", 'a');
	ft_printf("(FT) Test 3: Width 10 with minus: [%-10c]\n", 'a');
	printf("(IO) Test 3: Width 10 with minus: [%-10c]\n", 'a');
	
	// These flags shouldn't affect %c but should be tested
	ft_printf("(FT) Test 4: With plus flag: [%+5c]\n", 'a');
	printf("(IO) Test 4: With plus flag: [%+5c]\n", 'a');
	ft_printf("(FT) Test 5: With space flag: [% 5c]\n", 'a');
	printf("(IO) Test 5: With space flag: [% 5c]\n", 'a');
	ft_printf("(FT) Test 6: With hash flag: [%#5c]\n", 'a');
	printf("(IO) Test 6: With hash flag: [%#5c]\n", 'a');
	
	// Combining flags
	ft_printf("(FT) Test 7: Minus + zero (minus should take precedence): [%-05c]\n", 'a');
	printf("(IO) Test 7: Minus + zero (minus should take precedence): [%-05c]\n", 'a');
	ft_printf("(FT) Test 8: All flags: [%-+0# 10c]\n", 'a');
	printf("(IO) Test 8: All flags: [%-+0# 10c]\n", 'a');
}

static void	test_char_with_precision(void)
{
	print_test_subheader("Character with precision");
	
	// Precision technically shouldn't affect %c but let's test anyway
	ft_printf("(FT) Test 1: Precision 5: [%.5c]\n", 'a');
	printf("(IO) Test 1: Precision 5: [%.5c]\n", 'a');
	ft_printf("(FT) Test 2: Precision 0: [%.0c]\n", 'a');
	printf("(IO) Test 2: Precision 0: [%.0c]\n", 'a');
	ft_printf("(FT) Test 3: Width 10 + Precision 5: [%10.5c]\n", 'a');
	printf("(IO) Test 3: Width 10 + Precision 5: [%10.5c]\n", 'a');
	ft_printf("(FT) Test 4: Width 5 + Precision 10: [%5.10c]\n", 'a');
	printf("(IO) Test 4: Width 5 + Precision 10: [%5.10c]\n", 'a');
	
	// Precision with flags
	ft_printf("(FT) Test 5: Left-aligned + precision: [%-10.5c]\n", 'a');
	printf("(IO) Test 5: Left-aligned + precision: [%-10.5c]\n", 'a');
	ft_printf("(FT) Test 6: Zero flag + precision: [%010.5c]\n", 'a');
	printf("(IO) Test 6: Zero flag + precision: [%010.5c]\n", 'a');
}

static void	test_char_edge_cases(void)
{
	print_test_subheader("Character edge cases");
	
	ft_printf("(FT) Test 1: Null character: [%c]\n", '\0');
	printf("(IO) Test 1: Null character: [%c]\n", '\0');
	ft_printf("(FT) Test 2: Null with width: [%5c]\n", '\0');
	printf("(IO) Test 2: Null with width: [%5c]\n", '\0');
	ft_printf("(FT) Test 3: Null left-aligned: [%-5c]\n", '\0');
	printf("(IO) Test 3: Null left-aligned: [%-5c]\n", '\0');
	ft_printf("(FT) Test 4: ASCII 127 (DEL): [%c]\n", 127);
	printf("(IO) Test 4: ASCII 127 (DEL): [%c]\n", 127);
	ft_printf("(FT) Test 5: ASCII 31 (control char): [%c]\n", 31);
	printf("(IO) Test 5: ASCII 31 (control char): [%c]\n", 31);
	ft_printf("(FT) Test 6: Visible character surrounded by nulls: [%c%c%c]\n", '\0', 'X', '\0');
	printf("(IO) Test 6: Visible character surrounded by nulls: [%c%c%c]\n", '\0', 'X', '\0');
	
	// Test with numeric values that translate to ASCII
	ft_printf("(FT) Test 7: Decimal 65 (ASCII 'A'): [%c]\n", 65);
	printf("(IO) Test 7: Decimal 65 (ASCII 'A'): [%c]\n", 65);
	ft_printf("(FT) Test 8: Decimal 48 (ASCII '0'): [%c]\n", 48);
	printf("(IO) Test 8: Decimal 48 (ASCII '0'): [%c]\n", 48);
	
	// Test with extreme width
	ft_printf("(FT) Test 9: Huge width: [%50c]\n", 'Z');
	printf("(IO) Test 9: Huge width: [%50c]\n", 'Z');
}

void	test_char(void)
{
	print_test_header("char");
	
	test_basic_char();
	test_char_with_width();
	test_char_with_flags();
	test_char_with_precision();
	test_char_edge_cases();
}