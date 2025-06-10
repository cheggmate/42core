/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:49:59 by jotong            #+#    #+#             */
/*   Updated: 2025/06/06 23:58:47 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

int	ft_isalpha(int c)
{
	if (c == 0)
		return (0);
	if (!((c >= 97 && c <= 122) || (c >= 65 && c <= 90)))
		return (0);
	return (1);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*c1;
// 	unsigned char	*c2;

// 	c1 = (unsigned char *) s1;
// 	c2 = (unsigned char *) s2;
// 	i = 0;
// 	while ((*c1 == *c2 && *c1 != '\0' && *c2 != '\0') && i < n -1)
// 	{
// 		c1++;
// 		c2++;
// 		i++;
// 	}
// 	if (n == 0)
// 		return (0);
// 	else
// 		return (*c1 - *c2);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t			count;
// 	unsigned char	*ptr;

// 	count = 0;
// 	ptr = (unsigned char *)str;
// 	while (*ptr)
// 	{
// 		count++;
// 		ptr++;
// 	}
// 	return (count);
// }
