/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:06:30 by jotong            #+#    #+#             */
/*   Updated: 2025/07/01 08:54:06 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	mv_smallest_frm_a(int **stacks, int *len, int n)
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
		if (len[0] < n)
			smallest = find_smallest(stacks[0], len[0]);
		else
			smallest = find_smallest(stacks[0], n);
		s_index = find_pos(stacks[0], smallest, len[0]);
		while (j++ < s_index)
			rotate(stacks[0], len, 'a');
		pushb(stacks[1], stacks[0], len);
		moved++;
		while (--j > 0)
			rev_rot(stacks[0], len, 'a');
	}
	return (moved);
}

int	mv_largest_frm_b(int **stacks, int *len, int n)
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
		s_index = find_ind_max(stacks[1], n);
		while (j++ < s_index)
			rotate(stacks[1], len, 'b');
		pusha(stacks[0], stacks[1], len);
		moved++;
		while (--j > 0)
			rev_rot(stacks[1], len, 'b');
	}
	return (moved);
}

void	move_back_a(int **stacks, int *len, int n)
{
	if (len[0] < n)
		while (len[0] < n)
			pusha(stacks[0], stacks[1], len);
	else
		while (n-- > 0)
			pusha(stacks[0], stacks[1], len);
}

void	sort_small_a(int **stacks, int *len, int n)
{
	int moved;

	moved = 0;
	if (n == 0)
		return ;
	if (n > 3)
		moved = mv_smallest_frm_a(stacks, len, n);
	sort_stack(stacks[0], len, n);
	if (len[0] < n && moved > 0)
		move_back_a(stacks, len, n);
	else if (moved > 0)
		move_back_a(stacks, len, moved);
}

void	sort_small_b(int **stacks, int *len, int n)
{
	int i;
	int	moved;

	i = 0;
	moved = 0;
	if (n == 0)
		return ;
	if (n > 3)
	{
		moved = mv_largest_frm_b(stacks, len, n);
		n -= moved;
	}
	sort_stack_b(stacks[1], len, n);
	while (i++ < n)
		pusha(stacks[0], stacks[1], len);
}

int	*sort_a_base(int **stacks, int *len, int *sml_bg, int *counts)
{
	// pushes the top n into the respective parts of the stacks
	if (stacks[0][0] >= sml_bg[1])
	{
		rotate(stacks[0], len, 'a');
		counts[2]++;
	}
	else if (stacks[0][0] >= sml_bg[0])
	{
		pushb(stacks[1], stacks[0], len);
		counts[1]++;
	}
	else
	{
		pushb(stacks[1], stacks[0], len);
		rotate(stacks[1], len, 'b');
		counts[0]++;
	}
	return (counts);
}

void	sort_a_top(int **stacks, int *len, int n)
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
		sort_small_a(stacks, len, n);
	else
	{
		find_mids_a(stacks[0], n, sml_bg_tmp);
		if (!is_sorted(stacks[0], n))
			while (i++ < n)
				count_tmp = sort_a_base(stacks, len, sml_bg_tmp, count_tmp);
		sort_a_btm(stacks, len, count_tmp[2]);
		sort_b_top(stacks, len, count_tmp[1]);
		sort_b_btm(stacks, len, count_tmp[0]);
	}
	free(sml_bg_tmp);
	free (count_tmp);
}

void	sort_a_btm(int **stacks, int *len, int n)
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
	if (len[0] > n)
		while (i++ < n)
			rev_rot(stacks[0], len, 'a');
	if (n <= 5)
		sort_small_a(stacks, len, n);
	else
		{
			find_mids_a(stacks[0], n, sml_bg_tmp);
			if (!is_sorted(stacks[0], n))
			{
				i = 0;
				while (i++ < n)
					count_tmp = sort_a_base(stacks, len, sml_bg_tmp, count_tmp);
			}
			if (count_tmp[2] > 0 && len[0] > count_tmp[2])
				sort_a_btm(stacks, len, count_tmp[2]);
			if (count_tmp[1] > 0 && (stacks[0][0] - stacks[1][0]) <= count_tmp[1])
				sort_b_top(stacks, len, count_tmp[1]);
			sort_b_btm(stacks, len, count_tmp[0]);
		}
	free(sml_bg_tmp);
	free (count_tmp);
}

int	*sort_b_base(int **stacks, int *len, int *sml_bg, int *counts)
{
	if (stacks[1][0] >= sml_bg[1])
	{
		// largest
		pusha(stacks[0], stacks[1], len);
		counts[2]++;
	}
	else if (stacks[1][0] >= sml_bg[0])
	{
		// middle
		pusha(stacks[0], stacks[1], len);
		rotate(stacks[0], len, 'a');
		counts[1]++;
	}
	else
	{
		// smallest
		rotate(stacks[1], len, 'b');
		counts[0]++;
	}
	return (counts);
}


void sort_b_btm(int **stacks, int *len, int n)
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
		rev_rot(stacks[1], len, 'b');
	if (n <= 5)
		sort_small_b(stacks, len, n);
	else
	{
		find_mids_b(stacks[1], n, sml_bg_tmp);
		i = 0;
		if (!is_rev_sorted(stacks[1], n))
			while (i++ < n)
				count_tmp = sort_b_base(stacks, len, sml_bg_tmp, count_tmp);
		sort_a_top(stacks, len, count_tmp[2]);
		sort_a_btm(stacks, len, count_tmp[1]);
		sort_b_btm(stacks, len, count_tmp[0]);
	}
	free(sml_bg_tmp);
	free(count_tmp);
}

void	sort_b_top(int **stacks, int *len, int n)
{
	int i;
	int *count_tmp;
	int *sml_bg_tmp;

	count_tmp = (int *)ft_calloc(3, sizeof(int));
	sml_bg_tmp = (int *)ft_calloc(2, sizeof(int));
	if (!count_tmp || !sml_bg_tmp)
		return ;
	if (n <= 5)
		sort_small_b(stacks, len, n);
	else
	{
		i = 0;
		find_mids_b(stacks[1], n, sml_bg_tmp);
		if (!is_sorted(stacks[1], n))
			while (i++ < n)
			count_tmp = sort_b_base(stacks, len, sml_bg_tmp, count_tmp);
		sort_a_top(stacks, len, count_tmp[2]);
		sort_a_btm(stacks, len, count_tmp[1]);
		sort_b_btm(stacks, len, count_tmp[0]);
	}
	free(sml_bg_tmp);
	free(count_tmp);
}

void	ft_sort_b(int **stacks, int *len, int *counts)
{
	sort_a_btm(stacks, len, counts[2]);
	sort_b_top(stacks, len, counts[1]);
	sort_b_btm(stacks, len, counts[0]);
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

int	**presort_stack(int **stacks, int *len, int n)
{
	int	j;
	int	*sml_bg;
	int	i;
	int	len_tmp;
	int	**counts_psrt;

	j = 1;
	counts_psrt = set_psrt_count(*len);
	sml_bg = (int *)ft_calloc(2, sizeof(int)); 
	if (!counts_psrt || !sml_bg)
	{
		free_entire_array(counts_psrt, counts_psrt[0][0]);
		free(sml_bg);
		return (NULL);
	}
	if (n <= 5)
	{
		sort_small_a(stacks, len, n);
		free(sml_bg);
		return (0);
	}
	while (len[0] > 7)
	{
		find_mids_a(stacks[0], len[0], sml_bg);
		i = 0;
		len_tmp = len[0];
		i = 0;
		while (i++ < len_tmp)
			counts_psrt[j] = sort_a_base(stacks, len, sml_bg, counts_psrt[j]);
		j++;
	}
	sort_small_a(stacks, len, len[0]);
	free(sml_bg);
	return (counts_psrt);
}

void	sort_back(int **stacks, int *len, int **counts)
{
	int	i;

	i = counts[0][0] - 1;
	while (i > 0)
	{
		ft_sort_b(stacks, len, counts[i]);
		i--;
	}
}
