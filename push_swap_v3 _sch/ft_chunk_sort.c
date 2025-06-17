/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:34:48 by jotong            #+#    #+#             */
/*   Updated: 2025/06/16 22:55:31 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	replace_with_rank(int *stack, int len, int *copy, int *sorted)
{
	int	i;
	int j;

	i = -1;
	sorted = malloc (len * sizeof(int));
	if (sorted)
	{
		while (i++ < len)
			sorted[i] = stack[i];
		insertion_sort(sorted, len);
	}
	i = -1;
	while (i++ < len)
	{
		j = -1;
		while (j++ < len)
		{
			if (stack[i] == sorted[j])
			{
				copy[i] = j;
				break;
			}
		}
	}
	free(sorted);
}

int	find_ind_max(int *stack_b, int b_len)
{
	int	max;
	int	i;
	int	index;

	i = 0;
	max = stack_b[0];
	while (i++ < b_len)
	{
		if (stack_b[i] > max)
		{
			max = stack_b[i];
			index = i;
		} 
	}
	return (index);
}

void	sorted_return(int *stack, int *stack_b, int *len)
{
	int	max;

	while (len[1] > 0)
	{
		max = find_ind_max(stack_b, len[1]);
		if (max <= len[1] / 2)
		{
			while (max-- > 0)
				rotate(stack_b, len, 'b');
		}
		else
		{
			max = len[1] - max;
			while (max-- > 0)
				rev_rot(stack_b, len, 'b');
		}
		pusha(stack, stack_b, len);
	}
}

static void	chunk_sort(int *stack, int *stack_b, int *len)
{
	int	chunk_size;
	int	low;
	int	i;
	int	pushed;
	int	size;

	size = len[0];
	chunk_size = (len[0] <= 100) ? 15 : 30; // chunk_size = len[0] / 5 + 1;
	low = 0;
	while (low < size)
	{
		i = -1;
		pushed = 0;
		while (i++ < size && pushed < chunk_size)
		{
			if (stack[0] >= low && stack[0] <= (low + chunk_size - 1))
				pushed += pushb(stack_b, stack, len);
			else
				// rotate(stack, len, 'a');
				chunk_optmzns(stack, stack_b, len);
		}
		low += chunk_size;
	}
	sorted_return(stack, stack_b, len);
}

void	start_chunking(int *stack, int *stack_b, int *len)
{
	int	*copy;
	int *sorted;

	sorted = NULL;
	copy = malloc(len[0] * sizeof(int));
	if (copy)
	{
		replace_with_rank(stack, len[0], copy, sorted);
		chunk_sort(copy, stack_b, len);
	}
	free(copy);
}
