/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:06:30 by jotong            #+#    #+#             */
/*   Updated: 2025/06/23 01:06:28 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	mv_smallest_frm_a(int **stacks, int *len)
{
	int	smallest;
	int	s_index;
	while(len[0] > 3)
	{
		smallest = find_smallest(stacks[0], len[0]);
		s_index = find_pos(stacks[0], smallest, len[0]);
		while (s_index--)
			rotate(stacks[0], len, 'a');
		pushb(stacks[1], stacks[0], len);
	}
}

void	mv_largest_frm_b(int **stacks, int *len)
{
	int	largest;
	int	s_index;
	while(len[1] > 3)
	{
		largest = find_largest(stacks[1], len[1]);
		s_index = find_pos(stacks[1], largest, len[1]);
		while (s_index--)
			rotate(stacks[1], len, 'b');
		pusha(stacks[0], stacks[1], len);
	}
}

void	move_back_a(int **stacks, int *len, int n)
{
	while (len[0] < n)
		pusha(stacks[0], stacks[1], len);
}

void	sort_small_a(int **stacks, int *len, int n)
{
	printf("sorting a\n");
	if (n > 3)
		mv_smallest_frm_a(stacks, len);
	print_stack(stacks[0], len, 'a');
	sort_stack(stacks[0], len, n);
	if (len[0] < n)
		move_back_a(stacks, len, n);
	printf("after small sort\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
}

void	sort_small_b(int **stacks, int *len, int n)
{
	int i;

	i = 0;
	printf("sorting b (n= %d)\n", n);
	if (n > 3)
		mv_largest_frm_b(stacks, len);
	sort_stack_b(stacks[1], len, n);
	// if (len[1] < n)
	// 	move_back_b(stacks, len, n);
	while (i++ < 3)
		pusha(stacks[0], stacks[1], len);
	printf("after small sort\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
}

void	sort_a_base(int **stacks, int *len, int *sml_bg, int *counts)
{
	// pushes the top n into the respective parts of the stacks
	if (stacks[0][0] >= sml_bg[1])
	{
		printf("sort_a_base: largest stack\n");
		rotate(stacks[0], len, 'a');
		counts[2]++;
	}
	else if (stacks[0][0] >= sml_bg[0])
	{
		printf("sort_a_base: middle stack\n");
		pushb(stacks[1], stacks[0], len);
		counts[1]++;
	}
	else
	{
		printf("sort_a_base: smallest stack\n");
		pushb(stacks[1], stacks[0], len);
		rotate(stacks[1], len, 'b');
		counts[0]++;
	}
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
		printf("pivots:%d & %d\n", sml_bg_tmp[0], sml_bg_tmp[1]);
		while (i++ < n)
			sort_a_base(stacks, len, sml_bg_tmp, count_tmp);
		if (count_tmp[2] > 0)
			sort_a_btm(stacks, len, count_tmp[2], iter);
		if (count_tmp[1] > 0)
			sort_b_top(stacks, len, count_tmp[1], iter);
		if (count_tmp[0] > 0)
			sort_b_top(stacks, len, count_tmp[0], iter);
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
	if (!count_tmp || !sml_bg_tmp)
		return ;
	i = 0;
	if (len[0] > n) // if the len of the array is less than the size of the substack.
		while (i++ < n)
			rev_rot(stacks[0], len, 'a');
	if (n <= 5)
		sort_small_b(stacks, len, n);
	else
		{
			find_mids_a(stacks[0], n, sml_bg_tmp);
			while (i++ < n)
				sort_a_base(stacks, len, sml_bg_tmp, count_tmp);
			if (count_tmp[2] > 0)
				sort_a_btm(stacks, len, count_tmp[2], iter);
			if (count_tmp[1] > 0)
				sort_b_top(stacks, len, count_tmp[1], iter);
			if (count_tmp[0] > 0)
				sort_b_top(stacks, len, count_tmp[0], iter);
		}
	free(sml_bg_tmp);
	free (count_tmp);
}

void	sort_b_base(int **stacks, int *len, int *sml_bg, int *counts)
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
}


void sort_b_btm(int **stacks, int *len, int n, int iter)
{
	int i;
	int *count_tmp;
	int	*sml_bg_tmp;

	iter++;
	printf("[sort_b_btm] iter = %d\n", iter);
	i = 0;
	count_tmp = (int *)(3 * sizeof(int));
	sml_bg_tmp = (int *)malloc(2 * sizeof(int));
	if (!count_tmp || !sml_bg_tmp)
		return ;
	sml_bg_tmp[0] = 0;
	while (i++ <n)
		rev_rot(stacks[1], len, 'b');
	if (n <= 5)
		sort_small_b(stacks, len, n);
	else
	{
		find_mids_b(stacks[1], n, sml_bg_tmp);
		while (i++ < n)
			sort_b_base(stacks, len, sml_bg_tmp, count_tmp);
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
	count_tmp = NULL;
	if (!count_tmp || sml_bg_tmp)
		return ;
	if (n <= 5)
		sort_small_b(stacks, len, n);
	else
	{
		i = 0;
		find_mids_b(stacks[1], len[1], sml_bg_tmp);
		while (i++ < n)
			sort_b_base(stacks, len, sml_bg_tmp, count_tmp);
		if (count_tmp[2] > 0)
			sort_a_top(stacks, len, count_tmp[2], iter);
		if (count_tmp[1] > 0)
			sort_a_btm(stacks, len, count_tmp[1], iter);
		else if (count_tmp[0] > 0)
			sort_b_btm(stacks, len, count_tmp[0], iter);
	}
	free(sml_bg_tmp);
	free(count_tmp);
}

// void	ft_sort_a(int **stacks, int *len, int *counts, int iter)
// {
// 	int	*count_next;

// 	iter++;
// 	count_next = (int *)malloc(3 * sizeof(int));
// 	printf("[ft_sort_a] iter = %d, counts[0]= %d, counts[1]= %d, counts[2]= %d, len[0] = %d, len[1] = %d\n", iter, counts[0], counts[1], counts[2], len[0], len[1]);
// 	if (counts[2] <= 5)
// 		return(sort_small_a(stacks, len, counts[2]));
// 	printf("before if condition/sending to ft sort a\n");
// 	print_stack(stacks[0], len, 'a');
// 	print_stack(stacks[1], len, 'b');
	
// 	// Process all elements in the current subtacks
// 	if (counts[2] > 0)
// 	{
// 		count_next = sort_a_top(stacks, len, counts[2]);
// 		// ft_sort_b(stacks, len, count_next, iter);
// 	}
// 	if(counts[1] > 0)
// 	{
// 		count_next = sort_a_btm(stacks, len, counts[1]);
// 		// ft_sort_b(stacks, len, count_next, iter);
// 	}
// 	if (counts[0] > 0)
// 	{
// 		count_next = sort_b_btm(stacks, len, counts[0]);
// 		// ft_sort_b(stacks, len, count_next, iter);
// 	}
// 	free(count_next);
// 	printf("before exiting ft_sort_a\n");
// 	print_stack(stacks[0], len, 'a');
// 	print_stack(stacks[1], len, 'b');
// }

void	ft_sort_b(int **stacks, int *len, int *counts, int iter)
{
	iter++;
	printf("[ft_sort_b] iter = %d, counts[0] = %d, counts[1] = %d, counts[2] = %d, len[0] = %d, len[1] = %d\n", iter, counts[0], counts[1], counts[2], len[0], len[1]);
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	if (counts[2] > 0)
	{
		// TODO: add len check adn use sort_a_top if len of a = counts[2]
		sort_a_btm(stacks, len, counts[2], iter);
		// ft_sort_a(stacks, len, count_next, iter);
	}
	if (counts[1] > 0)
	{
		sort_b_top(stacks, len, counts[1], iter);
		// ft_sort_a(stacks, len, count_next, iter);
	}
	if (counts[0] > 0)
	{
		sort_b_btm(stacks, len, counts[0], iter);
	}
	printf("end of ft sort b\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
}

int	*presort_stack(int **stacks, int *len, int n, int iter)
{
	int	*counts;
	int	*sml_bg;
	int	i;
	int	len_tmp;

	iter++;
	printf("starting presort\n");
	counts = (int *)malloc(3 * sizeof(int));
	sml_bg = (int *)malloc(2 * sizeof(int));
	if (!counts || !sml_bg)
		return (NULL);
	printf("[ft_sort_a] iter = %d, n = %d, len[0] = %d, len[1] = %d\n", iter, n, len[0], len[1]);
	if (n <= 5)
	{
		sort_small_a(stacks, len, n);
		return (0);
	}
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	
	// Process all elements in the current stack
	// sort_a_top(stacks, len, n, iter);
	while (len[0] > 7)
	{
		find_mids_a(stacks[0], len[0], sml_bg);
		printf("sort a: sml_bg[0] = %d, sml_bg[1] = %d\n", sml_bg[0], sml_bg[1]);
		i = 0;
		len_tmp = len[0];
		while (i++ < len_tmp)
			sort_a_base(stacks, len, sml_bg, counts);
	}
	sort_small_a(stacks, len, len[0]);
	printf("after presorting logic\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	
	// Sort remaining elements in stack A if any
	printf("calling sort b\n");
	ft_sort_b(stacks, len, counts, iter);
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	printf("ending presort\n");
	free(sml_bg);
	return (counts);
}
