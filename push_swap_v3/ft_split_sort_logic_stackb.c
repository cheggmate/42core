/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic_stackb.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:40:11 by jotong            #+#    #+#             */
/*   Updated: 2025/07/04 23:48:34 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	s_r_s_rr_s(t_stack *stack, t_list_ops *curr)
{
	swap (stack, curr, 'b');
	rotate (stack->stack_b, stack->len_b, curr, 'b');
	swap (stack, curr, 'b');
	rev_rot (stack->stack_b, stack->len_b, curr, 'b');
	swap (stack, curr, 'b');
}

static void	r_s_rr(t_stack *stack, t_list_ops *curr)
{
	rotate (stack->stack_b, stack->len_b, curr, 'b');
	swap (stack, curr, 'b');
	rev_rot (stack->stack_b, stack->len_b, curr, 'b');
}

static void	r_s_rr_s(t_stack *stack, t_list_ops *curr)
{
	rotate (stack->stack_b, stack->len_b, curr, 'b');
	swap (stack, curr, 'b');
	rev_rot (stack->stack_b, stack->len_b, curr, 'b');
	swap (stack, curr, 'b');
}

static void	s_r_s_rr(t_stack *stack, t_list_ops *curr)
{
	swap (stack, curr, 'b');
	rotate (stack->stack_b, stack->len_b, curr, 'b');
	swap (stack, curr, 'b');
	rev_rot (stack->stack_b, stack->len_b, curr, 'b');
}

void	sort_stack_b(t_stack *stack, t_list_ops *curr, int n)
{
	if (n == 2)
	{
		if (stack->stack_b[0] < stack->stack_b[1])
			swap (stack, curr, 'b');
		return ;
	}
	if (stack->stack_b[0] < stack->stack_b[1]
		&& stack->stack_b[1] > stack->stack_b[2]
		&& stack->stack_b[0] > stack->stack_b[2])
		swap (stack, curr, 'b');
	else if (stack->stack_b[0] < stack->stack_b[1]
		&& stack->stack_b[1] < stack->stack_b[2])
		s_r_s_rr_s(stack, curr);
	else if (stack->stack_b[0] > stack->stack_b[1]
		&& stack->stack_b[1] < stack->stack_b[2]
		&& stack->stack_b[0] > stack->stack_b[2])
		r_s_rr(stack, curr);
	else if (stack->stack_b[0] > stack->stack_b[1]
		&& stack->stack_b[1] < stack->stack_b[2]
		&& stack->stack_b[0] < stack->stack_b[2])
		r_s_rr_s(stack, curr);
	else if (stack->stack_b[0] < stack->stack_b[1]
		&& stack->stack_b[1] > stack->stack_b[2]
		&& stack->stack_b[0] < stack->stack_b[2])
		s_r_s_rr(stack, curr);
}
