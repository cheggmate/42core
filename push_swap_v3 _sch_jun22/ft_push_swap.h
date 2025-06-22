/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:21:45 by jotong            #+#    #+#             */
/*   Updated: 2025/06/23 00:29:53 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list_ops
{
	int					*op_type;
	struct s_list_ops	*next;
}					t_list_ops;

typedef struct s_list_split
{
	int					start;
	int					end;
	int					smlr;
	int					bgr;
	struct s_list_split	*next;
}					t_list_split;

int				ft_arr_len(int	*str);
int				find_pos(int *str, int val, int len);
int				is_num(char *str);
int				*ft_arr_dup(int *stack, int len);
int				check_order(int len, int *stack);
int				check_dups(int	*stack, int len);
int				prep_string(int len, char **str, int *stack);
int				prep_values(int len, int *stack, char **argv);
int				find_largest(int *stack, int len);
int				find_smallest(int *stack, int len);
int				is_sorted(int *stack, int len);
int				find_ind_max(int *stack_b, int b_len);
void			move_btoa_base_case(int **stacks, int *len, int sub_len);
void			find_mids_a(int *stack, int len, int *sml_bg);
void			find_mids_b(int *stack, int len, int *sml_bg);
// void			find_mids_b_bottom(int *stack, int len, int *sml_bg);
void			calc_mids(t_list_split *curr, int *sml_bg);
void			insertion_sort(int	*stack_dup, int len);
void			iter_quicksort(int *stack, int *stack_b, int *len);
void			replace_with_rank(int *stack, int len, int *copy);
void			mv_smallest_frm_a(int **stacks, int *len);
int				pusha(int	*stack_dest, int *stack_src, int *len);
int				pushb(int	*stack_dest, int *stack_src, int *len);
int				push_swap(int *stack, int *len);
void			rev_rot(int *stack, int *len, int ab);
void			rr(int	*stack_a, int *stack_b, int *len);
void			rrr(int	*stack_a, int *stack_b, int *len);
void			rotate(int *stack, int *len, int ab);
void			start_chunking(int *stack, int *stack_b, int *len);
void			chunk_optmzns(int *stack, int *stack_b, int *len);
void			split_stack(int *stack, int  *stack_b, int *len);
void			sort_stack(int *stack, int *len, int n);
void			sort_stack_b(int *stack_b, int *len, int n);
void			sorted_return(int *stack, int *stack_b, int *len);
void			swap(int	*stack, int *len, int ab);
void			swap_both(int *stack_a, int *stack_b, int *len);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			**ft_split_count(const char *s, char c, int *word_count);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_lstadd_front_ops(t_list_ops **lst, t_list_ops *new);
void			ft_lstadd_back_ops(t_list_ops **lst, t_list_ops *new);
t_list_ops		*ft_lstnew_ops(int *op_type);
int				ft_lstsize_ops(t_list_ops *list);
void			ft_lstclear_ops(t_list_split **lst);
void			ft_lstclear_splt(t_list_split **lst);
int				ft_lstsize_splt(t_list_split *list);
t_list_split	*ft_lstlast_splt(t_list_split *lst);
t_list_split	*ft_lstnew_splt(int *sml_bg);
void			ft_lstadd_front_splt(t_list_split **lst, t_list_split *new);
void			ft_lstadd_back_splt(t_list_split **lst, t_list_split *new);
int				ft_lstsize(t_list_split *list);
void			create_list_split(int *sml_bg, t_list_split **lsts);
// int				is_in_range(int	*stack, int len, t_list_split *curr);
// void			ft_sort_a(int **stacks, int *len, int *counts, int iter);		// remove iter
void			ft_sort_b(int **stacks, int *len, int *counts, int iter);		// remove iter
void			sort_a_base(int **stacks, int *len, int *sml_bg, int *counts);
void			sort_a_top(int **stacks, int *len, int n, int iter);
void			sort_a_btm(int **stacks, int *len, int n, int iter);
void			sort_b_base(int **stacks, int *len, int *sml_bg, int *counts);
void 			sort_b_btm(int **stacks, int *len, int n, int iter);
void			sort_b_top(int **stacks, int *len, int n, int iter);
int				*presort_stack(int **stacks, int *len, int n, int iter);
void			print_stack(int	*s, int *len, char ab);									// remove this before submission

# endif
