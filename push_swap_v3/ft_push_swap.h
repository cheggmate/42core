/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:21:45 by jotong            #+#    #+#             */
/*   Updated: 2025/06/16 00:00:19 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_arr_len(int	*str);
int		find_pos(int *str, int val, int len);
int		is_num(char *str);
int		*ft_arr_dup(int *stack, int len);
int		check_order(int len, int *stack);
int		check_dups(int	*stack, int len);
int		prep_string(int len, char **str, int *stack);
int		prep_values(int len, int *stack, char **argv);
int		find_largest(int *stack, int len);
int		is_sorted(int *stack, int len);
// void	rotate_and_push(int *stack_b, int *stack, int *b_len, int *len);
// int		rotate_and_push_top(int *stack_b, int *stack, int *b_len, int *len);
// int		push_and_rotate(int *dest, int *src, int *dest_len, int *src_len);
// int		adjust_rotate_and_push_bottom(int *stack_b, int *stack, int *b_len, int *len);
// void	find_mids(int *stack, int len, int *smlr, int *bgr);
void	insertion_sort(int	*stack_dup, int len);
int		pusha(int	*stack_dest, int *stack_src, int *len_dest, int *len_src);
int		pushb(int	*stack_dest, int *stack_src, int *len_dest, int *len_src);
int		push_swap(int *stack, int len);
void	rev_rot(int *stack, int *len, int ab);
void	rr(int	*stack_a, int *stack_b, int *len_a, int *len_b);
void	rrr(int	*stack_a, int *stack_b, int *len_a, int *len_b);
void	rotate(int *stack, int *len, int ab);
void	start_chunking(int *stack, int *stack_b, int *len, int *b_len);
void	chunk_optmzns(int *stack, int *stack_b, int *len, int *b_len);
void	split_stack(int *stack, int  *stack_b, int *len, int *b_len);
void	sort_stack(int *stack, int len);
void	sorted_return(int *stack, int *stack_b, int *len, int *b_len);
void	swap(int	*stack, int *len, int ab);
void	swap_both(int *stack_a, int *stack_b, int *len_a, int *len_b);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split_count(const char *s, char c, int *word_count);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_stack(int	*s, int *len, char ab);									// remove this before submission

# endif
