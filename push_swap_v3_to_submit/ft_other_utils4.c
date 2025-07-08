/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:26:36 by jotong            #+#    #+#             */
/*   Updated: 2025/07/08 13:31:22 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_second_largest(int *stack, int len)
{
	int	largest;
	int	second;
	int	i;

	if (len < 2)
		return (-1);
	largest = INT_MIN;
	second = INT_MIN;
	i = 0;
	while (i < len)
	{
		if (largest < stack[i])
		{
			if (second < largest)
				second = largest;
			largest = stack[i];
		}
		else if (second < stack[i] && stack[i] != largest)
			second = stack[i];
		i++;
	}
	return (second);
}

void	find_ind_2min_btm(int *stack, int len, int search, int *smallest)
{
	int	min;
	int	min2;
	int	i;

	i = 0;
	min = stack[len - 1];
	min2 = stack[len - 1];
	while (i++ < search)
	{
		if (stack[len - 1 - i] < min)
		{
			if (min2 > min)
				min2 = min;
			min = stack[len - 1 - i];
		}
		else if (stack[len - 1 - i] < min2)
			min2 = stack[len - 1 - i];
	}
	smallest[0] = min;
	smallest[1] = min2;
}

void	rev_rot_a_push_2(t_stack *stack, t_list_ops *curr, int *moved, int n)
{
	int	count;
	int	smllst[2];

	count = n;
	if (stack->len_a > n)
	{
		find_ind_2min_btm(stack->stack_a, stack->len_a, n, smllst);
		while (count--)
		{
			rev_rot(stack->stack_a, stack->len_a, curr, 'a');
			if (n == 5 && (stack->stack_a[0] == smllst[0]
					|| stack->stack_a[0] == smllst[1]))
			{
				pushb(stack, curr);
				(*moved) += 1;
			}
		}
	}
	else
		mv_smallest_frm_a(stack, curr, n);
	if (*moved == 2 && stack->stack_b[0] < stack->stack_b[1])
		swap(stack, curr, 'b');
}

void	find_ind_2max_btm(int *stack, int len, int search, int *largest)
{
	int	max;
	int	max2;
	int	i;

	i = 0;
	max = stack[len - 1];
	max2 = stack[len - 1];
	while (i++ < search)
	{
		if (stack[len - 1 - i] > max)
		{
			if (max2 < max)
				max2 = max;
			max = stack[len - 1 - i];
		}
		else if (stack[len - 1 - i] > max2)
			max2 = stack[len - 1 - i];
	}
	largest[0] = max;
	largest[1] = max2;
}

void	rev_rot_b_push_2(t_stack *stack, t_list_ops *curr, int *moved, int n)
{
	int	count;
	int	lrgst[2];

	count = n;
	if (stack->len_b > n)
	{
		find_ind_2max_btm(stack->stack_b, stack->len_b, n, lrgst);
		while (count--)
		{
			rev_rot(stack->stack_b, stack->len_b, curr, 'b');
			if (n == 5 && (stack->stack_b[0] == lrgst[0]
					|| stack->stack_b[0] == lrgst[1]))
			{
				pusha(stack, curr);
				(*moved) += 1;
			}
		}
	}
	else
		mv_largest_frm_b(stack, curr, n);
	if (*moved == 2 && stack->stack_a[0] > stack->stack_a[1])
		swap(stack, curr, 'a');
}
