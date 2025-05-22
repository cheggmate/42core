/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:55:29 by jotong            #+#    #+#             */
/*   Updated: 2025/05/19 23:46:16 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"
#include "libft/libft.h"

static int	string_handler(t_print *item, char flag, int fd) // changes need to be made to parse contents of struct
{
	// if (flag == 'c')
	// 	ft_putchar_fd(item, fd);  // this needs to be updated, putchar doesnt support t_print item in first param
	// else if (flag == 's')
	// 	ft_putstr_fd(item, fd); // this needs to be updated, putchar doesnt support t_print item in first param
	return (0);  // temp return value.
}

static int	number_handler(t_print *item, char flag, int fd) // changes need to be made to parse contents of struct
{
	// if (flag == 'i' || flag == 'u')
	// 	ft_putnbr_fd(item, fd);  // to fix: ft_putnbr takes a integer in the first param.
	return (0);  // temp return value.
}

static void setup_struct(t_print *item)
{
	item->width = 0;
	item->precision = 0;
	item->decimal = 0;
	item->dash = 0;
	item->len = 0;
	item->sign = 0;
}

static int eval_form(t_print *item, const char *form, int x)
{
	if (form[x] == '%' && form[x + 1])
	{
		if (form[x] == '.')
		{
			item->decimal = 1;
			x++;
		}
		else if (form[x] == '-')
		{
			item->dash = 1;
			x++;
		}
		else if (form[x] == 'c' || form[x] == 's')
		{
			// putchar OR putstr
			// total += len of char OR string;
			// string_handler(*form, 1);
		}
		else if (*form == 'p' || *form == 'd' || *form == 'i' || *form == 'u')
		{
			// p 
			// handle pointers
			// total == length of item that the pointer is pointing to?

			// d
			// handle numbers (int and decimals)
			// total += number of digits + 1 if its negative for the sign

			// i
			// handle integers
			// total += number of digits + 1 for sign if negative

			// u
			// handle unsigned
			// total += number of digits (+decimals?)
		}
		else if (*form == 'x')
		{
			// handle lower hex
			// total += ??
		}
		else if (*form == 'X')
		{
			
			// handle upper hex
			// total += ??
		}
		else
		{
			// handle %%
		}
	}
	if (form[x] == 'c' || form[x] == 's')
			string_handler(item, form[x], 1);
		else if (form[x] == 'd' || form[x] == 'i')
			number_handler(item, form[x], 1);
	return (1);											// Todo: currently just a placeholder value that needs to be updated
}

int	ft_printf(const char *form, ...)
{
	int			total;
	int			x;
	t_print		*item;
	va_list		args;

	x = -1;
	total = 0;
	item = (t_print *)malloc(sizeof(t_print));
	if (!item)
		return (-1);
	setup_struct(item);
	va_start(item->args, form); // sets the va_list variable with the last fixed argument
	// other allowed funcs: va_arg, va_copy, va_end, malloc, free, write

	while (form[++x])
	{
		if (form[x] == '%')
			x = eval_form(item, form, x + 1);
		else
			write(1, &form[x], 1);
	}
	va_end(item->args); // cleans up the va_list variable.
	// total can be onbtained from item->len
	free(item);
	return (0);
}
