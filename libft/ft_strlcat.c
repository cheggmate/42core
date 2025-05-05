/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:03:06 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 22:29:49 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* void	ft_fill_up_string(char *ptr, char *dest, \
    unsigned int len, unsigned int s)
{
while (*ptr && len + 1 < s)
{
    *dest = *ptr;
    dest++;
    ptr++;
}
*dest = '\0';
}

int	ft_calc_remainder(unsigned int len, unsigned int size, unsigned int rm)
{
if (len >= size)
    rm += size;
else
    rm += len;
return (rm);
} */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	length;
	unsigned int	remainder;
	char			*src_ptr;

	length = 0;
	remainder = size;
	src_ptr = src;
    if (size == 0)
        return (0);
	while (*dest)
	{
		dest++;
		length++;
        remainder--;
	}
	while (*src && remainder > 0)
	{
		src++;
		remainder--;
	}
    *dest = '\0';
	// remainder = ft_calc_remainder(length, size, remainder);
	// ft_fill_up_string(src_ptr, dest, length, size);
	return (size - remainder);
}
/* 
#include <stdio.h>
int     main(void)
{
    char    str1[] = "year of interesting things";
    char    str2[80] = "this is the year 2023";

    unsigned int    size;
    unsigned int	length;
	char			*dest_ptr;

	dest_ptr = str2;
    size = 25;
    length = ft_strlcat(str2, str1, size);
	printf("length is %i\n", length);
	printf("dest is %s\n", dest_ptr);
    return(0);
} */