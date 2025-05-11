/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:03:06 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 20:48:10 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>

static void	flush_everything(char *dest, char *src, unsigned int *count)
{
	unsigned int	temp_count;

	temp_count = *count;
	while (*dest)
	{
		temp_count++;
		dest++;
	}
	while (*src)
	{
		temp_count++;
		src++;
	}
	*count = temp_count;
}

static char	*copy_over(char *dest, char *src_ptr, \
	unsigned int *count, unsigned int *rem)
{
	int	temp_count;
	int	temp_rem;

	temp_rem = *rem;
	temp_count = *count;
	while (*src_ptr && temp_rem > 0)
	{
		*dest = *src_ptr;
		src_ptr++;
		dest++;
		temp_rem--;
		temp_count++;
	}
	while (*src_ptr)
	{
		temp_count++;
		src_ptr++;
	}
	*rem = temp_rem;
	*count = temp_count;
	return (dest);
}

unsigned int	ft_strlcat(char *restrict dest, \
	const char *restrict src, size_t size)
{
	unsigned int	remainder;
	unsigned int	count;
	char			*src_ptr;

	count = 0;
	remainder = size;
	src_ptr = (char *) src;
	if (size == 0)
	{
		flush_everything(dest, src_ptr, &count);
		return (count);
	}
	while (*dest)
	{
		dest++;
		count++;
		remainder--;
	}
	dest = copy_over(dest, src_ptr, &count, &remainder);
	*dest = '\0';
	return (count);
}
/* include <stdio.h>
int     main(void)
{
    char    str1[] = "World!";
    char    str2[20] = "Hello"; // destination

    unsigned int    size;
    unsigned int	length;

    size = sizeof(str2);
    length = ft_strlcat(str2, str1, size);
	printf("length is: %i\n", length);
	printf("dest is: %s\n",str2);
} */