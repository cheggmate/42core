/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:21:45 by jotong            #+#    #+#             */
/*   Updated: 2025/06/06 09:27:16 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <limits.h>

int		ft_arr_len(int	*str);
void	push(int	*stack_dest, int *stack_src, int *len_dest, int *len_src);
void	rev_rot(int *stack, int *len);
void	rotate(int *stack, int *len);
void	swap(int	*stack, int *len);
void	swap_both(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	print_stack(int	*s, int *len);									// remove this before submission

# endif
