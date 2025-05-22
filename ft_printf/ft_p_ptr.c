/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:36:59 by jotong            #+#    #+#             */
/*   Updated: 2025/05/22 10:04:58 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

size_t		ft_p_ptr(char *s)
{
	int			count;

	count += write(1, s, sizeof(s));
	return (count);
}