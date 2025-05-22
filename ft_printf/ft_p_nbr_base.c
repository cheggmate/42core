/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_nbr_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:57:13 by jotong            #+#    #+#             */
/*   Updated: 2025/05/21 23:26:38 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

size_t	ft_p_nbr_base(int *nbr, char type, char *base)
{
	int		i;
	char	buffer[32];

	int	count;

	count = 0;
	if (*nbr == 0)
		count += write(1, "0", 1);
	while (*nbr > 0)
	{
		if (type == 'x')
			buffer[i] = base[*nbr % 16];
		else
			buffer[i] = base[*nbr % 16];
		*nbr /= 16;
	}
	while (i-- > 0)
		count += write(1, &buffer[i], 1);
	return (count);
}
