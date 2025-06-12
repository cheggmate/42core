/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:49:59 by jotong            #+#    #+#             */
/*   Updated: 2025/06/12 22:00:55 by jotong           ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	unsigned int	final_int;
	int				sign;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	final_int = 0;
	sign = 1;
	while (*ptr == '\t' || *ptr == '\n' || *ptr == '\v'
		|| *ptr == '\f' || *ptr == '\r' || *ptr == ' ')
		ptr++;
	if ((*ptr == '-' || *ptr == '+'))
	{
		if (*ptr == '-')
			sign *= -1 ;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		final_int = final_int * 10 + *ptr - '0';
		ptr++;
	}
	return (final_int * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	i = 0;
	while ((*c1 == *c2 && *c1 != '\0' && *c2 != '\0') && i < n -1)
	{
		c1++;
		c2++;
		i++;
	}
	if (n == 0)
		return (0);
	else
		return (*c1 - *c2);
}

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
