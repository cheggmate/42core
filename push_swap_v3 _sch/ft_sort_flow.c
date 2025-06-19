/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:06:30 by jotong            #+#    #+#             */
/*   Updated: 2025/06/20 00:56:44 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_a_logic(int **stacks, int *len, int *sml_bg, int *counts)
{
	if (stacks[0][0] < sml_bg[0])
	{
		pushb(stacks[0], stacks[1], len);
		rotate(stacks[1], len, 'b');
		counts[0]++;
	}
	else if (stacks[0][0] > sml_bg[1])
	{
		pushb(stacks[0], stacks[1], len);
		counts[2]++;
	}
	else
	{
		rotate(stacks[0], len, 'a');
		counts[1]++;
	}
}

void	ft_sort_a(int **stacks, int *len, int *sml_bg, int n)
{
	int i;
	int	counts[3];

	i = -1;
	if (n <= 3)
		sort_stack(stacks[0], stacks[1], len);
	else
	{
		printf("sort a\n");				// remove before submission
		find_mids(stacks[0], len[0], sml_bg);
		printf("sml_bg[0] = %d\n", sml_bg[0]);
		printf("sml_bg[1] = %d\n", sml_bg[1]);
		counts[0] = 0;
		counts[1] = 0;
		counts[2] = 0;
		while (i++ < n)
			sort_a_logic(stacks, len, sml_bg, counts);
		while (counts[1]--)
			rev_rot(stacks[0], len, 'a');
		ft_sort_b(stacks, len ,sml_bg, counts[2]);
		ft_sort_a(stacks, len, sml_bg, n - counts[0] - counts[2]);
		while (counts[0]--)
			rev_rot(stacks[1], len, 'b');
		ft_sort_b(stacks, len, sml_bg, counts[0]);
	}
}

static void	sort_b_logic(int **stacks, int *len, int *sml_bg, int *counts)
{
	if (stacks[1][0] > sml_bg[1])
	{
		pusha(stacks[0], stacks[1], len);
		rotate(stacks[0], len, 'a');
		counts[2]++;
	}
	else if (stacks[1][0] < sml_bg[0])
	{
		rotate(stacks[1], len, 'b');
		counts[0]++;
	}
	else
	{
		pusha(stacks[0], stacks[1], len);
		counts[1]++;
	}
}

void	ft_sort_b(int **stacks, int *len, int *sml_bg, int n)
{
	int i;
	int	counts[3];

	i = -1;
	// printf("start sort b\n");
	if (n <= 3)
		sort_stack(stacks[1], stacks[0], len);
	else
	{
		// printf("start find mids\n");
		print_stack(stacks[0], len, 'a');			// remove this before submission.
		find_mids(stacks[1], len[1], sml_bg);
		// printf("mids: %d\n", sml_bg[0]);
		counts[0] = 0;
		counts[1] = 0;
		counts[2] = 0;
		while (i++ < n)
			sort_b_logic(stacks, len, sml_bg, counts);
		// write(1, "done sorting by logic\n", 23);
		while (counts[1]--)
			rev_rot(stacks[0], len, 'a');
		ft_sort_a(stacks, len, sml_bg, counts[1] + counts[2]);
		ft_sort_b(stacks, len, sml_bg, counts[0]);
		while (counts[0]--)
			rev_rot(stacks[1], len, 'b');
	}
	
}
