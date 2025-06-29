/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:06:30 by jotong            #+#    #+#             */
/*   Updated: 2025/06/29 18:24:29 by jotong           ###   ########.fr       */
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
	printf("moving smallest from a\n");
	while(i++ < n - 3)
	{
		if (len[0] < n)
			smallest = find_smallest(stacks[0], len[0]);
		else
			smallest = find_smallest(stacks[0], n);
		s_index = find_pos(stacks[0], smallest, len[0]);
		// s_index = find_ind_min(stacks[0], n);
		printf("smallest is %d at pos %d\n", smallest, s_index);
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
	int	largest;
	int	s_index;
	int i;
	int j;
	int	moved;

	i = 0;
	j = 0;
	moved = 0;
	while(i++ < n - 3)
	{
		largest = find_largest(stacks[1], len[1]);
		print_stack(stacks[1], len, 'b');
		s_index = find_ind_max(stacks[1], n);
		printf("largest is %d at pos %d\n", largest, s_index);
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
	printf("sorting a\n");
	printf("[sort small a]: %d, len[0] = %d\n", n, len[0]);
	if (n > 3)
		moved = mv_smallest_frm_a(stacks, len, n);
	print_stack(stacks[0], len, 'a');
	sort_stack(stacks[0], len, n);
	printf("moved is %d\n", moved);
	if (len[0] < n && moved > 0)
		move_back_a(stacks, len, n);
	else if (moved > 0)
		move_back_a(stacks, len, moved);
	printf("after small sort\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
}

void	sort_small_b(int **stacks, int *len, int n)
{
	int i;
	int	moved;

	i = 0;
	moved = 0;
	printf("sorting small b (n= %d)\n", n);
	if (n == 0)
		return ;
	if (n > 3)
	{
		moved = mv_largest_frm_b(stacks, len, n);
		n -= moved;
	}
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	sort_stack_b(stacks[1], len, n);
	print_stack(stacks[1], len, 'b');
	printf("n after mv largest frm b: %d\n", n );
	while (i++ < n)
		pusha(stacks[0], stacks[1], len);
	printf("after small sort\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
}

int	*sort_a_base(int **stacks, int *len, int *sml_bg, int *counts)
{
	// pushes the top n into the respective parts of the stacks
	if (stacks[0][0] >= sml_bg[1])
	{
		// printf("sort_a_base: largest stack\n");
		rotate(stacks[0], len, 'a');
		counts[2]++;
	}
	else if (stacks[0][0] >= sml_bg[0])
	{
		// printf("sort_a_base: middle stack\n");
		pushb(stacks[1], stacks[0], len);
		counts[1]++;
	}
	else
	{
		// printf("sort_a_base: smallest stack\n");
		pushb(stacks[1], stacks[0], len);
		rotate(stacks[1], len, 'b');
		counts[0]++;
	}
	return (counts);
}

void	sort_a_top(int **stacks, int *len, int n, int iter)
{
	int i;
	int	*count_tmp;
	int	*sml_bg_tmp;

	iter++;
	printf("[sort_a_top] iter = %d\n", iter);
	i = 0;
	printf("sort a top\n");
	count_tmp = (int *)malloc(3 * sizeof(int));
	sml_bg_tmp = (int *)malloc(2 * sizeof(int));
	if (!count_tmp || ! sml_bg_tmp)
		return ;
	if (n <= 5)
		sort_small_a(stacks, len, n);
	else
	{
		printf("n = %d\n", n);
		print_stack(stacks[0], len, 'a');
		find_mids_a(stacks[0], n, sml_bg_tmp);
		printf("n = %d\n", n);
		printf("pivots:%d & %d\n", sml_bg_tmp[0], sml_bg_tmp[1]);
		if (!is_sorted(stacks[0], n))
			while (i++ < n)
				count_tmp = sort_a_base(stacks, len, sml_bg_tmp, count_tmp);
		printf("after sorting a base in sort_a_top\n");
		print_stack(stacks[0], len, 'a');
		print_stack(stacks[1], len, 'b');
		if (count_tmp[2] > 0)
			sort_a_btm(stacks, len, count_tmp[2], iter);
		if (count_tmp[1] > 0)
			sort_b_top(stacks, len, count_tmp[1], iter);
		if (count_tmp[0] > 0)
			sort_b_btm(stacks, len, count_tmp[0], iter);
	}
	free(sml_bg_tmp);
	free (count_tmp);
}

void	sort_a_btm(int **stacks, int *len, int n, int iter)
{
	int i;
	int	*count_tmp;
	int	*sml_bg_tmp;

	iter++;
	printf("[sort_a_btm] iter = %d\n", iter);
	i = 0;
	printf("sort a btm\n");
	count_tmp = (int *)malloc(3 * sizeof(int));
	sml_bg_tmp = (int *)malloc(2 * sizeof(int));
	find_mids_a(stacks[0], n, sml_bg_tmp);
	printf("n = %d\n", n);
	printf("[sort_a_btm] pivots: %d %d\n", sml_bg_tmp[0], sml_bg_tmp[1]);
	if (!count_tmp || !sml_bg_tmp)
		return ;
	i = 0;
	if (len[0] > n) // if the len of the array is less than the size of the substack.
		while (i++ < n)
			rev_rot(stacks[0], len, 'a');
	if (n <= 5)
		sort_small_a(stacks, len, n);
	else
		{
			find_mids_a(stacks[0], n, sml_bg_tmp);
			if (!is_sorted(stacks[0], n))
				while (i++ < n)
					count_tmp = sort_a_base(stacks, len, sml_bg_tmp, count_tmp);
			printf("after sorting a base in sort_a_btm\n");
			print_stack(stacks[0], len, 'a');
			print_stack(stacks[1], len, 'b');
			if (count_tmp[2] > 0 && len[0] > count_tmp[2])
				sort_a_btm(stacks, len, count_tmp[2], iter);		
			if (count_tmp[1] > 0)
				sort_b_top(stacks, len, count_tmp[1], iter);
			if (count_tmp[0] > 0)
				sort_b_top(stacks, len, count_tmp[0], iter);
		}
	free(sml_bg_tmp);
	free (count_tmp);
}

int	*sort_b_base(int **stacks, int *len, int *sml_bg, int *counts)
{
	// This pushses the top of b into the respective parts of the stack.
	printf("start sorting b top logic\n");
	printf("smlbg: [%d %d]\n", sml_bg[0], sml_bg[1]);
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


void sort_b_btm(int **stacks, int *len, int n, int iter)
{
	int i;
	int *count_tmp;
	int	*sml_bg_tmp;

	iter++;
	printf("[sort_b_btm] iter = %d\n", iter);
	i = 0;
	count_tmp = malloc (3 * sizeof(int));
	sml_bg_tmp = (int *) malloc(2 * sizeof(int));
	if (!count_tmp || !sml_bg_tmp)
		return ;
	sml_bg_tmp[0] = 0;
	while (i++ < n)
		rev_rot(stacks[1], len, 'b');
	if (n <= 5)
	{
		printf("sorting small b\n");
		sort_small_b(stacks, len, n);
		// i = 0;
		// while (i++ < 3)
		// 	pusha(stacks[0], stacks[1], len);
	}
	else
	{
		find_mids_b(stacks[1], n, sml_bg_tmp);
		printf("[sort_b_btm] pivots: %d %d\n", sml_bg_tmp[0], sml_bg_tmp[1]);
		i = 0;
		if (!is_rev_sorted(stacks[1], n))
			while (i++ < n)
				count_tmp = sort_b_base(stacks, len, sml_bg_tmp, count_tmp);
		printf("n = %d\n", n);
		printf("after sorting a base in sort_b_btm\n");
		print_stack(stacks[0], len, 'a');
		print_stack(stacks[1], len, 'b');
		if (count_tmp[2] > 0)
			sort_a_top(stacks, len, count_tmp[2], iter);
		if (count_tmp[1] > 0)
			sort_a_btm(stacks, len, count_tmp[1], iter);
		if (count_tmp[0] > 0)
			sort_b_btm(stacks, len, count_tmp[0], iter);
	}
	free(sml_bg_tmp);
	free(count_tmp);
}

void	sort_b_top(int **stacks, int *len, int n, int iter)
{
	int i;
	int *count_tmp;
	int *sml_bg_tmp;

	iter++;
	printf("[sort_b_top] iter = %d\n", iter);
	count_tmp = (int *)malloc(3 * sizeof(int));
	sml_bg_tmp = (int *)malloc(2 * sizeof(int));
	if (!count_tmp || !sml_bg_tmp)
		return ;
	if (n <= 5)
		sort_small_b(stacks, len, n);
	else
	{
		i = 0;
		find_mids_b(stacks[1], n, sml_bg_tmp);
		printf("[sort_b_top] pivots: %d %d\n", sml_bg_tmp[0], sml_bg_tmp[1]);
		if (!is_sorted(stacks[1], n))
			while (i++ < n)
				count_tmp = sort_b_base(stacks, len, sml_bg_tmp, count_tmp);
		printf("after sorting a base in sort_b_top\n");
		printf("n = %d\n", n);
		print_stack(stacks[0], len, 'a');
		print_stack(stacks[1], len, 'b');
		sort_a_top(stacks, len, count_tmp[2], iter);
		sort_a_btm(stacks, len, count_tmp[1], iter);
		sort_b_btm(stacks, len, count_tmp[0], iter);
	}
	free(sml_bg_tmp);
	free(count_tmp);
}

void	ft_sort_b(int **stacks, int *len, int *counts, int iter)
{
	iter++;
	printf("[ft_sort_b] iter = %d, counts[0] = %d, counts[1] = %d, counts[2] = %d, len[0] = %d, len[1] = %d\n", iter, counts[0], counts[1], counts[2], len[0], len[1]);
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	// TODO: add len check adn use sort_a_top if len of a = counts[2]
	sort_a_btm(stacks, len, counts[2], iter);
	// ft_sort_a(stacks, len, count_next, iter);
	sort_b_top(stacks, len, counts[1], iter);
	// ft_sort_a(stacks, len, count_next, iter);
	sort_b_btm(stacks, len, counts[0], iter);
	
	printf("end of ft sort b\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
}

int	**set_psrt_count(int len)
{
	int i;
	int	iter_count;
	int	**counts_psrt;

	i = 0;
	printf("start set psrt count\n");
	iter_count = (log10(len) / log10(3)) + 2;
	printf("iter_count = %d\n", iter_count);
	counts_psrt = malloc((iter_count + 1) * sizeof(int *));
	if (!counts_psrt)
		return (NULL);
	while (i++ <= iter_count)
		counts_psrt[i] = NULL;
	printf("presort count malloced sucessfully till %d\n", i);
	counts_psrt[0] = malloc(1 * sizeof(int));
	if (!counts_psrt[0])
	{
		free (counts_psrt);
		return (NULL);
	}
	i = 1;
	while (i < iter_count)
	{
		counts_psrt[i] = malloc(3 * sizeof(int));
		if (!counts_psrt[i])
		{
			printf("failed to create counts_psrt[%d]\n", i);
			free_entire_array(counts_psrt, i);
			break;
		}
		i++;
	}
	printf("setting counts psrt\n");
	counts_psrt[0][0] = iter_count;
	printf("counts_psrt[0][0] = %d\n", counts_psrt[0][0]);
	return (counts_psrt);
}

int	**presort_stack(int **stacks, int *len, int n, int iter)
{
	int	j;
	int	*sml_bg;
	int	i;
	int	len_tmp;
	int	**counts_psrt;

	iter++;
	printf("starting presort\n");
	j = 1;
	// counts_psrt = malloc(((log10(*len) / log10(3)) + 3) * sizeof(int *));
	counts_psrt = set_psrt_count(*len);
	sml_bg = (int *)malloc(2 * sizeof(int)); 
	printf("malloced sml_bg\n");
	printf("len = %d\n", *len);
	if (!counts_psrt || !sml_bg)
	{
		free_entire_array(counts_psrt, counts_psrt[0][0]);
		free(sml_bg);
		return (NULL);
	}
	printf("[presort_stack] iter = %d, n = %d, len[0] = %d, len[1] = %d\n", iter, n, len[0], len[1]);

	printf("counts_psrt[0][0] = %d\n", counts_psrt[0][0]);
	if (n <= 5)
	{
		sort_small_a(stacks, len, n);
		free(sml_bg);
		return (0);
	}
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	
	// Process all elements in the current stack
	// sort_a_top(stacks, len, n, iter);
	while (len[0] > 7)
	{
		find_mids_a(stacks[0], len[0], sml_bg);
		printf("presort stack: sml_bg[0] = %d, sml_bg[1] = %d\n", sml_bg[0], sml_bg[1]);
		i = 0;
		len_tmp = len[0];
		while (i++ < counts_psrt[0][0] - 1)
		{
			counts_psrt[j][0] = 0;
			counts_psrt[j][1] = 0;
			counts_psrt[j][2] = 0;
		}
		i = 0;
		while (i++ < len_tmp)
			counts_psrt[j] = sort_a_base(stacks, len, sml_bg, &counts_psrt[j][0]);
		j++;
	}
	sort_small_a(stacks, len, len[0]);
	printf("after presorting logic\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	
	// Sort remaining elements in stack A if any
	// printf("calling sort b\n");
	// ft_sort_b(stacks, len, counts, iter);

	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	printf("ending presort\n");
	free(sml_bg);
	return (counts_psrt);
}

void	sort_back(int **stacks, int *len, int **counts, int *iter)
{
	// int	n_substacks;
	int	i;

	i = counts[0][0] - 1;
	printf("n_substacks = %d\n", i);
	while (i > 0)
	{
		ft_sort_b(stacks, len, counts[i], *iter);
		i--;
	}
}
