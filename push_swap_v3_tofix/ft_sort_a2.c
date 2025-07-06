/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:07:27 by jotong            #+#    #+#             */
/*   Updated: 2025/07/07 00:49:09 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	put_scnd_lrgst(t_stack *stack, t_list_ops *curr, int scnd, int n)
{
	int	i;

	i = 0;
	if (n == 3)
		sort_stack(stack, curr, n);
	else
	{
		if (scnd > stack->len_a / 2)
		{
			while (i++ < (stack->len_a - scnd))
				rev_rot(stack->stack_a, stack->len_a, curr, 'a');
			pushb(stack, curr);
			while (i-- > 0)
				rotate(stack->stack_a, stack->len_a, curr, 'a');
		}
		else if (scnd <= stack->len_a / 2)
		{
			while (i++ < scnd)
				rotate(stack->stack_a, stack->len_a, curr, 'a');
			pushb(stack, curr);
			while (i-- > 1)
				rev_rot(stack->stack_a, stack->len_a, curr, 'a');
		}
	}
}

static void	sort_n_put_lrgst_back_to_end(t_stack *stack, t_list_ops *curr)
{
	if (!is_sorted(stack->stack_a, stack->len_a - 1))
	{
		sort_stack(stack, curr, 3);
		rev_rot(stack->stack_a, stack->len_a, curr, 'a');
		pusha(stack, curr);
		rotate(stack->stack_a, stack->len_a, curr, 'a');
		rotate(stack->stack_a, stack->len_a, curr, 'a');
	}
}

static void	sort_five(t_stack *stack, t_list_ops *curr, int n, int *top_two)
{
	int	moved;

	moved = 0;
	if (top_two[0] == stack->len_a - 1)
	{
		if (top_two[1] == stack->len_a - 2)
			sort_stack(stack, curr, 3);
		else
		{
			put_scnd_lrgst(stack, curr, top_two[1], n - 1);
			sort_n_put_lrgst_back_to_end(stack, curr);
		}
	}
	else
	{
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
}

static void	sort_five_opts(t_stack *stack, t_list_ops *curr, int n, int *top_2)
{
	int	i;

	i = 0;
	if (top_2[0] == stack->len_a - 2 && top_2[1] == stack->len_a - 1)
	{
		rev_rot(stack->stack_a, stack->len_a, curr, 'a');
		rev_rot(stack->stack_a, stack->len_a, curr, 'a');
		swap(stack, curr, 'a');
		rotate(stack->stack_a, stack->len_a, curr, 'a');
		rotate(stack->stack_a, stack->len_a, curr, 'a');
		sort_stack(stack, curr, n);
	}
	else if (top_2[0] - top_2[1] == 1)
	{
		if (top_2[0] > stack->len_a / 2)
			while (i++ < (stack->len_a - top_2[0] - 1))
				rev_rot(stack->stack_a, stack->len_a, curr, 'a');
		else
			while (i++ < top_2[0] + 1)
				rotate(stack->stack_a, stack->len_a, curr, 'a');
		sort_stack(stack, curr, n);
	}
}

void	sort_small_a_presort(t_stack *stack, t_list_ops *curr, int n)
{
	int	top_two[2];

	if (is_sorted(stack->stack_a, stack->len_a - 1))
		return ;
	top_two[0] = find_ind_max(stack->stack_a, stack->len_a);
	top_two[1] = find_pos(stack->stack_a,
			find_second_largest(stack->stack_a, stack->len_a),
			stack->len_a);
	if (n <= 1)
		return ;
	else if (n <= 3)
		sort_stack(stack, curr, n);
	else
	{
		sort_five_opts(stack, curr, n, top_two);
		if (!is_sorted(stack->stack_a, stack->len_a - 1))
			sort_five(stack, curr, n, top_two);
	}
}
