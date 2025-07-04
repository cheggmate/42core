/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:19:57 by jotong            #+#    #+#             */
/*   Updated: 2025/07/02 20:35:18 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - pa (push a): Take the first element at the top of b and put it at the top of a.
//     Do nothing if b is empty.
// - pb (push b): Take the first element at the top of a and put it at the top of b.
//     Do nothing if a is empty.

#include "ft_push_swap.h"

int	pusha(t_stack *stack, t_list_ops *curr)
{
	t_list_ops	*new;
	
	if (stack->len_b > 0)
	{
		if (stack->len_a > 0)
			ft_memmove(&stack->stack_a[1], &stack->stack_a[0], (stack->len_a) * sizeof(int));
		stack->stack_a[0] = stack->stack_b[0];
		stack->len_a += 1;
		ft_memmove(&stack->stack_b[0], &stack->stack_b[1], (stack->len_b - 1) * sizeof(int));
		stack->stack_b[stack->len_b - 1] = 0;
		stack->len_b -= 1;
		new = ft_lstnew_ops("pa\n", stack->len_a);
		if (new)
			ft_lstadd_back_ops(curr, new);
		return (1);
	}
	return (0);
}

int	pushb(t_stack *stack, t_list_ops *curr)
{
	t_list_ops	*new;

	if (stack->len_a > 0)
	{
		if (stack->len_b > 0)
			ft_memmove(&stack->stack_b[1], &stack->stack_b[0], (stack->len_b) * sizeof(int));
		stack->stack_b[0] = stack->stack_a[0];
		stack->len_b += 1;
		ft_memmove(&stack->stack_a[0], &stack->stack_a[1], (stack->len_a - 1) * sizeof(int));
		stack->stack_a[stack->len_a - 1] = 0;
		stack->len_a -= 1;
		new = ft_lstnew_ops("pb\n", stack->len_a);
		if (new)
			ft_lstadd_back_ops(curr, new);
		return (1);
	}
	return (0);
}
