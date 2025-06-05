/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:21:45 by jotong            #+#    #+#             */
/*   Updated: 2025/06/05 23:39:13 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <limits.h>

int		ft_arr_len(int	*str);
void	push_a(int	*stack_a, int *stack_b, int *len_a, int *len_b);
void	push_b(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	rev_rot_a(int *a);
void	rev_rot_b(int *b);
void	rotate_a(int *stack_a);
void	rotate_b(int *stack_b);
void	swap_a(int	*stack_a);
void	swap_b(int	*stack_b);
void	swap_both(int *stack_a, int *stack_b);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	print_stack(int	*s, int *len);									// remove this before submission

# endif
