/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:40:08 by jotong            #+#    #+#             */
/*   Updated: 2025/05/09 20:41:48 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    int    *ptr;

    ptr = (int *)s;
    if (n <= 0 || (!(c >= 0 && c <= 255)))
        return (NULL);
    else
    {
        printf("ptr is %d\n", *ptr);
		while (*ptr)
        {
            printf("val checked is %d\n", *ptr);
			if (*ptr == c)
				break;
            else
                ptr++;
        }
		printf("ptr is pointing to %c\n", *ptr);
		return (ptr);
    }
}
/* 
#include <string.h>
int main(void)
{
    char    c = 'o';
    char    input[10] = "Hello";
    char    *out;

    out = (char *)memchr(input, c, strlen(input));
    if (out != NULL)
        printf("character '%c' found at position %ld\n", c, out - input);
    else
        printf("Character '%c' not found \n", c);
} */