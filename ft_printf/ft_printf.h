/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:55:50 by jotong            #+#    #+#             */
/*   Updated: 2025/05/22 10:07:33 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_h

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

// definition of function
int			ft_printf(const char *content, ...);
ssize_t		ft_p_str(char *s, char type);
size_t		ft_p_nbr(int n, char type);
size_t		ft_p_nbr_base(int nbr, char type, char *base);
size_t		ft_p_ptr(char *s);
size_t		ft_strlen(const char *str);
#endif