/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:28:20 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 17:28:21 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isprint(int c)
{
    if (!(c >= 32 && c <= 126))
        return (0);
    else
        return (1);
}
/* #include <stdio.h>
int main(void)
{
    int c;
    int out;

    c = 0;
    out = ft_isprint(c);
    printf("out is %d\n", out);
} */