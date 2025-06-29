/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 20:47:16 by jotong            #+#    #+#             */
/*   Updated: 2025/06/29 22:53:39 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_sorted(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (!(stack[i] < stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_arr_dup(int *stack, int len)
{
	int	*dup;
	int	i;
	
	i = -1;
	dup = NULL;
	if (len > 0)
	{
		dup = malloc((len + 1) * sizeof(int));
		while (i++ < len)
			dup[i] = stack[i];
	}
	return (dup);
}

int	find_smallest(int *stack, int len)
{
	int	smallest;
	int	i;

	smallest = INT_MAX;
	i = 0;
	while (i < len)
	{
		if (smallest > stack[i])
			smallest = stack[i];
		i++;
	}
	return (smallest);
}

void	replace_with_rank(int *stack, int len, int *copy)
{
	int	index[2];
	int	*sorted;

	index[0] = -1;
	sorted = malloc ((len + 1) * sizeof(int));
	if (sorted)
	{
		while (index[0]++ < len)
			sorted[index[0]] = stack[index[0]];
		insertion_sort(sorted, len);
		index[0] = -1;
		while (index[0]++ < len)
		{
			index[1] = -1;
			while (index[1]++ < len)
			{
				if (stack[index[0]] == sorted[index[1]])
				{
					copy[index[0]] = index[1];
					break;
				}
			}
		}
		free(sorted);
	}
}
