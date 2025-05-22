/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:33:44 by jotong            #+#    #+#             */
/*   Updated: 2025/05/22 22:28:05 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // remove when removing all printf
#include <unistd.h>
#include "ft_printf.h"

ssize_t	ft_p_str(char *s, char type)
{
	if (type == 'c')
		return (write(1, &s, 1));
	else
		return (write(1, s, ft_strlen(s)));
}
