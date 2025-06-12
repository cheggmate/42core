/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:21:45 by jotong            #+#    #+#             */
/*   Updated: 2025/06/12 18:28:15 by jotong           ###   ########.fr       */
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
int		ft_isalpha_str(char	*str);
int		ft_atoi(const char *str);
int		check_copy_inputs(int len, int *stack, char **argv);
int		get_med(int	*arr, int arr_len);
void	pusha(int	*stack_dest, int *stack_src, int *len_dest, int *len_src);
void	pushb(int	*stack_dest, int *stack_src, int *len_dest, int *len_src);
void	push_swap(int *stack, int len, int median);
void	rev_rot(int *stack, int *len, int ab);
void	rr(int	*stack_a, int *stack_b, int *len_a, int *len_b);
void	rrr(int	*stack_a, int *stack_b, int *len_a, int *len_b);
void	rotate(int *stack, int *len, int ab);
void	split_stack(int *stack, int  *stack_b, int len, int median);
void	sort_stack(int *stack, int  *stack_b, int len, int median);
void	swap(int	*stack, int *len, int ab);
void	swap_both(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	print_stack(int	*s, int *len, char ab);									// remove this before submission

# endif
