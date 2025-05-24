/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:55:50 by jotong            #+#    #+#             */
/*   Updated: 2025/05/23 17:13:42 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h> // remove when removing all printf statements
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

// definition of function
int			ft_printf(const char *content, ...);
ssize_t		ft_p_str(char *s);
size_t		ft_p_nbr(int n, char type);
size_t		ft_p_nbr_base(unsigned int nbr, char *base);
size_t		ft_p_ptr(void *s, const char *hex);
size_t		ft_strlen(const char *str);
size_t		ft_p_unbr(unsigned int n, char type);
ssize_t		ft_p_char(int c);
#endif