/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:18:37 by jotong            #+#    #+#             */
/*   Updated: 2025/07/02 00:38:52 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - ra (rotate a): Shift up all elements of stack a by 1.
//     The first element becomes the last one.
// - rb (rotate b): Shift up all elements of stack b by 1.
//     The first element becomes the last one.
// - rr : ra and rb at the same time.
// - rra (reverse rotate a): Shift down all elements of stack a by 1. 
//     The last element becomes the first one.
// - rrb (reverse rotate b): Shift down all elements of stack b by 1.
//     The last element becomes the first one.
// - rrr : rra and rrb at the same time.

#include "ft_push_swap.h"

void	rotate(int *stack, int len, t_list_ops *curr, int ab)
{
	int	tmp;

	tmp = 0;
	if (len >= 2)
	{
		tmp = stack[0];
		ft_memmove(&stack[0], &stack[1], (len - 1) * sizeof(int));
		stack[len- 1] = tmp;
		if (ab == 'a')
			write (1, "ra", 2);
		else if (ab == 'b')
			write (1, "rb", 2);
		if (ab == 'a' || ab == 'b')
			write (1, "\n", 1);
		printf("curr->len = %d\n", curr->len);
	}
}

void	rev_rot(int *stack, int len, t_list_ops *curr, int ab)
{
	int	tmp;

	tmp = 0;
	if (len >= 2)
	{
		tmp = stack[len- 1];
		ft_memmove(&stack[1], &stack[0], (len - 1) * sizeof(int));
		stack[0] = tmp;
		if (ab == 'a')
			write (1, "rra", 3);
		else if (ab == 'b')
			write (1, "rrb", 3);
		if (ab == 'a' || ab == 'b')
			write (1, "\n", 1);
		printf("curr->len = %d\n", curr->len);
	}
}

void	rr(t_stack *stack, t_list_ops *curr)
{
	rotate(stack->stack_a, stack->len_a, curr, 'x');
	rotate(stack->stack_b, stack->len_b, curr, 'y');
	write (1, "rr", 2);
	write (1, "\n", 1);
}

void	rrr(t_stack *stack, t_list_ops *curr)
{
	rev_rot(stack->stack_a, stack->len_a, curr, 'r');
	rev_rot(stack->stack_b, stack->len_b, curr, 'r');
	write (1, "rrr", 3);
	write (1, "\n", 1);
}
