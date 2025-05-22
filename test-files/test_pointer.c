/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/05/18 10:39:14 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"

static void	test_basic_pointer(void)
{
	print_test_subheader("Basic pointer tests");
	
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
	ft_printf("(FT) Test 5: Function pointer: [%p]\n", (void *)&test_basic_pointer);
	printf("(IO) Test 5: Function pointer: [%p]\n", (void *)&test_basic_pointer);
	ft_printf("(FT) Test 6: Multiple pointers: [%p %p]\n", ptr1, ptr2);
	printf("(IO) Test 6: Multiple pointers: [%p %p]\n", ptr1, ptr2);
}

static void	test_pointer_with_width(void)
{
	print_test_subheader("Pointer with width");
	
	void *ptr = (void *)0xABCDEF;
	void *null_ptr = NULL;
	
	ft_printf("(FT) Test 1: Width less than pointer length: [%5p]\n", ptr);
	printf("(IO) Test 1: Width less than pointer length: [%5p]\n", ptr);
	ft_printf("(FT) Test 2: Width equal to typical pointer length: [%14p]\n", ptr);
	printf("(IO) Test 2: Width equal to typical pointer length: [%14p]\n", ptr);
	ft_printf("(FT) Test 3: Width more than pointer length: [%20p]\n", ptr);
	printf("(IO) Test 3: Width more than pointer length: [%20p]\n", ptr);
	ft_printf("(FT) Test 4: Width with NULL pointer: [%10p]\n", null_ptr);
	printf("(IO) Test 4: Width with NULL pointer: [%10p]\n", null_ptr);
	ft_printf("(FT) Test 5: Zero width: [%0p]\n", ptr);
	printf("(IO) Test 5: Zero width: [%0p]\n", ptr);
}

static void	test_pointer_with_flags(void)
{
	print_test_subheader("Pointer with flags");
	
	void *ptr = (void *)0xABCDEF;
	void *null_ptr = NULL;
	
	// For %p only the minus flag should have a defined effect
	ft_printf("(FT) Test 1: Left-aligned: [%-20p]\n", ptr);
	printf("(IO) Test 1: Left-aligned: [%-20p]\n", ptr);
	
	// Other flags technically shouldn't affect %p but let's test
	ft_printf("(FT) Test 2: With zero flag: [%020p]\n", ptr);
	printf("(IO) Test 2: With zero flag: [%020p]\n", ptr);
	ft_printf("(FT) Test 3: With plus flag: [%+20p]\n", ptr);
	printf("(IO) Test 3: With plus flag: [%+20p]\n", ptr);
	ft_printf("(FT) Test 4: With space flag: [% 20p]\n", ptr);
	printf("(IO) Test 4: With space flag: [% 20p]\n", ptr);
	ft_printf("(FT) Test 5: With hash flag: [%#20p]\n", ptr);
	printf("(IO) Test 5: With hash flag: [%#20p]\n", ptr);
	
	// NULL pointer with flags
	ft_printf("(FT) Test 6: NULL with left alignment: [%-15p]\n", null_ptr);
	printf("(IO) Test 6: NULL with left alignment: [%-15p]\n", null_ptr);
	ft_printf("(FT) Test 7: NULL with zero padding: [%015p]\n", null_ptr);
	printf("(IO) Test 7: NULL with zero padding: [%015p]\n", null_ptr);
	
	// Combining flags
	ft_printf("(FT) Test 8: Left-aligned with zero (left alignment should win): [%-020p]\n", ptr);
	printf("(IO) Test 8: Left-aligned with zero (left alignment should win): [%-020p]\n", ptr);
	ft_printf("(FT) Test 9: All flags: [%-+0# 20p]\n", ptr);
	printf("(IO) Test 9: All flags: [%-+0# 20p]\n", ptr);
}

static void	test_pointer_with_precision(void)
{
	print_test_subheader("Pointer with precision");
	
	void *ptr = (void *)0xABCDEF;
	void *null_ptr = NULL;
	
	// Precision technically shouldn't affect %p in a standard way but let's test
	ft_printf("(FT) Test 1: Precision less than pointer digits: [%.5p]\n", ptr);
	printf("(IO) Test 1: Precision less than pointer digits: [%.5p]\n", ptr);
	ft_printf("(FT) Test 2: Precision equal to pointer digits: [%.12p]\n", ptr);
	printf("(IO) Test 2: Precision equal to pointer digits: [%.12p]\n", ptr);
	ft_printf("(FT) Test 3: Precision more than pointer digits: [%.20p]\n", ptr);
	printf("(IO) Test 3: Precision more than pointer digits: [%.20p]\n", ptr);
	ft_printf("(FT) Test 4: Precision zero: [%.0p]\n", ptr);
	printf("(IO) Test 4: Precision zero: [%.0p]\n", ptr);
	ft_printf("(FT) Test 5: NULL with precision: [%.5p]\n", null_ptr);
	printf("(IO) Test 5: NULL with precision: [%.5p]\n", null_ptr);
	ft_printf("(FT) Test 6: NULL with zero precision: [%.0p]\n", null_ptr);
	printf("(IO) Test 6: NULL with zero precision: [%.0p]\n", null_ptr);
}

