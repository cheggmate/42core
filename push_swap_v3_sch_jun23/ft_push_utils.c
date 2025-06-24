/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:19:57 by jotong            #+#    #+#             */
/*   Updated: 2025/06/16 22:25:47 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - pa (push a): Take the first element at the top of b and put it at the top of a.
//     Do nothing if b is empty.
// - pb (push b): Take the first element at the top of a and put it at the top of b.
//     Do nothing if a is empty.

#include "ft_push_swap.h"

int	pusha(int	*stack_dest, int *stack_src, int *len)
{
	if (len[1] > 0)
	{
		if (len[0] > 0)
			ft_memmove(&stack_dest[1], &stack_dest[0], (len[0]) * sizeof(int));
		stack_dest[0] = stack_src[0];
		len[0] += 1;
		ft_memmove(&stack_src[0], &stack_src[1], (len[1] - 1) * sizeof(int));
		stack_src[len[1] - 1] = 0;
		len[1] -= 1;
		write (1, "pa", 2);
		write (1, "\n", 1);
		return (1);
	}
	return (0);
}

int	pushb(int	*stack_dest, int *stack_src, int *len)
{
	if (len[0] > 0)
	{
		if (len[1] > 0)
			ft_memmove(&stack_dest[1], &stack_dest[0], (len[1]) * sizeof(int));
		stack_dest[0] = stack_src[0];
		len[1] += 1;
		ft_memmove(&stack_src[0], &stack_src[1], (len[0] - 1) * sizeof(int));
		stack_src[len[0] - 1] = 0;
		len[0] -= 1;
		write (1, "pb", 2);
		write (1, "\n", 1);
		return (1);
	}
	return (0);
}
