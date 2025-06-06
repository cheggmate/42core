/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:18:37 by jotong            #+#    #+#             */
/*   Updated: 2025/06/06 09:30:25 by jotong           ###   ########.fr       */
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

void	rotate(int *stack, int *len)
{
	int	tmp;

	tmp = 0;
	if (*len >= 2)
	{
		tmp = stack[0];
		ft_memmove(&stack[0], &stack[1], (*len - 1) * sizeof(int));
		stack[*len - 1] = tmp;
	}
}

void	rev_rot(int *stack, int *len)
{
	int	tmp;

	tmp = 0;
	if (*len >= 2)
	{
		tmp = stack[0];
		ft_memmove(&stack[0], &stack[1], (*len - 1) * sizeof(int));
		stack[*len - 1] = tmp;
	}
}

// int	main(void)
// {
// 	int	a[5] = {1, 2, 3, 4, 5};
// 	int	b[5] = {5, 4, 3, 2, 1};
// 	int	len_a = 5;
// 	int	len_b = 5;

// 	rotate(a, &len_a);
// 	print_stack(a, &len_a);
// 	rotate(b, &len_b);
// 	print_stack(b, &len_b);
// }