static void	test_pointer_with_width_and_precision(void)
{
	print_test_subheader("Pointer with width and precision");
	
	void *ptr = (void *)0xABCDEF;
	void *null_ptr = NULL;
	
	// Width and precision combinations
	ft_printf("(FT) Test 1: Width > precision: [%20.10p]\n", ptr);
	printf("(IO) Test 1: Width > precision: [%20.10p]\n", ptr);
	ft_printf("(FT) Test 2: Width < precision: [%10.20p]\n", ptr);
	printf("(IO) Test 2: Width < precision: [%10.20p]\n", ptr);
	ft_printf("(FT) Test 3: Width = precision: [%15.15p]\n", ptr);
	printf("(IO) Test 3: Width = precision: [%15.15p]\n", ptr);
	
	// With flags
	ft_printf("(FT) Test 4: Left-aligned with precision: [%-20.10p]\n", ptr);
	printf("(IO) Test 4: Left-aligned with precision: [%-20.10p]\n", ptr);
	ft_printf("(FT) Test 5: Zero flag with precision: [%020.10p]\n", ptr);
	printf("(IO) Test 5: Zero flag with precision: [%020.10p]\n", ptr);
	
	// NULL cases
	ft_printf("(FT) Test 6: NULL with width > precision: [%15.5p]\n", null_ptr);
	printf("(IO) Test 6: NULL with width > precision: [%15.5p]\n", null_ptr);
	ft_printf("(FT) Test 7: NULL with width < precision: [%5.15p]\n", null_ptr);
	printf("(IO) Test 7: NULL with width < precision: [%5.15p]\n", null_ptr);
	ft_printf("(FT) Test 8: NULL with width, zero precision: [%10.0p]\n", null_ptr);
	printf("(IO) Test 8: NULL with width, zero precision: [%10.0p]\n", null_ptr);
}

static void	test_pointer_edge_cases(void)
{
	print_test_subheader("Pointer edge cases");
	
	ft_printf("(FT) Test 1: Address 0: [%p]\n", (void *)0);
	printf("(IO) Test 1: Address 0: [%p]\n", (void *)0);
	ft_printf("(FT) Test 2: NULL explicitly: [%p]\n", NULL);
	printf("(IO) Test 2: NULL explicitly: [%p]\n", NULL);
	ft_printf("(FT) Test 3: Stack address: [%p]\n", (void *)&test_pointer_edge_cases);
	printf("(IO) Test 3: Stack address: [%p]\n", (void *)&test_pointer_edge_cases);
	ft_printf("(FT) Test 4: Huge width: [%50p]\n", (void *)0xABCDEF);
	printf("(IO) Test 4: Huge width: [%50p]\n", (void *)0xABCDEF);
	ft_printf("(FT) Test 5: Huge precision: [%.50p]\n", (void *)0xABCDEF);
	printf("(IO) Test 5: Huge precision: [%.50p]\n", (void *)0xABCDEF);
	ft_printf("(FT) Test 6: Zero width, zero precision: [%0.0p]\n", (void *)0xABCDEF);
	printf("(IO) Test 6: Zero width, zero precision: [%0.0p]\n", (void *)0xABCDEF);
	ft_printf("(FT) Test 7: All flags, width, precision: [%-+0# 20.10p]\n", (void *)0xABCDEF);
	printf("(IO) Test 7: All flags, width, precision: [%-+0# 20.10p]\n", (void *)0xABCDEF);
	
	// Force different pointer sizes
	char arr[10];
	short sarr[10];
	ft_printf("(FT) Test 8: Array pointer: [%p]\n", (void *)arr);
	printf("(IO) Test 8: Array pointer: [%p]\n", (void *)arr);
	ft_printf("(FT) Test 9: Different size array: [%p]\n", (void *)sarr);
	printf("(IO) Test 9: Different size array: [%p]\n", (void *)sarr);
	ft_printf("(FT) Test 10: String literal address: [%p]\n", (void *)"Hello");
	printf("(IO) Test 10: String literal address: [%p]\n", (void *)"Hello");
}

void	test_pointer(void)
{
	print_test_header("pointer");
	
	test_basic_pointer();
	test_pointer_with_width();
	test_pointer_with_flags();
	test_pointer_with_precision();
	test_pointer_with_width_and_precision();
	test_pointer_edge_cases();
}