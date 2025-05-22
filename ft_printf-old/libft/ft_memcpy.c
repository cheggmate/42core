/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:44:42 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 17:25:53 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			len;

	len = 0;
	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	if (!to || !from)
		return (dest);
	else
	{
		while (len < n)
		{
			to[len] = from[len];
			len++;
		}
	}
	return (dest);
}
/* #include <stdio.h>
int main(void)
{
    char source[] = "Hello";
    char destination[10];

    memcpy(&destination, &source, 6);  // Includes the null terminator
    printf("Copied string: %s\n", destination);  // Output: Hello

    return 0;
} */