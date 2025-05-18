/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:28:27 by jotong            #+#    #+#             */
/*   Updated: 2025/05/12 15:00:27 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static void	*copy_string(char const *s1, char const *s2, char *new_str)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*new_sub_str;

	len1 = 0;
	len2 = 0;
	new_sub_str = new_str;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	if (s1 != NULL || len1 > 0)
	{
		ft_strlcpy(new_str, s1, len1 + 1);
		new_sub_str += len1;
	}
	if (s2 != NULL || len2 > 0)
		ft_strlcpy(new_sub_str, s2, len2 + 1);
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	total_len;
	unsigned int	len1;
	unsigned int	len2;

	total_len = 0;
	len1 = 0;
	len2 = 0;
	if (!(s1 && s2))
		return (NULL);
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	total_len = len1 + len2;
	new_str = (char *)malloc(total_len + 1);
	if (!new_str)
		return (NULL);
	else
	{
		copy_string(s1, s2, new_str);
		return (new_str);
	}
}
