/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:06:30 by jotong            #+#    #+#             */
/*   Updated: 2025/07/02 00:58:18 by jotong           ###   ########.fr       */
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
	while(i++ < n - 3)
	{
		if (stack->len_a < n)
			smallest = find_smallest(stack->stack_a, stack->len_a);
		else
			smallest = find_smallest(stack->stack_a, n);
		s_index = find_pos(stack->stack_a, smallest, stack->len_a);
		while (j++ < s_index)
			rotate(stack->stack_a, stack->len_a, curr, 'a');
		pushb(stack, curr);
		moved++;
		while (--j > 0)
			rev_rot(stack->stack_a, stack->len_a, curr, 'a');
	}
	return (moved);
}

int	mv_largest_frm_b(t_stack *stack, t_list_ops *curr, int n)
{
	int	s_index;
	int i;
	int j;
	int	moved;

	i = 0;
	j = 0;
	moved = 0;
	while(i++ < n - 3)
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
	int moved;

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

void	sort_small_b(t_stack *stack, t_list_ops *curr, int n)
{
	int i;
	int	moved;

	i = 0;
	moved = 0;
	if (n == 0)
		return ;
	if (n > 3)
	{
		moved = mv_largest_frm_b(stack, curr, n);
		n -= moved;
	}
	sort_stack_b(stack, curr, n);
	while (i++ < n)
		pusha(stack, curr);
}

int	*sort_a_base(t_stack *stack, int *sml_bg, int *counts, t_list_ops *curr)
{
	// pushes the top n into the respective parts of the stacks
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
	int i;
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
	int i;
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
	if (n <= 5)
		sort_small_a(stack, curr, n);
	else
		{
			find_mids_a(stack->stack_a, n, sml_bg_tmp);
			if (!is_sorted(stack->stack_a, n))
			{
				i = 0;
				while (i++ < n)
					count_tmp = sort_a_base(stack, sml_bg_tmp, count_tmp, curr);
			}
			if (count_tmp[2] > 0 && stack->len_a > count_tmp[2])
				sort_a_btm(stack, curr, count_tmp[2]);
			if (count_tmp[1] > 0 && (stack->stack_a[0] - stack->stack_b[0]) <= count_tmp[1])
				sort_b_top(stack, curr, count_tmp[1]);
			sort_b_btm(stack, curr, count_tmp[0]);
		}
	free(sml_bg_tmp);
	free (count_tmp);
}

int	*sort_b_base(t_stack *stack, int *sml_bg, int *counts, t_list_ops *curr)
{
	if (stack->stack_b[0] >= sml_bg[1])
	{
		// largest
		pusha(stack, curr);
		counts[2]++;
	}
	else if (stack->stack_b[0] >= sml_bg[0])
	{
		// middle
		pusha(stack, curr);
		rotate(stack->stack_a, stack->len_a, curr, 'a');
		counts[1]++;
	}
	else
	{
		// smallest
		rotate(stack->stack_b, stack->len_b, curr, 'b');
		counts[0]++;
	}
	return (counts);
}


void sort_b_btm(t_stack *stack, t_list_ops *curr, int n)
{
	int i;
	int *count_tmp;
	int	*sml_bg_tmp;

	i = 0;
	count_tmp = ft_calloc(3, sizeof(int));
	sml_bg_tmp = (int *)ft_calloc(2, sizeof(int));
	if (!count_tmp || !sml_bg_tmp)
		return ;
	sml_bg_tmp[0] = 0;
	while (i++ < n)
		rev_rot(stack->stack_b, stack->len_b, curr, 'b');
	if (n <= 5)
		sort_small_b(stack, curr, n);
	else
	{
		find_mids_b(stack->stack_b, n, sml_bg_tmp);
		i = 0;
		if (!is_rev_sorted(stack->stack_b, n))
			while (i++ < n)
				count_tmp = sort_b_base(stack, sml_bg_tmp, count_tmp, curr);
		sort_a_top(stack, curr, count_tmp[2]);
		sort_a_btm(stack, curr, count_tmp[1]);
		sort_b_btm(stack, curr, count_tmp[0]);
	}
	free(sml_bg_tmp);
	free(count_tmp);
}

void	sort_b_top(t_stack *stack, t_list_ops *curr, int n)
{
	int i;
	int *count_tmp;
	int *sml_bg_tmp;

	count_tmp = (int *)ft_calloc(3, sizeof(int));
	sml_bg_tmp = (int *)ft_calloc(2, sizeof(int));
	if (!count_tmp || !sml_bg_tmp)
		return ;
	if (n <= 5)
		sort_small_b(stack, curr, n);
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
	free(sml_bg_tmp);
	free(count_tmp);
}

void	ft_sort_b(t_stack *stack, t_list_ops *curr, int *counts)
{
	sort_a_btm(stack, curr, counts[2]);
	sort_b_top(stack, curr, counts[1]);
	sort_b_btm(stack, curr, counts[0]);
}

int	**set_psrt_count(int len)
{
	int i;
	int	iter_count;
	int	**counts_psrt;

	i = 0;
	iter_count = (log10(len) / log10(3)) + 2;
	counts_psrt = ft_calloc((iter_count + 1),  sizeof(int *));
	if (!counts_psrt)
		return (NULL);
	while (i++ < iter_count)
		counts_psrt[i] = NULL;
	counts_psrt[0] = ft_calloc(2,  sizeof(int));
	if (!counts_psrt[0])
	{
		free (counts_psrt);
		return (NULL);
	}
	i = 1;
	while (i < iter_count)
	{
		counts_psrt[i] = ft_calloc(3,  sizeof(int));
		if (!counts_psrt[i])
		{
			free_entire_array(counts_psrt, i);
			break;
		}
		i++;
	}
	counts_psrt[0][0] = iter_count;
	return (counts_psrt);
}

int	**presort_stack(t_stack *stack, t_list_ops *curr)
{
	int	j;
	int	*sml_bg;
	int	i;
	int	len_tmp;
	int	**counts_psrt;

	j = 1;
	counts_psrt = set_psrt_count(stack->len_a);
	sml_bg = (int *)ft_calloc(2, sizeof(int)); 
	if (!counts_psrt || !sml_bg)
	{
		free_entire_array(counts_psrt, counts_psrt[0][0]);
		free(sml_bg);
		return (NULL);
	}
	if (stack->len_a <= 5)
	{
		sort_small_a(stack, curr, stack->len_a);
		free(sml_bg);
		return (0);
	}
	while (stack->len_a > 7)
	{
		find_mids_a(stack->stack_a, stack->len_a, sml_bg);
		i = 0;
		len_tmp = stack->len_a;
		i = 0;
		while (i++ < len_tmp)
			counts_psrt[j] = sort_a_base(stack, sml_bg, counts_psrt[j], curr);
		j++;
	}
	sort_small_a(stack, curr, stack->len_a);
	free(sml_bg);
	return (counts_psrt);
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
