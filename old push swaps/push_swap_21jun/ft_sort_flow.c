/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:06:30 by jotong            #+#    #+#             */
/*   Updated: 2025/06/21 01:45:43 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_a_logic(int **stacks, int *len, int *sml_bg, int *counts)
{
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

void	move_smallest_a(int **stacks, int *len)
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

void	move_back_a(int **stacks, int *len, int n)
{
	while (len[0] < n)
		pusha(stacks[0], stacks[1], len);
}

void	ft_sort_a(int **stacks, int *len, int *sml_bg, int n, int iter)
{
	int i;
	int	counts[3];

	iter++;
	printf("iter = %d\n", iter);
	i = 0;
	if (n < 6)
	{
		if (n > 3)
			move_smallest_a(stacks, len);
		sort_stack(stacks[0], len, n);
		if (len[0] < n)
			move_back_a(stacks, len, n);
		printf("after small sort\n");
		print_stack(stacks[0], len, 'a');
		print_stack(stacks[1], len, 'b');
		return ;
	}
	find_mids(stacks[0], n, sml_bg);
	printf("sort a: sml_bg[0] = %d, sml_bg[1] = %d\n", sml_bg[0], sml_bg[1]);
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;

	if (len[0] >= 6)
		while (i++ < n)
			sort_a_logic(stacks, len, sml_bg, counts);
	else
		ft_sort_a(stacks, len, sml_bg, len[0], iter);
	printf("after sort a logic\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	i = 0;
	while (i++ < counts[1])
		rev_rot(stacks[0], len, 'a');
	if (counts[1] <= 3)
		sort_stack(stacks[0], len, counts[1]);
	// if (n - counts[0] - counts[1] > 0)
	// 	ft_sort_a(stacks, len, sml_bg, n - counts[0] - counts[1], iter);	// added this
	if (counts[1] > 3)
	{
		printf("before sort b\n");
		print_stack(stacks[0], len, 'a');
		print_stack(stacks[1], len, 'b');
		ft_sort_b(stacks, len, sml_bg, counts[1], iter);
		i = 0;
		while (i++ < counts[1])
			pusha(stacks[0], stacks[1], len);
	}
	i = 0;
	while (i++ < counts[0])
		rev_rot(stacks[1], len, 'b');
	if (counts[0] >= 6)
	{
		ft_sort_b(stacks, len, sml_bg, counts[0], iter);
		i = 0;
		while (i++ < counts[0])
			pusha(stacks[0], stacks[1], len);
	}
	printf("n = %d, counts[0] = %d, counts[1] = %d, counts[2] = %d\n", n, counts[0], counts[1], counts[2]);
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
}

static void	sort_b_logic(int **stacks, int *len, int *sml_bg, int *counts)
{
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

void	ft_sort_b(int **stacks, int *len, int *sml_bg, int n, int iter)
{
	int i;
	int	counts[3];

	iter++;
	printf("iter = %d\n", iter);
	printf("n = %d\n", n);
	if (n <= 3) 
	{
		sort_stack_b(stacks[1], len, n);
		i = 0;
		while (i++ < n)
			pusha(stacks[0], stacks[1], len);
		return ;
	}
	find_mids(stacks[1], n, sml_bg);
	printf("sort b: sml_bg[0] = %d, sml_bg[1] = %d\n", sml_bg[0], sml_bg[1]);
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	i = 0;
	if (len[1] >= 6)
		while (i++ < n)
			sort_b_logic(stacks, len, sml_bg, counts);
	printf("after sorting b logic\n");
	print_stack(stacks[0], len, 'a');
	print_stack(stacks[1], len, 'b');
	printf("counts[0] = %d, counts[1] = %d, counts[2] = %d\n", counts[0], counts[1], counts[2]);
	if (counts[2] <= 5)
		sort_stack_b(stacks[1], len, 'b');
	i = 0;
	while (i++ < counts[1])
		rev_rot(stacks[1], len, 'b');
	if (counts[0] > 0)
	{
		i = 0;
		while (i++ < counts[1])
			rev_rot(stacks[0], len, 'a');
		i = 0;
		while (i++ < counts[0])
			ft_sort_a(stacks, len, sml_bg, counts[0], iter);	// added this
	}

	if (counts[2] <= 5)
		sort_stack_b(stacks[1], len, n);
	else
		ft_sort_b(stacks, len, sml_bg, counts[2], iter);
	i = 0;
	// while (i++ < counts[1])
	// 	pusha(stacks[0], stacks[1], len);
}
