/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:40:10 by jotong            #+#    #+#             */
/*   Updated: 2025/05/12 11:51:48 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	flush_everything(const char *restrict src, unsigned int *count)
{
	unsigned int	temp_count;

	temp_count = *count;
	while (*src)
	{
		if (src != NULL)
		{
			temp_count++;
			src++;
		}
		else
			break ;
	}
	*count = temp_count;
}

static char	*copy_over(char *restrict dest, const char *restrict src_ptr, \
	unsigned int *count, unsigned int *rem)
{
	int	temp_count;
	int	temp_rem;

	temp_rem = *rem;
	temp_count = *count;
	while (*src_ptr && temp_rem > 1)
	{
		*dest = *src_ptr;
		src_ptr++;
		dest++;
		temp_count++;
		temp_rem--;
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

size_t	ft_strlcpy(char *restrict dest, \
	const char *restrict src, size_t size)
{
	unsigned int	count;
	unsigned int	remainder;

	count = 0;
	remainder = size;
	if (size == 0)
	{
		flush_everything(src, &count);
		return (count);
	}
	else if (!src)
		return (0);
	else
	{
		dest = copy_over(dest, src, &count, &remainder);
		*dest = '\0';
		return (count);
	}
}
/*
int	main(void)
{
	char 			src[] = "HELLO THERE";
	char 			dest[100] = "HEY,";
	unsigned int	size = 100;
	unsigned int	out = 0;

	out = ft_strlcpy(dest, src, size);
	printf("out = %i", out);
	return(0);
}*/