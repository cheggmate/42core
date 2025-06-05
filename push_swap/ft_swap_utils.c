/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:07:33 by jotong            #+#    #+#             */
/*   Updated: 2025/06/05 11:24:28 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Operations available: 
// - sa (swap a): Swap the first 2 elements at the top of stack a.
//     Do nothing if there is only one element or none.
// - sb (swap b): Swap the first 2 elements at the top of stack b.
//     Do nothing if there is only one element or none.
// - ss : sa and sb at the same time.

#include "ft_push_swap.h"

void	swap_a(char	*stack_a)
{
	int	tmp;

	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
}

void	swap_b(char	*stack_b)
{
	int	tmp;

	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
}

void	swap_both(char *stack_a, char *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
