/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:06:30 by jotong            #+#    #+#             */
/*   Updated: 2025/07/06 14:39:09 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	mv_smallest_frm_a(t_stack *stack, t_list_ops *curr, int n)
{
	int	smallest;
	int	s_index;
	int	i;
	int	j;
	int	moved;

	i = 0;
	j = 0;
	moved = 0;
	while (i++ < n - 3)
	{
		if (stack->len_a < n)
			smallest = find_smallest(stack->stack_a, stack->len_a);
		else
			smallest = find_smallest(stack->stack_a, n);
		s_index = find_pos (stack->stack_a, smallest, stack->len_a);
		while (j++ < s_index)
			rotate (stack->stack_a, stack->len_a, curr, 'a');
		pushb (stack, curr);
		moved++;
		while (--j > 0)
			rev_rot (stack->stack_a, stack->len_a, curr, 'a');
	}
	return (moved);
}

int	**set_psrt_count(int len)
{
	int	i;
	int	iter_count;
	int	**counts_psrt;

	i = 0;
	iter_count = (log10(len) / log10(3)) + 4;
	counts_psrt = ft_calloc((iter_count + 1), sizeof(int *));
	if (!counts_psrt)
		return (NULL);
	counts_psrt[0] = ft_calloc(2, sizeof(int));
	i = 1;
	while (i < iter_count)
	{
		counts_psrt[i] = ft_calloc(3, sizeof(int));
		if (!counts_psrt[0] || !counts_psrt[i])
		{
			free_entire_array(counts_psrt, i);
			break ;
		}
		i++;
	}
	counts_psrt[0][0] = iter_count;
	return (counts_psrt);
}

void	ft_sort_b(t_stack *stack, t_list_ops *curr, int *counts)
{
	sort_a_btm(stack, curr, counts[2]);
	sort_b_top(stack, curr, counts[1]);
	sort_b_btm(stack, curr, counts[0]);
}

int	**presort_stack(t_stack *stack, t_list_ops *curr, int *sml_bg)
{
	int	j;
	int	i;
	int	len_tmp;
	int	**cts_psrt;

	j = 1;
	cts_psrt = set_psrt_count(stack->len_a);
	if (cts_psrt)
	{
		while (stack->len_a > 6)
		{
			find_mids_a(stack->stack_a, stack->len_a, sml_bg);
			len_tmp = stack->len_a;
			i = 0;
			while (i++ < len_tmp)
				cts_psrt[j] = sort_a_base(stack, sml_bg, cts_psrt[j], curr);
			j++;
		}
		sort_small_a_presort(stack, curr, stack->len_a);
		free(sml_bg);
		return (cts_psrt);
	}
	free_entire_array(cts_psrt, cts_psrt[0][0]);
	free(sml_bg);
	return (NULL);
}

void	sort_back(t_stack *stack, t_list_ops *curr, int **counts)
{
	int	i;

	i = counts[0][0] - 1;
	while (i > 0)
	{
		ft_sort_b(stack, curr, counts[i]);
		i--;
	}
}
