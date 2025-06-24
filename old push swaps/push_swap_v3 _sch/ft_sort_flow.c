/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:06:30 by jotong            #+#    #+#             */
/*   Updated: 2025/06/22 15:37:08 by jotong           ###   ########.fr       */
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

static void	sort_a_base(int **stacks, int *len, int *sml_bg, int *counts)
{
	// pushes the top n into the respective parts of the stacks
	if (stacks[0][0] < sml_bg[0])
	{
		// printf("smallest stack\n");
		pushb(stacks[1], stacks[0], len);
		rotate(stacks[1], len, 'b');
		counts[0]++;
	}
	else if (stacks[0][0] <= sml_bg[1])
	{
		// printf("middle stack\n");
		pushb(stacks[1], stacks[0], len);
		counts[1]++;
	}
	else
	{
		// printf("largest stack\n");
		rotate(stacks[0], len, 'a');
		counts[2]++;
	}
}

static int	*sort_a_top(int **stacks, int *len, int n)
{
	int i;
	int	*count_tmp;
	int	*sml_bg_tmp;

	i = 0;
	count_tmp = (int *)malloc(3 * sizeof(int));
	sml_bg_tmp = (int *)malloc(2 * sizeof(int));
	if (!count_tmp || ! sml_bg_tmp)
		return (NULL);
	if (n <= 5)
		sort_small_a(stacks, len, n);
	else
	{
		printf("n = %d\n", n);
		find_mids_a(stacks[0], n, sml_bg_tmp);
		printf("pivots:%d & %d\n", sml_bg_tmp[0], sml_bg_tmp[1]);
		while (i++ < n)
			sort_a_base(stacks, len, sml_bg_tmp, count_tmp);
	}
	free(sml_bg_tmp);
	return (count_tmp);
}

static int *sort_a_btm(int **stacks, int *len, int n)
{
	int i;
	int	*count_tmp;
	int	*sml_bg_tmp;

	i = 0;
	count_tmp = (int *)malloc(3 * sizeof(int));
	sml_bg_tmp = (int *)malloc(2 * sizeof(int));
	find_mids_a(stacks[0], n, sml_bg_tmp);
	if (!count_tmp || !sml_bg_tmp)
		return (NULL);
	i = 0;
	while (i++ < n)
		rev_rot(stacks[0], len, 'a');
	if (n <= 3)
		sort_small_b(stacks, len, n);
	else
		{
			find_mids_a(stacks[0], n, sml_bg_tmp);
			while (i++ < n)
				sort_a_base(stacks, len, sml_bg_tmp, count_tmp);
		}
	free(sml_bg_tmp);
	return (count_tmp);
}

// void	move_back_b(int **stacks, int *len, int n)
// {
// 	while (len[1] < n)
// 		pushb(stacks[1], stacks[0], len);
// }

