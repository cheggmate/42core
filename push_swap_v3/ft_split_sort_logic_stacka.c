/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic_stacka.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/07/04 23:30:30 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	s_r_s_rr_s(t_stack *stack, t_list_ops *curr)
{
	swap (stack, curr, 'a');
	rotate (stack->stack_a, stack->len_a, curr, 'a');
	swap (stack, curr, 'a');
	rev_rot (stack->stack_a, stack->len_a, curr, 'a');
	swap (stack, curr, 'a');
}

static void	r_s_rr_s(t_stack *stack, t_list_ops *curr)
{
	rotate (stack->stack_a, stack->len_a, curr, 'a');
	swap (stack, curr, 'a');
	rev_rot (stack->stack_a, stack->len_a, curr, 'a');
	swap (stack, curr, 'a');
}

static void	r_s_rr(t_stack *stack, t_list_ops *curr)
{
	rotate (stack->stack_a, stack->len_a, curr, 'a');
	swap (stack, curr, 'a');
	rev_rot (stack->stack_a, stack->len_a, curr, 'a');
}

static void	s_r_s_rr(t_stack *stack, t_list_ops *curr)
{
	swap (stack, curr, 'a');
	rotate (stack->stack_a, stack->len_a, curr, 'a');
	swap (stack, curr, 'a');
	rev_rot (stack->stack_a, stack->len_a, curr, 'a');
}

void	sort_stack(t_stack *stack, t_list_ops *curr, int n)
{
	if (n == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			swap (stack, curr, 'a');
		return ;
	}
	if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[1] < stack->stack_a[2]
		&& stack->stack_a[0] < stack->stack_a[2])
		swap (stack, curr, 'a');
	else if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[2])
		s_r_s_rr_s(stack, curr);
	else if (stack->stack_a[0] < stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[2]
		&& stack->stack_a[0] > stack->stack_a[2])
		r_s_rr_s(stack, curr);
	else if (stack->stack_a[0] < stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[2]
		&& stack->stack_a[0] < stack->stack_a[2])
		r_s_rr(stack, curr);
	else if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[1] < stack->stack_a[2]
		&& stack->stack_a[0] > stack->stack_a[2])
		s_r_s_rr(stack, curr);
}
