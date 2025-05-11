/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:39:43 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 23:33:50 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	int	*arr;
	int	*temp_ptr;
	int	*zero_ptr;

	if (num <= 0 || size <= 0)
	{
		zero_ptr = (void *)0;
		return (zero_ptr);
	}
	arr = (int *)malloc(num * size);
	if (!arr)
		return (arr);
	else
	{
		temp_ptr = arr;
		while (*temp_ptr)
		{
			*temp_ptr = 0;
			temp_ptr++;
		}
		return (arr);
	}
}
