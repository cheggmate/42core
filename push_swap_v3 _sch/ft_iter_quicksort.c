/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_quicksort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:30:31 by jotong            #+#    #+#             */
/*   Updated: 2025/06/18 01:15:02 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	first_iter(int **stacks, int *len, t_list_split **lsts, int *sml_bg)
{
	int	iter;
	int	largest;

	iter = 0;
	while (len[0] > 6)
	{
		find_mids(stacks[0], len[0], sml_bg);
		printf("smlr = %d\n", sml_bg[0]);				// remove before submission.
		printf("bgr = %d\n", sml_bg[1]);					// remove before submission.
		largest = find_largest(stacks[0], len[0]);
		if (iter == 0)
			lsts[0] = ft_lstnew_splt(0, len[0]);
		else
		{
			lsts[1] = ft_lstnew_splt(find_smallest(stacks[0], len[0]), largest);
			ft_lstadd_back_splt(&lsts[0], lsts[1]);
		}
		print_stack(stacks[0], len, 'a');					// remove before submission.
		print_stack(stacks[1], len, 'b');					// remove before submission.
		while (len[0] > largest - sml_bg[1] + 2 && len[0] > 6)
		{
			printf("stack[0][0] = %d, sml_bg[0] = %d, sml_bg[1] = %d\n", stacks[0][0], sml_bg[0], sml_bg[1]);
			if (stacks[0][0] >= sml_bg[1])
				rotate(stacks[0], len, 'a');
			else if (stacks[0][0] >= sml_bg[0])
				pushb(stacks[1], stacks[0], len);
			else
			{
				pushb(stacks[1], stacks[0], len);
				rotate(stacks[1], len, 'b');
			}
			print_stack(stacks[0], len, 'a');					// remove before submission.
			print_stack(stacks[1], len, 'b');					// remove before submission.
		}
		iter++;
	}
}

void	iter_quicksort(int *stack, int *stack_b, int *len)
{
	t_list_split	*lsts[2];
	int				*stacks[2];
	int				sml_bg[2];
	int				*copy;

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
		sort_stack(stacks[0], stacks[1], len);
		printf("after sorting\n");
		print_stack(stacks[0], len, 'a');					// remove before submission.
		print_stack(stacks[1], len, 'b');					// remove before submission.
		free(copy);
		ft_lstclear_splt(lsts);
	}
}

