/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:23:03 by jotong            #+#    #+#             */
/*   Updated: 2025/05/17 14:55:04 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int			len;
	char		*dup;

	len = 0;
	len = ft_strlen(s1);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (dup);
	else
	{
		ft_memcpy(dup, s1, len + 1);
		return (dup);
	}
}
