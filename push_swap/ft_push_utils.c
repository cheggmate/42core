/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:19:57 by jotong            #+#    #+#             */
/*   Updated: 2025/06/06 00:04:59 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - pa (push a): Take the first element at the top of b and put it at the top of a.
//     Do nothing if b is empty.
// - pb (push b): Take the first element at the top of a and put it at the top of b.
//     Do nothing if a is empty.

#include "ft_push_swap.h"

void	push_a(int	*stack_a, int *stack_b, int *len_a, int *len_b)
{
	if (stack_a[0] != 0)
		ft_memmove(&stack_a[1], &stack_a[0], (*len_a - 1) * sizeof(int));
	stack_a[0] = stack_b[0];
	if (stack_b[0] != 0)
		ft_memmove(&stack_b[0], &stack_b[1], (*len_b - 1) * sizeof(int));
	stack_b[*len_b - 1] = 0;
}

void	push_b(int *stack_a, int *stack_b ,int *len_a, int *len_b)
{
	int	*tmp_b;

	if (stack_b[0] != 0)
		ft_memmove(&stack_b[1], &stack_b[0], *len_b * sizeof(int));
	stack_b[0] = stack_a[0];
	if (stack_a[0] != 0)
		ft_memmove(&stack_a[0], &stack_a[1], (*len_a - 1) * sizeof(int));
	stack_a[*len_a - 1] = 0;
}
// 
// int	main(void)
// {
// 	int		a[6]= {5, 1, 2, 3, 4, 0};
// 	int		b[4] = {6, 0, 0, 0};
// 	int		len_a = 6;
// 	int		len_b = 4;

// 	push_a(a, b, &len_a, &len_b);
// 	print_stack(a, &len_a);
// 	print_stack(b, &len_b);
// }
