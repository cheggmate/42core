/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:19:57 by jotong            #+#    #+#             */
/*   Updated: 2025/06/15 15:41:55 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - pa (push a): Take the first element at the top of b and put it at the top of a.
//     Do nothing if b is empty.
// - pb (push b): Take the first element at the top of a and put it at the top of b.
//     Do nothing if a is empty.

#include "ft_push_swap.h"

int	pusha(int	*stack_dest, int *stack_src, int *len_dest, int *len_src)
{
	if (*len_src > 0)
	{
		if (*len_dest > 0)
			ft_memmove(&stack_dest[1], &stack_dest[0], (*len_dest) * sizeof(int));
		stack_dest[0] = stack_src[0];
		*len_dest += 1;
		ft_memmove(&stack_src[0], &stack_src[1], (*len_src - 1) * sizeof(int));
		stack_src[*len_src - 1] = 0;
		*len_src -= 1;
		write (1, "pa", 2);
		write (1, "\n", 1);
		return (1);
	}
	return (0);
}

int	pushb(int	*stack_dest, int *stack_src, int *len_dest, int *len_src)
{
	if (*len_src > 0)
	{
		if (*len_dest > 0)
			ft_memmove(&stack_dest[1], &stack_dest[0], (*len_dest) * sizeof(int));
		stack_dest[0] = stack_src[0];
		*len_dest += 1;
		ft_memmove(&stack_src[0], &stack_src[1], (*len_src - 1) * sizeof(int));
		stack_src[*len_src - 1] = 0;
		*len_src -= 1;
		write (1, "pb", 2);
		write (1, "\n", 1);
		return (1);
	}
	return (0);
}
