/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:21:45 by jotong            #+#    #+#             */
/*   Updated: 2025/07/02 00:06:56 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>

typedef struct s_list_ops
{
	char				*op_type;
	int					len;
	struct s_list_ops	*next;
}					t_list_ops;

typedef struct s_stack
{
	int					len_a;
	int					len_b;
	int					*stack_a;
	int					*stack_b;
}					t_stack;

// typedef struct s_list_split
// {
// 	int					start;
// 	int					end;
// 	int					smlr;
// 	int					bgr;
// 	struct s_list_split	*next;
// }					t_list_split;

int				ft_arr_len(int	*str);
int				find_pos(int *str, int val, int len);
int				is_num(char *str);
int				*ft_arr_dup(int *stack, int len);
void			*ft_memset(void *ptr, int value, size_t num);
void			*ft_calloc(size_t num, size_t size);
int				check_order(int len, int *stack);
int				check_dups(t_stack *stack);
int				prep_string(t_stack *stack, char **str);
int				prep_values(t_stack *stack, char **argv);
int				find_largest(int *stack, int len);
int				find_smallest(int *stack, int len);
int				is_sorted(int *stack, int len);
int				is_rev_sorted(int *stack, int len);
int				find_ind_max(int *stack_b, int b_len);
int				find_ind_min(int *stack, int len);
void			free_entire_array(int **counts_psrt, int i);
void			free_entire_str_array(char **str);
void 			free_everything(char **str, int *stack);
// void			move_btoa_base_case(int **stacks, int *len, int sub_len);
void			find_mids_a(int *stack, int len, int *sml_bg);
void			find_mids_b(int *stack, int len, int *sml_bg);
// void			find_mids_b_bottom(int *stack, int len, int *sml_bg);
// void			calc_mids(t_list_split *curr, int *sml_bg);
void			insertion_sort(int	*stack_dup, int len);
void			iter_quicksort(int *stack, int *stack_b, int *len);
void			replace_with_rank(int *stack, int len, int *copy);
int				mv_smallest_frm_a(t_stack *stack, t_list_ops *curr, int n);
int				pusha(t_stack *stack, t_list_ops *curr);
int				pushb(t_stack *stack, t_list_ops *curr);
int				push_swap(t_stack *stack);
void			rev_rot(int *stack, int len, t_list_ops *curr, int ab);
void			rr(t_stack *stack, t_list_ops *curr);
void			rrr(t_stack *stack, t_list_ops *curr);
void			rotate(int *stack, int len, t_list_ops *curr, int ab);
void			split_stack(int *stack, int  *stack_b, int *len);
void			sort_stack(t_stack *stack, t_list_ops *curr, int n);
void			sort_stack_b(t_stack *stack, t_list_ops *curr, int n);
void			sorted_return(int *stack, int *stack_b, int *len);
void			swap(t_stack *stack, t_list_ops *curr, int ab);
void			swap_both(t_stack *stack, t_list_ops *curr);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			**ft_split_count(const char *s, char c, int *word_count);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_lstadd_front_ops(t_list_ops **lst, t_list_ops *new);
void			ft_lstadd_back_ops(t_list_ops **lst, t_list_ops *new);
t_list_ops		*ft_lstnew_ops(char *op_type);
int				ft_lstsize_ops(t_list_ops *list);
void			ft_lstclear_ops(t_list_ops *lst);
// void			ft_lstclear_splt(t_list_split **lst);
// int				ft_lstsize_splt(t_list_split *list);
// t_list_split	*ft_lstlast_splt(t_list_split *lst);
// t_list_split	*ft_lstnew_splt(int *sml_bg);
// void			ft_lstadd_front_splt(t_list_split **lst, t_list_split *new);
// void			ft_lstadd_back_splt(t_list_split **lst, t_list_split *new);
// int				ft_lstsize(t_list_split *list);
// void			create_list_split(int *sml_bg, t_list_split **lsts);
void			ft_sort_b(t_stack *stack, t_list_ops *curr, int *counts);
int				*sort_a_base(t_stack *stack, int *sml_bg, int *counts, t_list_ops *curr);
void			sort_a_top(t_stack *stack, t_list_ops *curr, int n);
void			sort_a_btm(t_stack *stack, t_list_ops *curr, int n);
int				*sort_b_base(t_stack *stack, int *sml_bg, int *counts, t_list_ops *curr);
void 			sort_b_btm(t_stack *stack, t_list_ops *curr, int n);
void			sort_b_top(t_stack *stack, t_list_ops *curr, int n);
int				**presort_stack(t_stack *stack, t_list_ops *curr);
void			sort_back(t_stack *stack, t_list_ops *curr, int **counts);
void			print_stack(t_stack *stack, char ab);									// remove this before submission

# endif
