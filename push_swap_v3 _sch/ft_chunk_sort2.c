/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:57:13 by jotong            #+#    #+#             */
/*   Updated: 2025/06/17 20:43:39 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	chunk_optmzns(int *stack, int *stack_b, int *len)
{
	if (stack_b[len[1] - 1] > stack_b[0])
		rr(stack, stack_b, len);
	else
		rotate(stack, len, 'a');
	if (stack[0] > stack[1] && len[1] > 2 && stack_b[1] > stack_b[0])
		swap_both(stack, stack_b, len);
}
