/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:37:43 by jotong            #+#    #+#             */
/*   Updated: 2025/05/17 14:56:52 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*ptr;
	unsigned char	to_search;

	to_search = (unsigned char)c;
	ptr = (unsigned char *)str;
	if (!(to_search == 9 || to_search == 10 \
		|| (to_search >= 32 && to_search <= 126) || to_search == 0))
		return (NULL);
	while (*ptr)
	{
		if (*ptr == (char)to_search)
			return ((char *)ptr);
		ptr++;
	}
	if ((char)to_search == '\0')
		return ((char *)ptr);
	return (NULL);
}
