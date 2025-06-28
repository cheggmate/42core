/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:18:37 by jotong            #+#    #+#             */
/*   Updated: 2025/06/16 22:31:57 by jotong           ###   ########.fr       */
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

void	rotate(int *stack, int *len, int ab)
{
	int	tmp;
	int	*len_ptr;

	if (ab == 'a' || ab == 'x')
		len_ptr = &len[0];
	else
		len_ptr = &len[1];
	tmp = 0;
	if (*len_ptr >= 2)
	{
		tmp = stack[0];
		ft_memmove(&stack[0], &stack[1], (*len_ptr - 1) * sizeof(int));
		stack[*len_ptr - 1] = tmp;
		if (ab == 'a')
			write (1, "ra", 2);
		else if (ab == 'b')
			write (1, "rb", 2);
		if (ab == 'a' || ab == 'b')
			write (1, "\n", 1);
	}
}

void	rev_rot(int *stack, int *len, int ab)
{
	int	tmp;
	int	*len_ptr;

	tmp = 0;
	if (ab == 'a' || ab == 'x')
		len_ptr = &len[0];
	else
		len_ptr = &len[1];
	if (*len >= 2)
	{
		tmp = stack[*len_ptr - 1];
		ft_memmove(&stack[1], &stack[0], (*len_ptr - 1) * sizeof(int));
		stack[0] = tmp;
		if (ab == 'a')
			write (1, "rra", 3);
		else if (ab == 'b')
			write (1, "rrb", 3);
		if (ab == 'a' || ab == 'b')
			write (1, "\n", 1);
	}
}

void	rr(int	*stack_a, int *stack_b, int *len)
{
	rotate(stack_a, &len[0], 'x');
	rotate(stack_b, &len[1], 'y');
	write (1, "rr", 2);
	write (1, "\n", 1);
}

void	rrr(int	*stack_a, int *stack_b, int *len)
{
	rev_rot(stack_a, &len[0], 'r');
	rev_rot(stack_b, &len[1], 'r');
	write (1, "rrr", 3);
	write (1, "\n", 1);

}