static void	sort_b_base(int **stacks, int *len, int *sml_bg, int *counts)
{
	// This pushses the top of b into the respective parts of the stack.
	printf("start sorting b top logic\n");
	printf("smlbg: [%d %d]\n", sml_bg[0], sml_bg[1]);
	if (stacks[1][0] > sml_bg[1])
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

static int	*sort_b_top(int **stacks, int *len, int n)
{
	int i;
	int *count_tmp;
	int *sml_bg_tmp;

	count_tmp = (int *)malloc(3 * sizeof(int));
	sml_bg_tmp = (int *)malloc(2 * sizeof(int));
	count_tmp = NULL;
	if (!count_tmp || sml_bg_tmp)
		return (NULL);
	if (n <= 5)
		sort_small_b(stacks, len, n);
	else
	{
		i = 0;
		find_mids_b(stacks[1], len[1], sml_bg_tmp);
		while (i++ < n)
			sort_b_base(stacks, len, sml_bg_tmp, count_tmp);
	}
	free(sml_bg_tmp);
	return(count_tmp);
}

static int *sort_b_btm(int **stacks, int *len, int n)
{
	int i;
	int *count_tmp;
	int	*sml_bg_tmp;

	i = 0;
	count_tmp = (int *)(3 * sizeof(int));
	sml_bg_tmp = (int *)malloc(2 * sizeof(int));
	count_tmp = NULL;
	if (!count_tmp || !sml_bg_tmp)
		return (NULL);
	sml_bg_tmp[0] = 0;
	while (i++ <n)
		rev_rot(stacks[1], len, 'b');
	if (n < 5)
		sort_small_b(stacks, len, n);
	else
	{
		find_mids_b(stacks[1], n, sml_bg_tmp);
		while (i++ < n)
			sort_b_base(stacks, len, sml_bg_tmp, count_tmp);
	}
	free(sml_bg_tmp);
	return(count_tmp);
}

void	ft_sort_a(int **stacks, int *len, int *counts, int iter)
{
	int	*count_next;

	iter++;
	count_next = (int *)malloc(3 * sizeof(int));
	printf("[ft_sort_a] iter = %d, counts[0]= %d, counts[1]= %d, counts[2]= %d, len[0] = %d, len[1] = %d\n", iter, counts[0], counts[1], counts[2], len[0], len[1]);
	if (counts[2] <= 5)
		return(sort_small_a(stacks, len, counts[2]));
	printf("before if condition/sending to ft sort a\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	
	// Process all elements in the current subtacks
	if (counts[2] > 0)
	{
		count_next = sort_a_top(stacks, len, counts[2]);
		ft_sort_b(stacks, len, count_next, iter);
	}
	if(counts[1] > 0)
	{
		count_next = sort_a_btm(stacks, len, counts[1]);
		ft_sort_b(stacks, len, count_next, iter);
	}
	if (counts[0] > 0)
	{
		count_next = sort_b_btm(stacks, len, counts[0]);
		ft_sort_b(stacks, len, count_next, iter);
	}
	free(count_next);
	
	// // Sort remaining elements in stack A if any
	// if (len[0] > 0)
	// {
	// 	if (len[0] <= 5)
	// 		sort_small_a(stacks, len, len[0]);
	// 	else if (len[0] > 0)
	// 		ft_sort_a(stacks, len, sml_bg, len[0], iter);
	// }
	
	// // Sort elements in stack B
	// // Push back middle elements first
	// printf("[ft_sort_a] Handling counts[1]=%d, len[1]=%d\n", counts[1], len[1]);
	// if (counts[1] <= 3)
	// {
	// 	sort_small_b(stacks, len, counts[1]);
	// 	printf("after sort b top\n");
	// 	print_stack(stacks[0], len, 'a');
	// 	print_stack(stacks[1], len, 'b');
	// 	// sort_stack_b(stacks[1], len, counts[1]);
	// 	i = 0;
	// 	// while (i++ < counts[1] && len[1] > 0)
	// 	// {
	// 	// 	printf("[ft_sort_a] pusha (counts[0]), len[1]=%d\n", len[1]);
	// 	// 	pusha(stacks[0], stacks[1], len);
	// 	// }
	// }
	// else if (counts[1] > 0 && len[1] >= counts[1])
	// {
	// 	printf("[ft_sort_a] recursive ft_sort_b (counts[1]=%d, len[1]=%d)\n", counts[1], len[1]);
	// 	find_mids_b(stacks[1], counts[1], sml_bg);
	// 	i = 0;
	// 	while (i++ < counts[1])
	// 		sort_b_top(stacks, len, sml_bg, counts);
	// }
	// print_stack(stacks[0], len, 'a');
	// print_stack(stacks[1], len, 'b');
	
	// // Push back smallest elements
	// if (counts[0] > 0)
	// {
	// 	printf("[ft_sort_a] Handling counts[0]=%d, len[1]=%d\n", counts[0], len[1]);
	// 	if (counts[0] <= 3)
	// 	{
	// 		i = 0;
	// 		while (i++ < counts[0])
	// 			rev_rot(stacks[1], len, 'b');
	// 		sort_small_b(stacks, len, counts[1]);
	// 	}
	// 	else if (counts[0] > 0 && len[1] >= counts[0])
	// 	{
	// 		printf("[ft_sort_a] recursive ft_sort_b (counts[0]=%d, len[1]=%d)\n", counts[0], len[1]);
	// 		sort_b_btm(stacks, len, counts);
	// 	}
	// 	print_stack(stacks[0], len, 'a');
	// 	print_stack(stacks[1], len, 'b');
	// }
		
	// 	// Push back largest elements last
	// 	if (counts[2] > 0)
	// 	{
	// 		printf("[ft_sort_a] Handling counts[2]=%d, len[1]=%d\n", counts[2], len[1]);
	// 		if (counts[2] <= 3)
	// 		{
	// 			sort_stack_b(stacks[1], len, counts[2]);
	// 			i = 0;
	// 			while (i++ < counts[2] && len[1] > 0)
	// 			{
	// 				printf("[ft_sort_a] pusha (counts[2]), len[1]=%d\n", len[1]);
	// 				pusha(stacks[0], stacks[1], len);
	// 			}
	// 		}
	// 		else if (counts[2] > 0 && len[1] >= counts[2])
	// 		{
	// 			printf("[ft_sort_a] recursive ft_sort_b (counts[2]=%d, len[1]=%d)\n", counts[2], len[1]);
	// 			ft_sort_b(stacks, len, sml_bg, counts[2], iter);
	// 		}
	// 	}
	
	// printf("n = %d, counts[0] = %d, counts[1] = %d, counts[2] = %d\n", n, counts[0], counts[1], counts[2]);
	printf("before exiting ft_sort_a\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
}

void	ft_sort_b(int **stacks, int *len, int *counts, int iter)
{
	int	*count_next;
	// int	counts[3];

	iter++;
	count_next = (int *)malloc(3 * sizeof (int));
	if (!count_next)
		return ;
	printf("[ft_sort_b] iter = %d, counts[0] = %d, counts[1] = %d, counts[2] = %d, len[0] = %d, len[1] = %d\n", iter, counts[0], counts[1], counts[2], len[0], len[1]);
	// counts[0] = 0; // bottom of stack b -- smallest third
	// counts[1] = 0; // bottom of stack a -- middle third
	// counts[2] = 0; // top of stack a -- largest third
	if (counts[2] > 0)
	{
		count_next = sort_a_btm(stacks, len, counts[2]);
		ft_sort_a(stacks, len, count_next, iter);
	}
	if (counts[1] > 0)
	{
		count_next = sort_b_top(stacks, len, counts[1]);
		ft_sort_a(stacks, len, count_next, iter);
	}
	if (counts[0] > 0)
	{
		count_next = sort_b_btm(stacks, len, counts[0]);
		ft_sort_a(stacks, len, count_next, iter);
	}
	
	// if (counts[1] <= 3)
	// {
	// 	// sort_stack_b(stacks[1], len, n);
	// 	// i = 0;
	// 	// while (i++ < n && len[1] > 0)
	// 	// {
	// 	// 	printf("[ft_sort_b] pusha (n<=3), len[1]=%d\n", len[1]);
	// 	// 	pusha(stacks[0], stacks[1], len);
	// 	// }
	// 	sort_small_b(stacks, len, counts[1]);
	// 	return ;
	// }

	// if (ciybts)
	// {
	// 	find_mids_b(stacks[1], counts[1], sml_bg);
	// 	sort_b_top(stacks, len, counts);
	// }
	// else if (stacks[1][0] < sml_bg[0])
	// {
	// 	i = 0;
	// 	while (i++ < counts[0])
	// 		rev_rot(stacks[1], len, 'b');
	// 	find_mids_b(stacks[1], counts[1], sml_bg);
	// }
		
	// // find_mids_b(stacks[1], counts[1], sml_bg);
	// // printf("sort b: sml_bg[0] = %d, sml_bg[1] = %d\n", sml_bg[0], sml_bg[1]);
	// i = 0;
	// if (len[1] >= 6)
	// 	while (i++ < n && len[1] > 0)
	// 		sort_b_top(stacks, len, counts);
	// printf("after sorting b logic\n");
	// print_stack(stacks[0], len, 'a');
	// print_stack(stacks[1], len, 'b');
	// printf("counts[0] = %d, counts[1] = %d, counts[2] = %d\n", counts[0], counts[1], counts[2]);
	
	// // Handle the smallest elements first (counts[0])
	// if (counts[0] > 0)
	// {
	// 	printf("[ft_sort_b] Handling counts[0]=%d, len[1]=%d\n", counts[0], len[1]);
	// 	if (counts[0] <= 3)
	// 	{
	// 		sort_stack_b(stacks[1], len, counts[0]);
	// 		i = 0;
	// 		while (i++ < counts[0] && len[1] > 0)
	// 		{
	// 			printf("[ft_sort_b] pusha (counts[0]), len[1]=%d\n", len[1]);
	// 			pusha(stacks[0], stacks[1], len);
	// 		}
	// 	}
	// 	else if (counts[0] > 0 && len[1] >= counts[0])
	// 	{
	// 		printf("[ft_sort_b] recursive ft_sort_b (counts[0]=%d, len[1]=%d)\n", counts[0], len[1]);
	// 		ft_sort_b(stacks, len, sml_bg, counts[0], iter);
	// 	}
	// }
	
	// // Handle the middle elements (counts[1])
	// if (counts[1] > 0)
	// {
	// 	printf("[ft_sort_b] Handling counts[1]=%d, len[1]=%d\n", counts[1], len[1]);
	// 	if (counts[1] <= 3)
	// 	{
	// 		sort_stack_b(stacks[1], len, counts[1]);
	// 		i = 0;
	// 		while (i++ < counts[1] && len[1] > 0)
	// 		{
	// 			printf("[ft_sort_b] pusha (counts[1]), len[1]=%d\n", len[1]);
	// 			pusha(stacks[0], stacks[1], len);
	// 		}
	// 	}
	// 	else if (counts[1] > 0 && len[1] >= counts[1])
	// 	{
	// 		printf("[ft_sort_b] recursive ft_sort_b (counts[1]=%d, len[1]=%d)\n", counts[1], len[1]);
	// 		ft_sort_b(stacks, len, sml_bg, counts[1], iter);
	// 	}
	// }
	
	// // Handle the largest elements last (counts[2])
	// if (counts[2] > 0)
	// {
	// 	printf("[ft_sort_b] Handling counts[2]=%d, len[1]=%d\n", counts[2], len[1]);
	// 	if (counts[2] <= 5)
	// 	{
	// 		printf("1. counts[2] <= 5, sorting stack b\n");
	// 		sort_stack_b(stacks[1], len, counts[2]);
	// 		i = 0;
	// 		while (i++ < counts[2] && len[1] > 0)
	// 		{
	// 			printf("[ft_sort_b] pusha (counts[2]), len[1]=%d\n", len[1]);
	// 			pusha(stacks[0], stacks[1], len);
	// 		}
	// 	}
	// 	else if (counts[2] > 0 && len[1] >= counts[2])
	// 	{
	// 		printf("[ft_sort_b] recursive ft_sort_b (counts[2]=%d, len[1]=%d)\n", counts[2], len[1]);
	// 		ft_sort_b(stacks, len, sml_bg, counts[2], iter);
	// 	}
	// }
	// if ()
	printf("end of ft sort b\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
}


int	*presort_stack(int **stacks, int *len, int n, int iter)
{
	int i;
	int	*counts;
	int	*sml_bg;

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
		return (NULL);
	}
	find_mids_a(stacks[0], n, sml_bg);
	printf("sort a: sml_bg[0] = %d, sml_bg[1] = %d\n", sml_bg[0], sml_bg[1]);
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	printf("before if condition/sending to ft sort a\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	
	// Process all elements in the current stack
	i = 0;
	while (i++ < n && len[0] > 0)
	{
		printf("(i = %d) sorting a top\n", i);
		counts = sort_a_top(stacks, len, n);
	}
	
	printf("after sort a logic\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	
	// Sort remaining elements in stack A if any
	if (len[0] > 6)
	{
		if (len[0] <= 5)
			sort_small_a(stacks, len, len[0]);
		else if (len[0] > 0)
		{
			printf("calling sort a\n");
			ft_sort_a(stacks, len, counts, iter);
		}
	}
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	printf("ending presort\n");
	return (counts);
}
