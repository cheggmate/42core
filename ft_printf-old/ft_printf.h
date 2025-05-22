/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:55:50 by jotong            #+#    #+#             */
/*   Updated: 2025/05/18 22:55:47 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_h

#include <stdlib.h>

typedef struct s_print
{
	va_list		args;
	int			width;
	int			precision;
	int			decimal;
	int			dash; // '-'
	int			len;
	int			sign;
}	t_print;

// definition of function
int			ft_printf(const char *content, ...);
#endif