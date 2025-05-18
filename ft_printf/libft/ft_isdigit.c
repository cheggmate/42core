/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:21:56 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 20:47:40 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/* #include <stdio.h>
int main(void)
{
	int out;
    int val = 3;

    out = ft_isdigit(val);
    printf("result is %d\n", out);
} */