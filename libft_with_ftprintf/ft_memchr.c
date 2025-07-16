/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:40:08 by jotong            #+#    #+#             */
/*   Updated: 2025/05/23 15:12:54 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;
	unsigned char			target;
	size_t					count;

	count = 0;
	target = (unsigned char)c;
	ptr = (const unsigned char *)s;
	if (n < 0)
		return (NULL);
	else
	{
		while (count < n)
		{
			if (*ptr == target)
				return ((void *)ptr);
			else
			{
				count++;
				ptr++;
			}
		}
		return (NULL);
	}
}
