/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:43:09 by jotong            #+#    #+#             */
/*   Updated: 2025/05/21 23:12:01 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t			count;
	unsigned char	*ptr;

	count = 0;
	ptr = (unsigned char *)str;
	while (*ptr)
	{
		count++;
		ptr++;
	}
	return (count);
}
