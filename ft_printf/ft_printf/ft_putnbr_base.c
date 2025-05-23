/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:57:13 by jotong            #+#    #+#             */
/*   Updated: 2025/05/23 16:00:30 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int, char case)
{
	int		i;
	char	lower_base[] = "0123456789abcdef";
	char	upper_base[] = "0123456789ABCDEF";
	int		*ptr;
	char	buffer[32];

	ptr = va_arg(arg, int);
	if (*ptr == 0)
		write(1, '0', 1);
	while (*ptr > 0)
	{
		if (case == 'x')
			buffer[i] = lower_base[*ptr % 16];
		else
			buffer[i] = upper_base[*ptr % 16]
		*ptr /= 16;
	}
	while (i-- > 0)
		write(1, &buffer[i], 1);
}
