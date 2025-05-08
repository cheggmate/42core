/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:40:08 by jotong            #+#    #+#             */
/*   Updated: 2025/05/07 19:50:07 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *memchr(const void *s, int c, int n)
{
    char    *ptr;

    ptr = s;
    if (n <= 0 || (!(c >= 0 && c <= 255)))
        return (NULL);
    else
    {
        while (*ptr)
        {
            if (*ptr == c)
               ptr = s;
            else
                ptr++;
        }
    }
}
/* #include <stdio.h>
int main(void)
{
    char    c = 'e';
    char    input[10] = "Hello";
    char    *out;

    out = (char *)memchr(input, c, strlen(str));
    if (out != NULL)
        printf("character '%c' found at position %ld\n", c, out - input);
    else
        printf("Character '%c' not found \n");
} */