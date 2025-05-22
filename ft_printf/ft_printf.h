/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:55:50 by jotong            #+#    #+#             */
/*   Updated: 2025/05/22 22:32:22 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// definition of function
int			ft_printf(const char *content, ...);
ssize_t		ft_p_str(char *s, char type);
size_t		ft_p_nbr(int n, char type);
size_t		ft_p_nbr_base(unsigned int nbr, char type, char *base);
size_t		ft_p_ptr(void *s, const char *hex);
size_t		ft_strlen(const char *str);
size_t		ft_p_unbr(unsigned int n, char type);
#endif