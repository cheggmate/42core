/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:37:28 by jotong            #+#    #+#             */
/*   Updated: 2025/06/10 09:28:52 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_stack(int	*s, int *len)			// remove this function before subm112ission.
{
	int		i;

	i = 0;
	printf("stack = ");
	while (i < *len)
	{
		printf("%d ", s[i]);
		i++;
	}
	printf("\n");
}

int	ft_arr_len(int	*str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] >= INT_MIN && str[i] <= INT_MAX && str[i] != 0)
			i++;
	}
	return (i);
}
