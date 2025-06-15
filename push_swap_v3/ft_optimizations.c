/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:57:13 by jotong            #+#    #+#             */
/*   Updated: 2025/06/16 00:33:44 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	chunk_optmzns(int *stack, int *stack_b, int *len, int *b_len)
{
	if (stack_b[*b_len - 1] > stack_b[0])
		rr(stack, stack_b, len, b_len);
	else
		rotate(stack, len, 'a');
	if (stack[0] > stack[1] && *b_len > 2 && stack_b[1] > stack_b[0])
		swap_both(stack, stack_b, len, b_len);
}



