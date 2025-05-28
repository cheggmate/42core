 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:42:05 by jotong            #+#    #+#             */
/*   Updated: 2025/05/24 15:42:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*ptr;
	unsigned char	to_search;

	if (!str)
		return (NULL);
	to_search = (unsigned char)c;
	ptr = (unsigned char *)str;
	if (!(to_search == 9 || to_search == 10
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (!src || !dest)
		return (0);

	if (size > 0)
	{
		while (src[count] && count < (size - 1))
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0'; 
	}

	return ft_strlen(src);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	total_len;

	total_len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1 != NULL)
		total_len += ft_strlen(s1);
	if (s2 != NULL)
		total_len += ft_strlen(s2);
	new_str = (char *)malloc(total_len + 1);
	new_str[0] = '\0';
	if (!new_str)
		return (NULL);
	if (s1)
		ft_strlcat(new_str, s1, total_len + 1);
	if (s2)
		ft_strlcat(new_str, s2, total_len + 1);
	return (new_str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	i = 0;
	dest_size = 0;
	src_size = 0;
	while (dest[dest_size] && dest_size < size)
		dest_size++;
	while (src[src_size])
		src_size++;
	if (dest_size >= size)
	{
		if (dest_size > size)
			dest[dest_size] = '\0';
		return (size + src_size);
	}
	while (src[i] && (dest_size + i + 1) < size)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	if (dest_size + i < size)
		dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
