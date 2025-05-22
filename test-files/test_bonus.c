/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/05/18 11:25:30 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"

int	main(void)
{
	printf("\n===== FT_PRINTF COMPREHENSIVE TEST SUITE =====\n\n");
	

	
	setvbuf(stdout, NULL, _IONBF, 0);

	test_char();
	printf("\n\n");
	
	test_string();
	printf("\n\n");
	
	test_pointer();
	printf("\n\n");
	
	test_decimal();
	printf("\n\n");
	
	test_unsigned();
	printf("\n\n");
	
	test_hex();
	printf("\n\n");

	test_return_values();
	printf("\n\n");
	
	printf("\n\n===== TEST SUITE COMPLETE =====\n");
	return (0);
}

void	print_test_header(const char *test_name)
{
	printf("\n\n==================================================\n");
	printf("              TESTING %%%s FORMAT                ", test_name);
	printf("\n==================================================\n");
}

void	print_test_subheader(const char *subheader)
{
	printf("\n--------------------------------------------------\n");
	printf(" %s ", subheader);
	printf("\n--------------------------------------------------\n");
}