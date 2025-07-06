/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:18:37 by jotong            #+#    #+#             */
/*   Updated: 2025/07/04 23:57:34 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate(int *stack, int len, t_list_ops *curr, int ab)
{
	int			tmp;
	t_list_ops	*new;
	char		*ops;

	tmp = 0;
	ops = "\0";
	if (len >= 2)
	{
		tmp = stack[0];
		ft_memmove(&stack[0], &stack[1], (len - 1) * sizeof(int));
		stack[len - 1] = tmp;
		if (ab == 'a')
			ops = "ra\n";
		else if (ab == 'b')
			ops = "rb\n";
		if (ab == 'a' || ab == 'b')
		{
			new = ft_lstnew_ops(ops, len);
			if (new)
				ft_lstadd_back_ops(curr, new);
		}
	}
}

void	rev_rot(int *stack, int len, t_list_ops *curr, int ab)
{
	int			tmp;
	t_list_ops	*new;
	char		*ops;

	tmp = 0;
	if (len >= 2)
	{
		tmp = stack[len - 1];
		ft_memmove(&stack[1], &stack[0], (len - 1) * sizeof(int));
		stack[0] = tmp;
		if (ab == 'a')
			ops = "rra\n";
		else if (ab == 'b')
			ops = "rrb\n";
		if (ab == 'a' || ab == 'b')
		{
			new = ft_lstnew_ops(ops, len);
			if (new)
				ft_lstadd_back_ops(curr, new);
		}
	}
}

void	rr(t_stack *stack, t_list_ops *curr)
{
	t_list_ops	*new;

	rotate(stack->stack_a, stack->len_a, curr, 'x');
	rotate(stack->stack_b, stack->len_b, curr, 'y');
	new = ft_lstnew_ops("rr\n", stack->len_a);
	if (new)
		ft_lstadd_back_ops(curr, new);
}

void	rrr(t_stack *stack, t_list_ops *curr)
{
	t_list_ops	*new;

	rev_rot(stack->stack_a, stack->len_a, curr, 'r');
	rev_rot(stack->stack_b, stack->len_b, curr, 'r');
	new = ft_lstnew_ops("rrr\n", stack->len_a);
	if (new)
		ft_lstadd_back_ops(curr, new);
}
