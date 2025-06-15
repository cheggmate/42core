/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/06/15 15:52:00 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_and_push(int *stack_b, int *stack, int *b_len, int *len)
{
	int	iter;
	int	iter2;

	iter = find_pos(stack_b, stack[0], *b_len);
	iter2 = iter;
	while (iter-- > 0)
		rotate(stack_b, b_len, 'b');
	pushb(stack_b, stack, b_len, len);
	while (iter2-- > 0)
		rev_rot(stack_b, b_len, 'b');
}

int rotate_and_push_top(int *stack_b, int *stack, int *b_len, int *len)
{
	rr(stack, stack_b, len, b_len);
	pushb(stack_b, stack, b_len, len);
	if (stack[0] > stack[1])
		rrr(stack, stack_b, len, b_len);
	else
		rev_rot(stack_b, b_len, 'b');
	return (1);
}

void	split_stack(int *stack, int  *stack_b, int *len)
{
	int	b_len;
	int	to_push;
	int mid_u;
	int mid_l;

	mid_u = 0;
	mid_l = 0;
	b_len = 0;
	to_push = *len - 6;
	find_median(stack, len, &mid_l, &mid_u);
	while (to_push > 0)
	{
		if (stack[0] > mid_u && stack[1] < mid_u && stack[1] < stack_b[0])  // top item on stack a is in biggest third, and next item on stack a is in middle third and show go below b
			to_push -= rotate_and_push2(stack_b, stack, &b_len, len);
		else if (stack[0] > mid_u)
			rotate(stack, len, 'a');
		// else if (stack[0] < mid_l)												// todo : add more optimisations here to use dual stack operations.
		// if (b_len > 0 && stack[0] > mid_u && stack_b[0] < stack_b[b_len - 1])
		// 	rr(stack, stack_b, len, &b_len);
		// else if (stack[0] < mid_u)
		// {
		// 	if (b_len > 0 && (stack[0] < stack_b[0]))
		// 	{
		// 		rotate_and_push(stack_b, stack, &b_len, len);
		// 	}
		// 	else
		// 	{
		// 		pushb(stack_b, stack, &b_len, len);
		// 	}
		// 	to_push--;
		// }
		// else
		// {
		// 	rotate(stack, len, 'a');
		// 	printf("rotating\n");
		// 	print_stack(stack, len, 'a');
		// }
		// printf("len = %d, b_len = %d\n", *len, b_len);
		// print_stack(stack, len, 'a');			// remove this before submission.
		// print_stack(stack_b, &b_len, 'b');		// remove this before submission.
		// printf("to_push is %d\n", to_push);		// remove this before submission.
		// i++;
	}
}

void	sort_stack(int *stack, int len)
{
	int	largest;
	// int i = 0;

	largest = find_largest(stack, len);
	while (is_sorted(stack, len) == 0)
	{
		if (stack[0] == largest)
			rev_rot(stack, &len, 'a');
		else if (stack[0] > stack[1])
			swap(stack, &len, 'a');
		else
			rev_rot(stack, &len, 'a');
	}
}
