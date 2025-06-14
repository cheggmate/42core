/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:39:44 by jotong            #+#    #+#             */
/*   Updated: 2025/06/14 23:57:03 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "globals.h"			// remove before submission!

int	check_order(int len, int *stack)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		// printf("checking %d\n", i);
		// printf("stack[0] = %d\n", stack[0]);
		// printf("stack1 = %d\n", stack[1]);
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
