/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:41 by jotong            #+#    #+#             */
/*   Updated: 2025/06/12 22:14:33 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (!src || !dest)
		return (0);

	if (size > 0)
	{
		while (src[count] && count < (size - 1))
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0'; 
	}

	return ft_strlen(src);
}

static int	count_digits(int m, int n_digits)
{
	while (m > 0)
	{
		m /= 10;
		n_digits++;
	}
	return (n_digits);
}

static char	*create_string(int n, int is_negative, char *str_n)
{
	int		pos;
	int		m;
	int		n_digits;

	pos = 0;
	m = n;
	n_digits = 0;
	n_digits = count_digits(m, n_digits);
	str_n = malloc(n_digits + is_negative + 1);
	if (str_n)
	{
		str_n[n_digits + is_negative] = '\0';
		while (n > 0)
		{
			str_n[n_digits + is_negative - pos - 1] = (n % 10) + '0';
			n = n / 10;
			pos++;
		}
		if (is_negative)
			str_n[0] = '-';
	}
	return (str_n);
}

static char	*handle_limits_and_zero(int n, char *str_n)
{
	if (n == INT_MIN)
	{
		str_n = malloc(11 + 1);
		if (str_n)
			ft_strlcpy(str_n, "-2147483648", 12);
	}
	else if (n == INT_MAX)
	{
		str_n = malloc(10 + 1);
		if (str_n)
			ft_strlcpy(str_n, "2147483647", 11);
	}
	else
	{
		str_n = malloc(1 + 1);
		if (str_n)
			ft_strlcpy(str_n, "0", 2);
	}
	return (str_n);
}

char	*ft_itoa(int n)
{
	int		is_negative;
	char	*str_n;

	str_n = NULL;
	is_negative = 0;
	if (n == INT_MAX || n == INT_MIN || n == 0)
	{
		str_n = handle_limits_and_zero(n, str_n);
		return (str_n);
	}
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	str_n = create_string(n, is_negative, str_n);
	return (str_n);
}
