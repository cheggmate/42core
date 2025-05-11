/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:24:00 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 20:46:39 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/* #include <stdio.h>
int main(void)
{
    int c;
    int out;

    c = 65;
    out = ft_tolower(c);
    printf("out is %d\n", out);
} */