/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:23:05 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 17:27:12 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_toupper(int c)
{
    if (!(c >= 97 && c <= 122))
        return (c + 32);
    else
        return (c);
}
/* #include <stdio.h>
int main(void)
{
    int c;
    int out;

    c = 97;
    out = ft_toupper(c);
    printf("out is %d\n", c);
} */