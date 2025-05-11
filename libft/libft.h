/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:08:01 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 21:05:14 by jotong           ###   ########.fr       */
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
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *ptr, int value, size_t num);
char			*ft_strchr(const char *str, int c);
unsigned int	ft_strlcat(char *restrict dest, const char *restrict src, size_t size);
unsigned int	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size);
int				ft_strlen(const char *str);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(char *str, char *to_find, int len);
int 			ft_tolower(int c);
int 			ft_toupper(int c);
#endif