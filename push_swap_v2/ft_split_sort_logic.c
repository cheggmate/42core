/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/06/15 21:27:01 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// void	rotate_and_push(int *stack_b, int *stack, int *b_len, int *len)
// {
// 	int	iter;
// 	int	iter2;

// 	iter = find_pos(stack_b, stack[0], *b_len);
// 	iter2 = iter;
// 	while (iter-- > 0)
// 		rotate(stack_b, b_len, 'b');
// 	pushb(stack_b, stack, b_len, len);
// 	while (iter2-- > 0)
// 		rev_rot(stack_b, b_len, 'b');
// }

int	adjust_rotate_and_push_bottom(int *stack_b, int *stack, int *b_len, int *len)
{
	printf("adjust_rotate_and_push_bottom\n");
	rev_rot(stack_b, b_len, 'b');
	pushb(stack_b, stack, b_len, len);
	rotate(stack_b, b_len, 'b');
	return (1);
}

int rotate_and_push_top(int *stack_b, int *stack, int *b_len, int *len)
{
	printf("rotate and push top\n");
	rr(stack, stack_b, len, b_len);
	pushb(stack_b, stack, b_len, len);
	// if (stack[0] > stack[1])
	// 	rrr(stack, stack_b, len, b_len);
	// else
	rev_rot(stack_b, b_len, 'b');
	return (1);
}

int	push_and_rotate(int *dest, int *src, int *dest_len, int *src_len)
{
	int	total;

	printf("push and rotate\n");
	total = 0;
	total += pushb(dest, src, dest_len, src_len);
	rotate(dest, dest_len, 'b');
	return (total);
}

void	split_stack(int *stack, int  *stack_b, int *len, int *b_len)
{
	int	to_push;
	int	bgr;
	int	smlr;
	int i;					// remove before submission.

	i = 0;					// remove before submission.
	bgr = 0;
	smlr = 0;
	to_push = *len - 6;
	find_mids(stack, *len, &smlr, &bgr);
	printf("start split\n");
	print_stack(stack, len, 'a');			// remove this before submission.
	print_stack(stack_b, b_len, 'b');		// remove this before submission.
	printf("bgr is %d\n", bgr);
	printf("smlr is %d\n", smlr);
	while (to_push > 0 && i++ < *len)		// remove i++ condition before submission
	{
		if (stack[0] < smlr && b_len > 0 && stack_b[*b_len - 1] < stack[0]) // top item on stack a is in upper third and item at the bottom of stack b is smaller
			to_push -= adjust_rotate_and_push_bottom(stack_b, stack, b_len, len);
		else if (stack[0] < smlr)
			to_push -= push_and_rotate(stack_b, stack, b_len, len);
		else if (stack[0] > smlr && stack[0] <= bgr && stack[0] < stack_b[0] && stack_b[0] < smlr)
		{
			printf("rotate push rotate\n");
			rotate(stack_b, b_len, 'b');
			to_push -= pushb(stack_b, stack, b_len, len);
			rev_rot(stack_b, b_len, 'b');
		}
		else if (stack[0] >= bgr && stack[0] < smlr && stack[1] < smlr && stack[1] < stack_b[0])  // top item on stack a is in biggest third, and next item on stack a is in top third and show go below b
			to_push -= rotate_and_push_top(stack_b, stack, b_len, len);
		else if (stack[0] >= smlr && stack[0] < bgr)
			to_push -= pushb(stack_b, stack, b_len, len);
		else if (stack[0] >= bgr)
			rotate(stack, len, 'a');

		print_stack(stack, len, 'a');			// remove this before submission.
		print_stack(stack_b, b_len, 'b');		// remove this before submission.
		
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
