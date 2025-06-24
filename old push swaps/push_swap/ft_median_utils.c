/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:37:37 by jotong            #+#    #+#             */
/*   Updated: 2025/06/14 00:04:34 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	insertion_sort(int	*stack_dup, int len)
{
	int i;
	int	val;
	int j;

	i = 1;
	while (i < len)
	{
		val = stack_dup[i];
		j = i - 1;

		while (j >= 0 && stack_dup[j] > val)
		{
			stack_dup[j + 1] = stack_dup[j];
			j--;
		}
		stack_dup[j + 1] = val;
		i++;
	}
}

double	find_median(int *stack, int len)
{
	int			*stack_dup;
	double		median;

	stack_dup = ft_arr_dup(stack, len);
	median = 0;
	if (stack_dup)
	{
		insertion_sort(stack_dup, len);
		if (len % 2 == 0)
			median = (stack_dup[len / 2 - 1] + stack_dup[len / 2]) / 2.0;
		else
			median = stack_dup[len / 2];
	}
	
	free (stack_dup);
	return (median);
}
