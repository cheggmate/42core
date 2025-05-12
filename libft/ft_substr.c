/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:31:21 by jotong            #+#    #+#             */
/*   Updated: 2025/05/12 11:16:16 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		ctr;
	unsigned int		real_len;

	ctr = start;
	real_len = ft_strlen(s);
	if (len <= 0 || !s || real_len == 0 || real_len < start + 1)
		return (NULL);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	else
	{
		while ((ctr < real_len) && ctr < len - start)
		{
			substr[ctr - start] = s[ctr];
			ctr++;
		}
		substr[ctr - start] = '\0';
		return (&substr[0]);
	}
}
