/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:31:21 by jotong            #+#    #+#             */
/*   Updated: 2025/05/07 19:03:59 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void    bzero(void *s, int n)
{
    char    *ptr;

    ptr = s;
    if (!(*ptr == NULL) || (n <= 0))
    {
        while (*ptr)
        {
            *ptr = 0;
            ptr++;
        }
    }
}
/* 
int main(void)
{
    int     val = 2;
    char    buffer[10];
    bzero(&buffer, val);
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
} */