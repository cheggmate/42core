/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:39:43 by jotong            #+#    #+#             */
/*   Updated: 2025/05/15 18:38:57 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char		*arr;
	unsigned char		*temp_ptr;

	if (num <= 0 || size <= 0 || num == (size_t)INT_MAX || num == (size_t)INT_MIN \
	|| size == (size_t)INT_MAX || size == (size_t)INT_MIN)
		return (NULL);
	
	if (num > 0 && size > SIZE_MAX / num)
		return (NULL);
	arr = malloc(num * size);
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
