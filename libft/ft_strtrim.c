/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:11:33 by jotong            #+#    #+#             */
/*   Updated: 2025/05/12 16:01:37 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	fill_string(char const *s1, char const *set, char *new_str)
{
	char	*dup;

	while (*s1)
	{
		dup = ft_strchr(set, (int)(*s1));
		if (!dup)
		{
			*new_str = *s1;
			new_str++;
		}
		s1++;
	}
	*new_str = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	char	*new_str_start;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (!set)
	{
		new_str = ft_strdup(s1);
		return (new_str);
	}
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	new_str_start = new_str;
	fill_string(s1, set, new_str);
	return (new_str_start);
}
