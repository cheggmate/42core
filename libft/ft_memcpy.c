/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:44:42 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 17:44:43 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
void    *ft_memcpy(void *dest, const void *src, int n)
{
    int     *ptr;
    int     *from;
    int     len;

    len = 0;
    ptr = (int *)dest;      // check if this works
    from = (int *)src;      // check if this works
    while (*ptr && len <= n)
    {
        *ptr = *from;
        ptr++;
        src++;
        len++;
    }
    return (dest);
}
/* #include <stdio.h>
int main(void)
{
    char source[] = "Hello";
    char destination[10];

    memcpy(destination, source, 6);  // Includes the null terminator
    printf("Copied string: %s\n", destination);  // Output: Hello

    return 0;
} */