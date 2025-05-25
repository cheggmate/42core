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

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*ptr;
	unsigned char	to_search;

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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			count;

	count = 0;
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (dest1 < src1 || dest1 >= src1 + n)
	{
		while (count < n)
		{
			dest1[count] = src1[count];
			count++;
		}
	}
	else
	{
		count = n;
		while (count > 0)
		{
			dest1[count - 1] = src1[count - 1];
			count--;
		}
	}
	return (dest);
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

char	*check_or_read(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*out;
	char		*eol;
	char		*tmp;
	size_t		read_b;

	out = (char *)malloc((2 * BUFFER_SIZE + 1) * sizeof (char *));
	if (!out)
		return (NULL);
	// len = 0;
	if (*buf)
	{
		eol = ft_strchr(buf, '\n');
		// len = eol - buf;
		if (eol - buf > 0)  // found a newline
		{
			ft_strlcpy(out, buf, (size_t)(eol - buf + 1));
			memmove(buf, eol + 1, eol - buf);		// shift left
			// buf[len] = '\0';  // check if this is needed
		}
		else  // did not find a newline, need to read more
		{
			// len = ft_strlen(buf);
			ft_strlcpy(out, buf, ft_strlen(buf) + 1); // copy remainder of buff to out
			read_b = read(fd, buf, BUFFER_SIZE); // read more, create new array, and then copy the string to be returned to out.
			ft_strlcat(out, buf, BUFFER_SIZE);
			eol = ft_strchr(buf, '\n');
			while (eol == NULL)
			{
				tmp = (char *)malloc((len(out) + BUFFER_SIZE) * sizeof(char *));
				ft(strlcpy(tmp, eol, eol - out + 1));
				free(out);
				out = tmp;
				read_b = read(fd, buf, BUFFER_SIZE);
				eol = ft_strchr(buf, '\n');
				// copy from buff until '\n' to out.
			}
			
		}
	}
	
	return (out);
}
