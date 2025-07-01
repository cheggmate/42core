/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:19:57 by jotong            #+#    #+#             */
/*   Updated: 2025/07/02 00:57:19 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - pa (push a): Take the first element at the top of b and put it at the top of a.
//     Do nothing if b is empty.
// - pb (push b): Take the first element at the top of a and put it at the top of b.
//     Do nothing if a is empty.

#include "ft_push_swap.h"

int	pusha(t_stack *stack, t_list_ops *curr)
{
	if (stack->len_b > 0)
	{
		if (stack->len_a > 0)
			ft_memmove(&stack->stack_a[1], &stack->stack_a[0], (stack->len_a) * sizeof(int));
		stack->stack_a[0] = stack->stack_b[0];
		stack->len_a += 1;
		ft_memmove(&stack->stack_b[0], &stack->stack_b[1], (stack->len_b - 1) * sizeof(int));
		stack->stack_b[stack->len_b - 1] = 0;
		stack->len_b -= 1;
		write (1, "pa", 2);
		write (1, "\n", 1);
		printf("curr->len = %d\n", curr->len);
		print_stack(stack, 'a');
		print_stack(stack, 'b');
		return (1);
	}
	return (0);
}

int	pushb(t_stack *stack, t_list_ops *curr)
{
	if (stack->len_a > 0)
	{
		if (stack->len_b > 0)
			ft_memmove(&stack->stack_b[1], &stack->stack_b[0], (stack->len_b) * sizeof(int));
		stack->stack_b[0] = stack->stack_a[0];
		stack->len_b += 1;
		ft_memmove(&stack->stack_a[0], &stack->stack_a[1], (stack->len_a - 1) * sizeof(int));
		stack->stack_a[stack->len_a - 1] = 0;
		stack->len_a -= 1;
		write (1, "pb", 2);
		write (1, "\n", 1);
		printf("curr->len = %d\n", curr->len);
		print_stack(stack, 'a');
		print_stack(stack, 'b');
		return (1);
	}
	return (0);
}
