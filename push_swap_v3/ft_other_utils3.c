/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:10:03 by jotong            #+#    #+#             */
/*   Updated: 2025/06/29 18:02:31 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_ind_max(int *stack_b, int b_len)
{
	int	max;
	int	i;
	int	index;

	i = 0;
	index = 0;
	max = stack_b[0];
	while (i++ < b_len)
	{
		if (stack_b[i] > max)
		{
			max = stack_b[i];
			index = i;
		} 
	}
	return (index);
}

void	free_entire_array(int **counts_psrt, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (counts_psrt[j] != NULL)
			free(counts_psrt[j]);
		j++;
	}
	free(counts_psrt);
}

int	is_rev_sorted(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (!(stack[i] > stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	free_entire_str_array(char **str, int i)
{
	int index;

	index = 0;
	while (index <= i)
	{
		if (str[index] != NULL)
		{
			free(str[index]);
			index++;
		}
	}
	free(str);
}
