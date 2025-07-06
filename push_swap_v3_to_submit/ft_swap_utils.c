/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:07:33 by jotong            #+#    #+#             */
/*   Updated: 2025/07/04 23:45:35 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	create_listops(t_list_ops *curr, int **swap, int ab)
{
	t_list_ops	*new;
	char		*ops;

	if (ab == 'a' || ab == 'x')
	{
		if (ab == 'a')
			ops = "sa\n";
	}
	else
	{
		if (ab == 'b')
			ops = "sb\n";
	}
	if (ab == 'a' || ab == 'b')
	{
		new = ft_lstnew_ops(ops, *swap[0]);
		if (new)
			ft_lstadd_back_ops(curr, new);
	}
}

void	swap(t_stack *stack, t_list_ops *curr, int ab)
{
	int	tmp;
	int	*swap[2];

	if (ab == 'a' || ab == 'x')
	{
		swap[0] = &stack->len_a;
		swap[1] = stack->stack_a;
	}
	else
	{
		swap[0] = &stack->len_b;
		swap[1] = stack->stack_b;
	}
	if (*swap[0] >= 2)
	{
		tmp = swap[1][0];
		swap[1][0] = swap[1][1];
		swap[1][1] = tmp;
		create_listops(curr, swap, ab);
	}
}

void	swap_both(t_stack *stack, t_list_ops *curr)
{
	t_list_ops	*new;

	swap(stack, curr, 'x');
	swap(stack, curr, 'y');
	new = ft_lstnew_ops("ss\n", stack->len_a);
	if (new)
		ft_lstadd_back_ops(curr, new);
}
