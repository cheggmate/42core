/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:18:22 by jotong            #+#    #+#             */
/*   Updated: 2025/07/04 23:34:08 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	move_back_a(t_stack *stack, t_list_ops *curr, int n)
{
	if (stack->len_a < n)
		while (stack->len_a < n)
			pusha(stack, curr);
	else
		while (n-- > 0)
			pusha(stack, curr);
}

void	sort_small_a(t_stack *stack, t_list_ops *curr, int n)
{
	int	moved;

	moved = 0;
	if (n == 0)
		return ;
	if (n > 3)
		moved = mv_smallest_frm_a(stack, curr, n);
	sort_stack(stack, curr, n);
	if (stack->len_a < n && moved > 0)
		move_back_a(stack, curr, n);
	else if (moved > 0)
		move_back_a(stack, curr, moved);
}

int	*sort_a_base(t_stack *stack, int *sml_bg, int *counts, t_list_ops *curr)
{
	if (stack->stack_a[0] >= sml_bg[1])
	{
		rotate(stack->stack_a, stack->len_a, curr, 'a');
		counts[2]++;
	}
	else if (stack->stack_a[0] >= sml_bg[0])
	{
		pushb(stack, curr);
		counts[1]++;
	}
	else
	{
		pushb(stack, curr);
		rotate(stack->stack_b, stack->len_b, curr, 'b');
		counts[0]++;
	}
	return (counts);
}

void	sort_a_top(t_stack *stack, t_list_ops *curr, int n)
{
	int	i;
	int	*count_tmp;
	int	*sml_bg_tmp;

	i = 0;
	count_tmp = (int *)ft_calloc(3, sizeof(int));
	sml_bg_tmp = (int *)ft_calloc(2, sizeof(int));
	if (!count_tmp || ! sml_bg_tmp)
		return ;
	if (n <= 5)
		sort_small_a(stack, curr, n);
	else
	{
		find_mids_a(stack->stack_a, n, sml_bg_tmp);
		if (!is_sorted(stack->stack_a, n))
			while (i++ < n)
				count_tmp = sort_a_base(stack, sml_bg_tmp, count_tmp, curr);
		sort_a_btm(stack, curr, count_tmp[2]);
		sort_b_top(stack, curr, count_tmp[1]);
		sort_b_btm(stack, curr, count_tmp[0]);
	}
	free(sml_bg_tmp);
	free (count_tmp);
}

void	sort_a_btm(t_stack *stack, t_list_ops *curr, int n)
{
	int	i;
	int	*count_tmp;
	int	*sml_bg_tmp;

	i = 0;
	count_tmp = (int *)ft_calloc(3, sizeof(int));
	sml_bg_tmp = (int *)ft_calloc(2, sizeof(int));
	if (!count_tmp || !sml_bg_tmp)
		return ;
	i = 0;
	if (stack->len_a > n)
		while (i++ < n)
			rev_rot(stack->stack_a, stack->len_a, curr, 'a');
	sort_a_top(stack, curr, n);
	free(sml_bg_tmp);
	free (count_tmp);
}
