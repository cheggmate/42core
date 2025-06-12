/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 20:47:16 by jotong            #+#    #+#             */
/*   Updated: 2025/06/12 21:10:42 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "globals.h"			// remove before submitting

int	is_sorted(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (!(stack[i] < stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
