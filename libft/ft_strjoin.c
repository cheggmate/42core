/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:28:27 by jotong            #+#    #+#             */
/*   Updated: 2025/05/26 22:04:32 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	ft_strlcpy(new_str, s1, total_len + 1);
	ft_strlcat(new_str, s2, total_len + 1);
	return (new_str);
}
