/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:55:29 by jotong            #+#    #+#             */
/*   Updated: 2025/05/22 10:05:21 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include "ft_printf.h"

#include <stdio.h>

static size_t eval_form(va_list args, const char *form, int x)
{
	void	*ptr;

	// printf("form = %c\n", form[x]);
	if (form[x-1] == '%' && form[x])
	{
		if (form[x] == 'c' || form[x] == 's')
			return(ft_p_str(va_arg(args, char *), form[x]));
		else if (form[x] == 'd' || form[x] == 'i' || form[x] == 'u')
			return(ft_p_nbr(va_arg(args, int), *form));
		else if (form[x] == 'x')
			return(ft_p_nbr_base(va_arg(args, int), form[x], "0123456789abcdef"));
		else if (form[x] == 'X')
			return(ft_p_nbr_base(va_arg(args, int), form[x], "0123456789ABCDEF"));
		else if (form[x] == '%')
			return (write(1, "%", 1));
		else if (*form == 'p')
			return(ft_p_ptr(va_arg(args, char *)));
		else
			x--;
	}
	return (0);
}

int	ft_printf(const char *form, ...)
{
	int			total;
	int			x;
	va_list		args;

	x = -1;
	total = 0;
	va_start(args, form); // sets the va_list variable with the last fixed argument
	// other allowed funcs: va_arg, va_copy, va_end, malloc, free, write
	while (form[++x])
	{
		if (form[x] == '%')
		{
			total = eval_form(args, form, x + 1);
			x++;	
		}

		else
			write(1, &form[x], 1);
	}
	va_end(args); // cleans up the va_list variable.
	return (0);
}
