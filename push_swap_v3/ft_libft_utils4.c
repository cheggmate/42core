/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:55:57 by jotong            #+#    #+#             */
/*   Updated: 2025/07/04 23:31:17 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			count;
	unsigned char	*dest;

	count = 0;
	dest = (unsigned char *)ptr;
	while (count < num)
	{
		dest[count] = value;
		count++;
	}
	return (ptr);
}
