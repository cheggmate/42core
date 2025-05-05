/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:51:16 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 13:51:22 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	final_int;
	int	sign;

	final_int = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
	*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1 ;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		final_int = final_int * 10 + *str - '0';
		str++;
	}
	return (final_int * sign);
}
/* 
#include <stdio.h>
int	main(void)
{
	int	out;

	out = ft_atoi("-----21474836sdv");
	printf("out: %i\n", out);
	return (0);
} */