/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic_stacka.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/07/02 09:09:20 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	s_r_s_rr_s(t_stack *stack, t_list_ops *curr)
{
	swap(stack, curr, 'a');
	rotate(stack->stack_a, stack->len_a, curr, 'a');
	swap(stack, curr, 'a');
	rev_rot(stack->stack_a, stack->len_a, curr, 'a');
	swap(stack, curr, 'a');
}

static void	r_s_rr_s(t_stack *stack, t_list_ops *curr)
{
	rotate(stack->stack_a, stack->len_a, curr, 'a');
	swap(stack, curr , 'a');
	rev_rot(stack->stack_a, stack->len_a, curr, 'a');
	swap(stack, curr , 'a');
}

static void	r_s_rr(t_stack *stack, t_list_ops *curr)
{
	rotate(stack->stack_a, stack->len_a, curr, 'a');
	swap(stack, curr, 'a');
	rev_rot(stack->stack_a, stack->len_a, curr, 'a');
}

static void	s_r_s_rr(t_stack *stack, t_list_ops *curr)
{
	swap(stack, curr , 'a');
	rotate(stack->stack_a, stack->len_a, curr, 'a');
	swap(stack, curr , 'a');
	rev_rot(stack->stack_a, stack->len_a, curr, 'a');
}

void	sort_stack(t_stack *stack, t_list_ops *curr, int n)
{
	if (n == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			swap(stack, curr, 'a');
		return ;
	}
	if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[1] < stack->stack_a[2] && \
		stack->stack_a[0] < stack->stack_a[2]) // 1 0 2
		swap(stack, curr, 'a');
	else if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[1] > stack->stack_a[2])  // 2 1 0
		s_r_s_rr_s(stack, curr);
	else if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] > stack->stack_a[2] && \
		stack->stack_a[0] > stack->stack_a[2]) // 1 2 0
		r_s_rr_s(stack, curr);
	else if (stack->stack_a[0] < stack->stack_a[1] && stack->stack_a[1] > stack->stack_a[2] && \
		stack->stack_a[0] < stack->stack_a[2]) // 0 2 1
		r_s_rr(stack, curr);
	else if (stack->stack_a[0] > stack->stack_a[1] && stack->stack_a[1] < stack->stack_a[2] && \
		stack->stack_a[0] > stack->stack_a[2]) // 2 0 1
		s_r_s_rr(stack, curr);
}
