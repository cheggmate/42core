/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:15:28 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 17:28:31 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isascii(int c)
{
    if (!(c >= 0 && c <= 127))
        return (0);
    else
        return (1);
}
/* #include <stdio.h>
int main(void)
{
    int val;
    int out;

    val = 120;
    out = ft_isascii(val);
    printf("out is %d\n", out);
} */