/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:19:57 by jotong            #+#    #+#             */
/*   Updated: 2025/06/06 09:41:00 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - pa (push a): Take the first element at the top of b and put it at the top of a.
//     Do nothing if b is empty.
// - pb (push b): Take the first element at the top of a and put it at the top of b.
//     Do nothing if a is empty.

#include "ft_push_swap.h"

void	push(int	*stack_dest, int *stack_src, int *len_dest, int *len_src)
{
	if (stack_dest[0] != 0)
	{
		ft_memmove(&stack_dest[1], &stack_dest[0], (*len_dest - 1) * sizeof(int));
		stack_dest[0] = stack_src[0];
		ft_memmove(&stack_src[0], &stack_src[1], (*len_src - 1) * sizeof(int));
		stack_src[*len_src - 1] = 0;
	}
}

int	main(void)
{
	int	a[6] = {1, 2, 3, 4, 5};
	int	b[5] = {5, 4, 3, 2, 1};
	int	len_a = 6;
	int	len_b = 5;

	push(a, b, &len_a, &len_b);
	printf("a = ");
	print_stack(a, &len_a);
	printf("b = ");
	print_stack(b, &len_b);
	push(b, a, &len_b, &len_a); 
	printf("a = ");
	print_stack(a, &len_a);
	printf("b = ");
	print_stack(b, &len_b);
}