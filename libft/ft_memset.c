/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:36:01 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 17:41:23 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
void    *ft_memset(void *ptr, int value, int num)
{
    int     counter;
    int     *dest;

    counter = 0;
    dest = (int*)ptr;                   // check if this works
    while (*dest && counter <= num)
    {
        *dest = value;
        dest++;
        counter++;
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