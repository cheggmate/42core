/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:32:01 by jotong            #+#    #+#             */
/*   Updated: 2025/05/13 00:45:27 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

static char	*reverse_string(char *str)
{
	int		len;
	int		pos;
	char	tmp_chr;

	pos = 0;
	len = ft_strlen(str);
	while (pos < len / 2)
	{
		tmp_chr = str[pos];
		str[pos] = str[len - pos - 1];
		str[len - pos - 1] = tmp_chr;
		pos++;
	}
	return (str);
}

static char	*create_string(int n, int is_negative)
{
	int		pos;
	char	*str_n;

	pos = 0;
	str_n = malloc(11 + 1);
	while (n > 0)
	{
		str_n[pos++] = (n % 10) + '0';
		n = n / 10;
	}
	if (is_negative == -1)
		str_n[pos++] = '-';
	str_n = reverse_string(str_n);
	return (str_n);
}

static char	*handle_limits_and_zero(int n)
{
	char	*str_n;

	if (n == INT_MIN)
	{
		str_n = malloc(11 + 1);
		ft_strlcpy(str_n, "-2147483648", 12);
	}
	else if (n == INT_MAX)
	{
		str_n = malloc(11 + 1);
		ft_strlcpy(str_n, "2147483647", 12);
	}
	else
	{
		str_n = malloc(1 + 1);
		ft_strlcpy(str_n, "0", 2);
	}
	return (str_n);
}

char	*ft_itoa(int n)
{
	int		is_negative;
	char	*str_n;

	is_negative = 1;
	if (n == INT_MAX || n == INT_MIN || n == 0)
	{
		str_n = handle_limits_and_zero(n);
		return (str_n);
	}
	if (n < 0)
	{
		is_negative = -1;
		n = -n;
	}
	str_n = create_string(n, is_negative);
	return (str_n);
}
