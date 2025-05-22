/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_unbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:47:53 by jotong            #+#    #+#             */
/*   Updated: 2025/05/22 21:49:30 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "ft_printf.h"

#include <stdio.h>

size_t	ft_p_unbr(unsigned int n, char type)
{
	int		count;
	char	string;

	count = 0;
	if (n == 4294967295)
	{
		count += write(1, "4294967295", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
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
