/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:27:29 by jotong            #+#    #+#             */
/*   Updated: 2025/05/15 21:20:57 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	char	*latest;

	ptr = (char *)str;
	latest = NULL;
	while (*ptr)
	{
		if (*ptr == (char)c)
			latest = ptr;
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	else
		return (latest);
}
