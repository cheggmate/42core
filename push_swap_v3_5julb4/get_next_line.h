/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:40:58 by jotong            #+#    #+#             */
/*   Updated: 2025/07/05 16:56:20 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int					len_a;
	int					len_b;
	int					*stack_a;
	int					*stack_b;
}					t_stack;

void	free_buf(char **buf, int fd);
char	*rd_parse_line(char **buf, int fd, char *tmp_buf, ssize_t *b);
char	*get_line(char *buf);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*rem_print(char *buf);
int		pswap_for_string(t_stack *stack, char **argv);
int		pswap_for_int(t_stack *stack, char **argv);
int		is_sorted(int *stack, int len);

#endif