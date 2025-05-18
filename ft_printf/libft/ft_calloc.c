/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:39:43 by jotong            #+#    #+#             */
/*   Updated: 2025/05/16 18:15:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char		*arr;
	size_t				count;

	arr = NULL;
	count = 0;
	if (num <= 0 || size <= 0)
		return (malloc(0));
	if (num == (size_t)INT_MAX || size == (size_t)INT_MAX)
		return (NULL);
	if (num > 0 && size > SIZE_MAX / num)
		return (NULL);
	arr = malloc(num * size);
	if (!arr)
		return (NULL);
	else
	{
		while (count < size)
		{
			arr[count] = 0;
			count++;
		}
		return (arr);
	}
}
