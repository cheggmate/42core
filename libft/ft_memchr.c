/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:40:08 by jotong            #+#    #+#             */
/*   Updated: 2025/05/12 10:12:43 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			count;

	count = 0;
	ptr = (unsigned char *)s;
	if (n <= 0 || (!(c >= 0 && c <= 255)))
		return (NULL);
	else
	{
		while (count < n)
		{
			if (ptr[count] == c)
				return (&ptr[count]);
			else if (!ptr[count])
				break ;
			else
				count++;
		}
	}
	
	return ((void *)0);
}
/* 
#include <string.h>
int main(void)
{
    char	data2[] = "abcdef";
	char	*result2;
	result2 = ft_memchr(data2, 'x', 6);
    if (result2 != NULL)
        printf("character found,\n");
    else
        printf("Character not found");
} */