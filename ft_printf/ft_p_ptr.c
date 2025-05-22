/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:36:59 by jotong            #+#    #+#             */
/*   Updated: 2025/05/22 22:02:04 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

size_t		ft_p_ptr(void *s, const char *hex)
{
	int			count;
	uintptr_t	addr;
	char		buffer[20];
	int			i;

	i = 19;
	addr = (uintptr_t)s;
	if (addr == 0)
	{
		count += write(1, "0x0\n", 4);
		return (count);
	}
	while(addr && i >= 2)
	{
		buffer[i--] = hex[addr % 16];
        addr /= 16;
	}
	buffer[i] = 'x';
	i--;
    buffer[i] = '0';
	count += write(1, &buffer[i], 20 - i);
	return (count);
}
