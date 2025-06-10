/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:07:33 by jotong            #+#    #+#             */
/*   Updated: 2025/06/09 20:30:15 by jotong           ###   ########.fr       */
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

	if (*len >= 2)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
		if (ab == 'a')
			write (1, "sa", 2);
		else
			write (1, "sb", 2);
		write (1, "\n", 1);
	}
}

void	swap_both(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	swap(stack_a, len_a, 'a');
	swap(stack_b, len_b, 'b');
}

// int	main(void)
// {
// 	int	a[5] = {1, 2, 3, 4, 5};
// 	int	b[5] = {5, 4, 3, 2, 1};
// 	int	len_a = 5;
// 	int	len_b = 5;

// 	swap(a, &len_a, 'a');
// 	print_stack(a, &len_a);
// 	swap(b, &len_b, 'b');
// 	print_stack(b, &len_b);
// }

// int	main(void)
// {
// 	int	a[5] = {1, 2, 3, 4, 5};
// 	int	b[5] = {5, 4, 3, 2, 1};
// 	int	len_a = 5;
// 	int	len_b = 5;

// 	rev_rot(a, &len_a);
// 	print_stack(a, &len_a);
// 	rev_rot(b, &len_b);
// 	print_stack(b, &len_b);
// }