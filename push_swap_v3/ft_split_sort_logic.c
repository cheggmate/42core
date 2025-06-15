/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/06/15 21:29:21 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


void	sort_stack(int *stack, int len)
{
	int	largest;
	// int i = 0;

	largest = find_largest(stack, len);
	while (is_sorted(stack, len) == 0)
	{
		if (stack[0] == largest)
			rev_rot(stack, &len, 'a');
		else if (stack[0] > stack[1])
			swap(stack, &len, 'a');
		else
			rev_rot(stack, &len, 'a');
	}
}
