/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:26:36 by jotong            #+#    #+#             */
/*   Updated: 2025/07/06 15:45:29 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_second_largest(int *stack, int len)
{
	int	largest;
	int	second;
	int	i;

	if (len < 2)
		return (-1);
	largest = INT_MIN;
	second = INT_MIN;
	i = 0;
	while (i < len)
	{
		if (largest < stack[i])
		{
			if (second < largest)
				second = largest;
			largest = stack[i];
		}
		else if (second < stack[i] && stack[i] != largest)
			second = stack[i];
		i++;
	}
	return (second);
}
