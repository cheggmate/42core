/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/06/21 01:08:44 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_stack(int *stack, int *len, int n)
{
	if (n == 2)
	{
		if (stack[0] > stack[1])
			swap(stack, len, 'a');
		return ;
	}
	if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2])
		swap(stack, len, 'a');
	else if (stack[0] > stack[1] && stack[1] > stack[2])
	{
		swap(stack, len , 'a');
		rotate(stack, len, 'a');
		swap(stack, len , 'a');
		rev_rot(stack, len, 'a');
		swap(stack, len , 'a');
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2])
		rotate(stack, len, 'a');
	else if (stack[0] > stack[1] && stack[1] > stack[2] && stack[0] < stack[2])
	{
		swap(stack, len, 'a');
		rotate(stack, len, 'a');
		swap(stack, len, 'a');
		rev_rot(stack, len, 'a');
	}
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2])
	{
		rotate(stack, len, 'a');
		swap(stack, len, 'a');
		rev_rot(stack, len, 'a');
		swap(stack, len, 'a');
	}	
}

void	sort_stack_b(int *stack_b, int *len, int n)
{
	if (n == 2)
	{
		if (stack_b[0] < stack_b[1])
			swap(stack_b, len, 'b');
		return ;
	}
	if (stack_b[0] < stack_b[1] && stack_b[1] > stack_b[2] && stack_b[0] > stack_b[2])
	{
		rotate(stack_b, len, 'b');
		swap(stack_b, len, 'b');
		rev_rot(stack_b, len, 'b');
		swap(stack_b, len, 'b');
	}
	else if (stack_b[0] < stack_b[1] && stack_b[1] < stack_b[2])
	{
		swap(stack_b, len, 'b');
		rotate(stack_b, len, 'b');
		swap(stack_b, len, 'b');
		rev_rot(stack_b, len, 'b');
		swap(stack_b, len, 'b');
	}
	else if (stack_b[0] < stack_b[1] && stack_b[1] < stack_b[2] && stack_b[0] > stack_b[2])
	{
		swap(stack_b, len, 'b');
		rotate(stack_b, len, 'b');
		swap(stack_b, len, 'b');
		rev_rot(stack_b, len, 'b');
	}
}
