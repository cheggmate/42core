/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic_stacka.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/07/01 08:49:27 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	s_r_s_rr_s(int *stack, int *len, int n)
{
	swap(stack, len , 'a');
	rotate(stack, len, 'a');
	swap(stack, len , 'a');
	rev_rot(stack, len, 'a');
	swap(stack, len , 'a');
}

static void	r_s_rr_s(int *stack, int *len, int n)
{
	rotate(stack, len, 'a');
	swap(stack, len , 'a');
	rev_rot(stack, len, 'a');
	swap(stack, len , 'a');
}

static void	r_s_rr(int *stack, int *len, int n)
{
	rotate(stack, len, 'a');
	swap(stack, len , 'a');
	rev_rot(stack, len, 'a');
}

static void	s_r_s_rr(int *stack, int *len, int n)
{
	swap(stack, len , 'a');
	rotate(stack, len, 'a');
	swap(stack, len , 'a');
	rev_rot(stack, len, 'a');
}

void	sort_stack(int *stack, int *len, int n)
{
	if (n == 2)
	{
		if (stack[0] > stack[1])
			swap(stack, len, 'a');
		return ;
	}
	if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2]) // 1 0 2
		swap(stack, len, 'a');
	else if (stack[0] > stack[1] && stack[1] > stack[2])  // 2 1 0
		s_r_s_rr_s(stack, len, n);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2]) // 1 2 0
		r_s_rr_s(stack, len, n);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2]) // 0 2 1
		r_s_rr(stack, len, n);
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2]) // 2 0 1
		s_r_s_rr(stack, len, n);
}
