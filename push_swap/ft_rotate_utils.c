/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:18:37 by jotong            #+#    #+#             */
/*   Updated: 2025/06/13 15:37:50 by jotong           ###   ########.fr       */
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
#include "globals.h"

void	rotate(int *stack, int *len, int ab)
{
	int	tmp;

	tmp = 0;
	if (*len >= 2)
	{
		tmp = stack[0];
		ft_memmove(&stack[0], &stack[1], (*len - 1) * sizeof(int));
		stack[*len - 1] = tmp;
		if (ab == 'a')
			write (1, "ra", 2);
		else if (ab == 'b')
			write (1, "rb", 2);
		write (1, "\n", 1);
		num_ops += 1;				// remove before submission
	}
}

void	rev_rot(int *stack, int *len, int ab)
{
	int	tmp;

	tmp = 0;
	if (*len >= 2)
	{
		tmp = stack[*len - 1];
		ft_memmove(&stack[1], &stack[0], (*len - 1) * sizeof(int));
		stack[0] = tmp;
		if (ab == 'a')
			write (1, "rra", 3);
		else if (ab == 'b')
			write (1, "rrb", 3);
		write (1, "\n", 1);
		num_ops += 1;				// remove before submission
	}
}

void	rr(int	*stack_a, int *stack_b, int *len_a, int *len_b)
{
	rotate(stack_a, len_a, 'r');
	rotate(stack_b, len_b, 'r');
	write (1, "rr", 2);
}

void	rrr(int	*stack_a, int *stack_b, int *len_a, int *len_b)
{
	rev_rot(stack_a, len_a, 'r');
	rev_rot(stack_b, len_b, 'r');
	write (1, "rrr", 3);
}

// int	main(void)
// {
// 	int	a[6] = {1, 2, 3, 4, 5};
// 	int	b[5] = {5, 4, 3, 2, 1};
// 	int	len_a = 5;
// 	int	len_b = 5;

// 	rotate(a, &len_a, 'a');
// 	print_stack(a, &len_a, 'a');
// 	rotate(b, &len_b, 'b');
// 	print_stack(b, &len_b, 'b');
// }