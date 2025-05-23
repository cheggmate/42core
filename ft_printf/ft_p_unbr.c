/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_unbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:47:53 by jotong            #+#    #+#             */
/*   Updated: 2025/05/23 19:24:32 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	neg_check(unsigned int n, int *count)
{
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n *= -1;
	}
	return (n);
}

size_t	ft_p_unbr(unsigned int n, char type)
{
	int		count;
	char	string;

	count = 0;
	if (n == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	n = neg_check(n, &count);
	if (n < 10)
	{
		string = n + '0';
		count += write(1, &string, 1);
		return (count);
	}
	ft_p_nbr(n / 10, type);
	string = (n % 10) + '0';
	count += write(1, &string, 1);
	return (count);
}
