/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:37:37 by jotong            #+#    #+#             */
/*   Updated: 2025/06/15 22:23:19 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	insertion_sort(int	*stack_dup, int len)
{
	int i;
	int	val;
	int j;

	i = 1;
	while (i < len)
	{
		val = stack_dup[i];
		j = i - 1;

		while (j >= 0 && stack_dup[j] > val)
		{
			stack_dup[j + 1] = stack_dup[j];
			j--;
		}
		stack_dup[j + 1] = val;
		i++;
	}
}

void	find_mids(int *stack, int len, int *smlr, int *bgr)
{
	int			*stack_dup;

	stack_dup = ft_arr_dup(stack, len);
	*smlr = 0;
	*bgr = 0;
	if (stack_dup)
	{
		insertion_sort(stack_dup, len);
		if (len > 6 && len % 2 == 0)
		{
			*smlr = (stack_dup[(len - 6) / 2 - 1] + stack_dup[(len - 6) / 2]) / 2.0;
			*bgr = stack_dup[len - 6 - 1];
		}
		else if (len > 6)
		{
			*smlr = stack_dup[(len - 6) / 2];
			*bgr = stack_dup[len - 6 - 2];
		}	
	}
	free (stack_dup);
}
