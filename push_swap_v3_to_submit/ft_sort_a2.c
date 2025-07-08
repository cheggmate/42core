/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:07:27 by jotong            #+#    #+#             */
/*   Updated: 2025/07/08 13:33:25 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	put_smallest(t_stack *stack, t_list_ops *curr)
{
	int	smallest;
	int	i;

	i = 0;
	smallest = find_ind_min(stack->stack_a, stack->len_a);
	if (smallest <= stack->len_a / 2)
	{
		while (i++ < smallest)
			rotate(stack->stack_a, stack->len_a, curr, 'a');
		pushb(stack, curr);
	}
	else
	{
		while (i++ < (stack->len_a - smallest))
			rev_rot(stack->stack_a, stack->len_a, curr, 'a');
		pushb(stack, curr);
	}
}

static void	sort_three(t_stack *stack, t_list_ops *curr)
{
	int	largest;

	largest = find_ind_max(stack->stack_a, stack->len_a);
	if (largest == 0)
		rotate(stack->stack_a, stack->len_a, curr, 'a');
	else if (largest == 1)
		rev_rot(stack->stack_a, stack->len_a, curr, 'a');
	if (stack->stack_a[0] > stack->stack_a[1])
		swap(stack, curr, 'a');
}

static void	sort_five(t_stack *stack, t_list_ops *curr)
{
	int	i;

	i = 0;
	while (stack->len_a >= 4)
	{
		put_smallest(stack, curr);
		i++;
	}
	sort_three(stack, curr);
	while (i--)
		pusha(stack, curr);
}

void	sort_small_a_presort(t_stack *stack, t_list_ops *curr, int n)
{
	if (is_sorted(stack->stack_a, stack->len_a))
		return ;
	if (n <= 1)
		return ;
	else if (n <= 3)
		sort_three(stack, curr);
	else
	{
		if (!is_sorted(stack->stack_a, stack->len_a))
			sort_five(stack, curr);
	}
}
