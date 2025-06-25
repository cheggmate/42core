/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:07:33 by jotong            #+#    #+#             */
/*   Updated: 2025/06/16 22:33:48 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Operations available: 
// - sa (swap a): Swap the first 2 elements at the top of stack a.
//     Do nothing if there is only one element or none.
// - sb (swap b): Swap the first 2 elements at the top of stack b.
//     Do nothing if there is only one element or none.
// - ss : sa and sb at the same time.

#include "ft_push_swap.h"

void	swap(int *stack, int *len, int ab)
{
	int	tmp;
	int	*len_ptr;

	if (ab == 'a' || ab == 'x')
		len_ptr = &len[0];
	else
		len_ptr = &len[1];

	if (*len_ptr >= 2)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
		if (ab == 'a')
			write (1, "sa", 2);
		else if (ab == 'b')
			write (1, "sb", 2);
		if (ab == 'a' || ab == 'b')
			write (1, "\n", 1);
	}
}

void	swap_both(int *stack_a, int *stack_b, int *len)
{
	swap(stack_a, &len[0], 'x');
	swap(stack_b, &len[1], 'x');
	write(1, "ss", 2);
	write (1, "\n", 1);
}
