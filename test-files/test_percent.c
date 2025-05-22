/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/05/18 11:07:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tester.h"

static void	test_basic_percent(void)
{
	print_test_subheader("Basic percent sign tests");

	ft_printf("(FT) Test 1: Simple percent: [%%]\n");
	printf("(IO) Test 1: Simple percent: [%%]\n");
	ft_printf("(FT) Test 2: Double percent: [%%%%]\n");
	printf("(IO) Test 2: Double percent: [%%%%]\n");
	ft_printf("(FT) Test 3: Triple percent: [%%%%%%]\n");
	printf("(IO) Test 3: Triple percent: [%%%%%%]\n");
	ft_printf("(FT) Test 4: Percent with text: [Hello %% World]\n");
	printf("(IO) Test 4: Percent with text: [Hello %% World]\n");
	ft_printf("(FT) Test 5: Multiple percent: [%% %% %%]\n");
	printf("(IO) Test 5: Multiple percent: [%% %% %%]\n");
}

void	test_percent_bonus(void)
{
	print_test_header("percent");

	test_basic_percent();
}