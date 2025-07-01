/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic_stackb.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:40:11 by jotong            #+#    #+#             */
/*   Updated: 2025/07/01 08:45:30 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	s_r_s_rr_s(int *stack_b, int *len, int n)
{
	swap(stack_b, len, 'b');
	rotate(stack_b, len, 'b');
	swap(stack_b, len, 'b');
	rev_rot(stack_b, len, 'b');
	swap(stack_b, len, 'b');
}

static void	r_s_rr(int *stack_b, int *len, int n)
{
	rotate(stack_b, len, 'b');
	swap(stack_b, len, 'b');
	rev_rot(stack_b, len, 'b');
}

static void r_s_rr_s(int *stack_b, int *len, int n)
{
	rotate(stack_b, len, 'b');
	swap(stack_b, len, 'b');
	rev_rot(stack_b, len, 'b');
	swap(stack_b, len, 'b');
}

static void	s_r_s_rr(int *stack_b, int *len, int n)
{
	swap(stack_b, len, 'b');
	rotate(stack_b, len, 'b');
	swap(stack_b, len, 'b');
	rev_rot(stack_b, len, 'b');
}

void	sort_stack_b(int *stack_b, int *len, int n)
{
	if (n == 2)
	{
		if (stack_b[0] < stack_b[1])
			swap(stack_b, len, 'b');
		return ;
	}
	if (stack_b[0] < stack_b[1] && stack_b[1] > stack_b[2] && stack_b[0] > stack_b[2]) // 1 2 0
	swap(stack_b, len, 'b');
	else if (stack_b[0] < stack_b[1] && stack_b[1] < stack_b[2]) // 0 1 2
		s_r_s_rr_s(stack_b, len, n);
	else if (stack_b[0] > stack_b[1] && stack_b[1] < stack_b[2] && stack_b[0] > stack_b[2]) // 2 0 1
		r_s_rr(stack_b, len, n);
	else if (stack_b[0] > stack_b[1] && stack_b[1] < stack_b[2] && stack_b[0] < stack_b[2]) // 1 0 2
		r_s_rr_s(stack_b, len, n);
	else if (stack_b[0] < stack_b[1] && stack_b[1] > stack_b[2] && stack_b[0] < stack_b[2]) // 0 2 1
		s_r_s_rr(stack_b, len, n);

}
