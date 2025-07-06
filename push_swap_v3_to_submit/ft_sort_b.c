/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:13:31 by jotong            #+#    #+#             */
/*   Updated: 2025/07/07 00:22:24 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_small_b(t_stack *stack, t_list_ops *curr, int n)
{
	int	i;
	int	moved;
	int	smallest;

	i = 0;
	moved = 0;
	smallest = find_ind_min(stack->stack_b, stack->len_b);
	if (n == 0)
		return ;
	if (n > 3)
	{
		if (smallest == n - 1)
			sort_small_b(stack, curr, n - 1);
		moved = mv_largest_frm_b(stack, curr, n);
		n -= moved;
	}
	sort_stack_b(stack, curr, n);
	while (i++ < n)
		pusha(stack, curr);
}

int	mv_largest_frm_b(t_stack *stack, t_list_ops *curr, int n)
{
	int	s_index;
	int	i;
	int	j;
	int	moved;

	i = 0;
	j = 0;
	moved = 0;
	while (i++ < n - 3)
	{
		s_index = find_ind_max(stack->stack_b, n);
		while (j++ < s_index)
			rotate(stack->stack_b, stack->len_b, curr, 'b');
		pusha(stack, curr);
		moved++;
		while (--j > 0)
			rev_rot(stack->stack_b, stack->len_b, curr, 'b');
	}
	return (moved);
}

void	sort_b_top(t_stack *stack, t_list_ops *curr, int n)
{
	int	i;
	int	*count_tmp;
	int	*sml_bg_tmp;

	count_tmp = (int *)ft_calloc(3, sizeof(int));
	sml_bg_tmp = (int *)ft_calloc(2, sizeof(int));
	if (!count_tmp || !sml_bg_tmp)
		return ;
	if (n <= 5)
		sort_small_b (stack, curr, n);
	else
	{
		i = 0;
		find_mids_b(stack->stack_b, n, sml_bg_tmp);
		if (!is_sorted(stack->stack_b, n))
			while (i++ < n)
				count_tmp = sort_b_base(stack, sml_bg_tmp, count_tmp, curr);
		sort_a_top(stack, curr, count_tmp[2]);
		sort_a_btm(stack, curr, count_tmp[1]);
		sort_b_btm(stack, curr, count_tmp[0]);
	}
	free (sml_bg_tmp);
	free (count_tmp);
}

void	sort_b_btm(t_stack *stack, t_list_ops *curr, int n)
{
	int	i;
	int	*count_tmp;
	int	*sml_bg_tmp;

	i = 0;
	count_tmp = ft_calloc(3, sizeof(int));
	sml_bg_tmp = (int *)ft_calloc(2, sizeof(int));
	if (!count_tmp || !sml_bg_tmp)
		return ;
	sml_bg_tmp[0] = 0;
	if (stack->len_b > n)
		while (i++ < n)
			rev_rot(stack->stack_b, stack->len_b, curr, 'b');
	sort_b_top(stack, curr, n);
	free(sml_bg_tmp);
	free(count_tmp);
}

int	*sort_b_base(t_stack *stack, int *sml_bg, int *counts, t_list_ops *curr)
{
	if (stack->stack_b[0] >= sml_bg[1])
	{
		pusha(stack, curr);
		counts[2]++;
	}
	else if (stack->stack_b[0] >= sml_bg[0])
	{
		pusha(stack, curr);
		rotate(stack->stack_a, stack->len_a, curr, 'a');
		counts[1]++;
	}
	else
	{
		rotate(stack->stack_b, stack->len_b, curr, 'b');
		counts[0]++;
	}
	return (counts);
}
