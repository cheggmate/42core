/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 23:00:08 by jotong            #+#    #+#             */
/*   Updated: 2025/06/30 00:21:52 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	rest_is_sorted(int *stack, int len, int rem_len)
{
	int	i;

	i = 2;
	if (rem_len > len)
		rem_len = len;
	while (i < rem_len - 1)
	{
		if (!(stack[i] < stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	sort_rest(int **stacks, int *len)
{
	int	is_swapped;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (len[0] <= 1 || is_sorted(stacks[0], len[0]))
		return ;
	while (i++ < len[0] - 1)
	{
		is_swapped = 0;
		while (j++ < len[0] - 1)
		{
			if (stacks[0][i] > stacks[0][i+1])
			{
				swap(stacks[0], len, 'a');
				is_swapped = 1;
			}
			if (j < len[0] - 2 - i)
				rotate(stacks[0], len, 'a');
		}
		if (is_swapped == 0)
			return ;
	}

}
