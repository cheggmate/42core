/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:39:44 by jotong            #+#    #+#             */
/*   Updated: 2025/07/01 21:45:34 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_order(int len, int *stack)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_dups(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->len_a)
	{
		j = 0;
		while (j < stack->len_a)
		{
			if (stack->stack_a[j] == stack->stack_a[i] && i != j)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}
