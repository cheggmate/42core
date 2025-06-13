/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/06/14 00:22:22 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "globals.h"				// Remove before submission

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

void	split_stack(int *stack, int  *stack_b, int *len, int median)
{
	int	i;
	int	b_len;
	int	char_to_check;

	char_to_check = *len;
	i = 0;
	b_len = 0;
	while (i < char_to_check)
	{
		if (b_len > 0 && stack[0] > stack[*len - 1] && stack_b[0] < stack_b[b_len - 1])
			rr(stack, stack_b, len, &b_len);
		else if (stack[0] < median)
		{
			if (b_len > 0 && (stack[0] < stack_b[0]))
				rotate_and_push(stack_b, stack, &b_len, len);
			else
				pushb(stack_b, stack, &b_len, len);
		}
		else
			rotate(stack, len, 'a');
		// printf("len = %d, b_len = %d\n", *len, b_len);
		// print_stack(stack, len, 'a');			// remove this before submission.
		// print_stack(stack_b, &b_len, 'b');		// remove this before submission.
		i++;
	}
}

void	sort_stack(int *stack, int len)
{
	int	largest;

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
