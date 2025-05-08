/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:18:41 by jotong            #+#    #+#             */
/*   Updated: 2025/05/07 20:18:42 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void    *memmove(void *dest, const void *src, int n)
{
    int     count;
    char    *ptr;

    ptr = dest;
    count = 0;
    if (src == NULL)
        return (NULL);
    else
    {
        while (count <= n)
        {
            *ptr = *src;
            ptr++;
            src++;
            count++;
        }
    }
}
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