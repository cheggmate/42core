/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:37:37 by jotong            #+#    #+#             */
/*   Updated: 2025/07/07 22:12:41 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	insertion_sort(int	*stack_dup, int len)
{
	int	i;
	int	val;
	int	j;

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

void	find_mids_a(int *stack, int len, int *sml_bg)
{
	int			*stack_dup;

	stack_dup = ft_arr_dup(stack, len);
	if (stack_dup)
	{
		insertion_sort(stack_dup, len);
		if (len > 15)
		{
			sml_bg[1] = stack_dup[len / 3 * 2 - 1];
			sml_bg[0] = stack_dup[len / 3 - 1];
		}
		else if (len > 6)
		{
			sml_bg[1] = stack_dup[len - 5];
			sml_bg[0] = stack_dup[(len - 5) / 2];
		}
		else
		{
			sml_bg[1] = stack_dup[len - 2];
			sml_bg[0] = stack_dup[(len - 2) / 2];
		}
	}
	free (stack_dup);
}

void	find_mids_b(int *stack, int len, int *sml_bg)
{
	int			*stack_dup;

	stack_dup = ft_arr_dup(stack, len);
	if (stack_dup)
	{
		insertion_sort(stack_dup, len);
		if (len > 3 && len % 2 == 0)
		{
			sml_bg[1] = stack_dup[len / 3 * 2];
			sml_bg[0] = stack_dup[len / 3 - 1];
		}
		else if (len > 3)
		{
			sml_bg[1] = stack_dup[len / 3 * 2];
			sml_bg[0] = stack_dup[len / 3];
		}
	}
	free (stack_dup);
}
