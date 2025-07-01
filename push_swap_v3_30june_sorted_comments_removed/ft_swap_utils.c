/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:07:33 by jotong            #+#    #+#             */
/*   Updated: 2025/07/01 23:36:40 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Operations available: 
// - sa (swap a): Swap the first 2 elements at the top of stack a.
//     Do nothing if there is only one element or none.
// - sb (swap b): Swap the first 2 elements at the top of stack b.
//     Do nothing if there is only one element or none.
// - ss : sa and sb at the same time.

#include "ft_push_swap.h"

void	swap(t_stack *stack, t_list_ops *curr, int ab)
{
	int	tmp;
	int	*len_ptr;
	int	*stack_toswap;

	if (ab == 'a' || ab == 'x')
	{
		len_ptr = &stack->len_a;
		stack_toswap = stack->stack_a;
	}
	else
	{
		len_ptr = &stack->len_b;
		stack_toswap = stack->stack_b;
	}
	if (*len_ptr >= 2)
	{
		tmp = stack_toswap[0];
		stack_toswap[0] = stack_toswap[1];
		stack_toswap[1] = tmp;
		if (ab == 'a')
			write (1, "sa", 2);
		else if (ab == 'b')
			write (1, "sb", 2);
		if (ab == 'a' || ab == 'b')
			write (1, "\n", 1);
		printf("curr->len = %d\n", curr->len);
	}
}

void	swap_both(t_stack *stack, t_list_ops *curr)
{
	swap(stack, curr, 'x');
	swap(stack, curr, 'y');
	write(1, "ss", 2);
	write (1, "\n", 1);
}
