/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:08:01 by jotong            #+#    #+#             */
/*   Updated: 2025/05/10 23:55:25 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>  // check if this is allowed

#ifndef LIBFT_h
# define IF_TRUE 1
# define IF_FALSE 0
// include information here
// # define ABS(Value) ({
//     int_num = (Value);
//     if (_num < 0) {
//         _num = - _num;
//     }
//     _num;
// })

// declare functions here
int             ft_atoi(const char *str);
void            ft_bzero(void *s, size_t n);
int 			ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int 			ft_isdigit(int c);
int 			ft_isprint(int c);
char			*ft_strchr(const char *str, int c);
unsigned int	ft_strlcat(char *restrict dest, const char *restrict src, size_t size);
unsigned int	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(char *str, char *to_find, int len);
int 			ft_tolower(int c);
int 			ft_toupper(int c);

// ft_memset
// ft_memcpy
// ft_memchr
// ft_memmomve
// ft_strrchr
#endif