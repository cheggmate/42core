/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tester.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/05/18 11:07:09 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TESTER_H
# define FT_PRINTF_TESTER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

/* These are the functions you need to implement */
int		ft_printf(const char *format, ...);

/* Test function prototypes */
void	test_percent_bonus(void);
void	test_char(void);
void	test_string(void);
void	test_pointer(void);
void	test_decimal(void);
void	test_unsigned(void);
void	test_hex(void);
void	test_return_values(void);

/* Helper function prototypes */
void	print_test_header(const char *test_name);
void	print_test_subheader(const char *subheader);

#endif