/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:18:41 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 15:14:47 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

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
// notes for above
// "if" flow: copy fwd if dest is before src
// "else" flow: if overlap and dest is after src, copy backwards
// while loop in else flow: -1 to acct for zero index
/*
int main(void)
{
    int     n = 1;
    char    src[10] = "hello land";
    char    *out;

    memmove(out, &src, n);
    if (out != NULL)
        printf("final string is %s\n", out);
} */