/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:36:01 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 15:54:40 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			count;
	unsigned char	*dest;

	count = 0;
	dest = (unsigned char *)ptr;
	while (count < num)
	{
		dest[count] = value;
		count++;
	}
	return (ptr);
}
/* #include <stdio.h>
int main(void)
{
    char buffer[10];

    memset(buffer, 'A', 9);  // Fill first 9 bytes with 'A'
    buffer[9] = '\0';        // Null-terminate the string

    printf("Buffer: %s\n", buffer);  // Output: AAAAAAAAA
    return 0;
} */