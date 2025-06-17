/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/06/17 13:36:16 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	move_back(int *stack, int *stack_b, int *len)
{
	while (len[1] > 0)
		pusha(stack, stack_b, len);
}

static int	find_smallest(int *stack, int len)
{
	int	smallest;
	int	i;
	int	index;

	smallest = INT_MAX;
	index = 0;
	i = -1;
	while (i++ < len)
	{
		if (stack[i] < smallest)
		{
			smallest = stack[i];
			index = i;
		}
	}
	return (index);
}

static void move_two(int *stack, int *stack_b, int *len)
{
	int s_index;
	int	pushed;

	pushed = 0;
	while (pushed < 2)
	{
		s_index = find_smallest(stack, len[0]);
		if (s_index > len[0] / 2)
		{
			while (len[0] - s_index++ > 0)
				rev_rot(stack, len, 'a');
		}
		else
		{
			while (s_index-- > 0)
				rotate(stack, len, 'a');
		}
		pushb(stack_b, stack, len);
		pushed++;
	}
}

void	sort_stack(int *stack, int *stack_b, int *len)
{
	int	largest;

	largest = find_largest(stack, len[0]);
	if (*len > 3)
		move_two(stack, stack_b, len);
	while (is_sorted(stack, *len) == 0)
	{
		if (stack[0] == largest)
			rev_rot(stack, len, 'a');
		else if (stack[0] > stack[1])
			swap(stack, len, 'a');
		else
			rev_rot(stack, len, 'a');
	}
	if (*len == 3)
		move_back(stack, stack_b, len);
}
