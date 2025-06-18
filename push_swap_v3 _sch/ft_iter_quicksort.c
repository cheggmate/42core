/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_quicksort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:30:31 by jotong            #+#    #+#             */
/*   Updated: 2025/06/19 01:15:31 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_btoa(int **stacks, int *len, int *sml_bg, t_list_split *curr)
{
	int	count;

	count = sml_bg[1] - sml_bg[0] + 1;
	while (count-- > 0)							// adapt this part to push numbers back in reverse order if count < 6. else sort like in 2b.
		pusha(stacks[1], stacks[0], len);
	count = sml_bg[3] - sml_bg[1] + 1;
	while (count-- > 0)							// adapt this part to push numbers back in reverse order if count < 6. else sort like in 2b.
	{
		rev_rot(stacks[1], len, 'b');
		pusha(stacks[1], stacks[0], len);
	}
	if (sml_bg[3] - sml_bg[1] + 1 < 6)
		sort_stack(stacks[0], stacks[1], len, 2);
	else
	{
		
	}

	// sort from top of b back to a

	// rotate up from bottom of b, then push sorted back to a.
}

static void sort_atob(int **stacks, int *len, int *sml_bg, t_list_split *curr)
{
	while (len[0] > 6)
	{
		find_mids(stacks[0], len[0], sml_bg);
		sml_bg[2] = find_smallest(stacks[0], len[0]);
		sml_bg[3] = find_largest(stacks[0], len[0]);
		if (sml_bg[1] > sml_bg[3] - 5)
			sml_bg[1] = sml_bg[3] - 5;
		create_list_split(sml_bg, lsts);
		while (len[0] > sml_bg[3] - sml_bg[1] + 1)
		{
			if (stacks[0][0] >= sml_bg[1])
				rotate(stacks[0], len, 'a');
			else
			{
				pushb(stacks[1], stacks[0], len);
				if (stacks[0][0] <= sml_bg[0])
					rotate(stacks[1], len, 'b');
			} 
			print_stack(stacks[0], len, 'a');					// remove before submission.
			print_stack(stacks[1], len, 'b');					// remove before submission.
		}
	}
}

static void	first_iter(int **stacks, int *len, t_list_split **lsts, int *sml_bg)
{
	while (len[0] > 6)
	{
		find_mids(stacks[0], len[0], sml_bg);
		sml_bg[2] = find_smallest(stacks[0], len[0]);
		sml_bg[3] = find_largest(stacks[0], len[0]);
		if (sml_bg[1] > sml_bg[3] - 5)
			sml_bg[1] = sml_bg[3] - 5;
		create_list_split(sml_bg, lsts);
		while (len[0] > sml_bg[3] - sml_bg[1] + 1)
		{
			if (stacks[0][0] >= sml_bg[1])
				rotate(stacks[0], len, 'a');
			else
			{
				pushb(stacks[1], stacks[0], len);
				if (stacks[0][0] <= sml_bg[0])
					rotate(stacks[1], len, 'b');
			} 
			print_stack(stacks[0], len, 'a');					// remove before submission.
			print_stack(stacks[1], len, 'b');					// remove before submission.
		}
	}
}

void	iter_quicksort(int *stack, int *stack_b, int *len)
{
	t_list_split	*lsts[2];
	int				*stacks[2];
	int				sml_bg[4];
	int				*copy;
	t_list_split	*curr;

	copy = malloc(len[0] * sizeof(int));
	if (copy)
	{
		lsts[0] = NULL;
		lsts[1] = NULL;
		stacks[1] = stack_b;
		sml_bg[0] = 0;
		sml_bg[1] = 0;
		replace_with_rank(stack, len[0], copy);
		stacks[0] = copy;
		first_iter(stacks, len, lsts, sml_bg);
		sort_stack(stacks[0], stacks[1], len, 2);
		while (ft_lstsize_split(lsts[0]) > 1)
		{
			curr = ft_lstlast_splt(lsts[0]);
			while (is_in_range(stacks[1], len[1], curr))
			{
				calc_mids(curr, sml_bg);
				sort_btoa(stacks, len, sml_bg, curr);
				sort_atob(stacks, len, sml_bg, curr);
			}
			free(curr);
			curr = NULL;
		}
		printf("after sorting\n");
		print_stack(stacks[0], len, 'a');					// remove before submission.
		print_stack(stacks[1], len, 'b');					// remove before submission.
		// sort_back();
		free(copy);
		ft_lstclear_splt(lsts);
	}
}

