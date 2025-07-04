/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:58:03 by jotong            #+#    #+#             */
/*   Updated: 2025/07/04 17:28:57 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


static int	replace_sasb_ss(t_list_ops *curr)
{
	int			changed;
	t_list_ops	*front_op;
	t_list_ops	*back_op;

	changed = 0;
	while (curr->next)
	{
		/*if (ft_strncmp(curr->op_type, "sa\n", 3) == 0 && \
		ft_strncmp(curr->next->op_type, "sb\n", 3) == 0)*/
		if (opt_checker(curr, curr->next, "sa\n", "sb\n"))
		{
			front_op = curr;
			back_op = curr->next;
			while (back_op->next)
			{
				if (ft_strncmp(back_op->op_type, "ss\n", 3) == 0)
					continue;
				else if (opt_checker(front_op, back_op, "sa\n", "sb\n"))
				{
					back_op = del_two_and_replace(front_op, back_op, "ss\n", front_op->len);
					changed = 1;
				}
				back_op = back_op->next;
			}
		}
		curr = curr->next;
	}
	return (changed);
}

static int	replace_rarb_rr(t_list_ops *curr)
{
	int			changed;
	t_list_ops	*front_op;
	t_list_ops	*back_op;

	changed = 0;
	if (!curr || !curr->next)
		return (0);
	while (curr && curr->next)
	{
		if (opt_checker(curr, curr->next, "ra\n", "rb\n"))
		{
			front_op = curr;
			back_op = curr->next;
			while (back_op->next)
			{
				if (ft_strncmp(back_op->op_type, "rr\n", 3) == 0)
					continue;
				else if (opt_checker(front_op, back_op, "ra\n", "rb\n"))
				{
					back_op = del_two_and_replace(front_op, back_op, "rr\n", front_op->len);
					changed = 1;
				}
				back_op = back_op->next;
			}
		}
		curr = curr->next;
	}
	return (changed);
}

static int	replace_rrarrb_rrr(t_list_ops *curr)
{
	int			changed;
	t_list_ops	*front_op;
	t_list_ops	*back_op;
	
	changed = 0;
	if (!curr || !curr->next)
		return (0);
	while (curr->next)
	{
		if (opt_checker(curr, curr->next, "rra\n", "rrb\n"))
		{
			front_op = curr;
			back_op = curr->next;
			while (back_op->next)
			{
				if (ft_strncmp(back_op->op_type, "rrr\n", 4) == 0)
					continue;
				else if(opt_checker(front_op, back_op, "rra\n", "rrb\n"))
				{
					back_op = del_two_and_replace(front_op, back_op, "rrr\n", front_op->len);
					changed = 1;
				}
				back_op = back_op->next;
			}
		}
		curr = curr->next;
	}
	return (changed);
}

void	optimise_list(t_list_ops *head)
{
	t_list_ops	*head_tmp;
	t_list_ops	*head_tmp1;
	t_list_ops	*head_tmp2;
	t_list_ops	*head_tmp3;

	head_tmp = head->next;
	head_tmp1 = head->next;
	head_tmp2 = head->next;
	head_tmp3 = head->next;
	while (head_tmp && (cancel_out_chks(head_tmp) == 1 \
		|| replace_sasb_ss(head_tmp1) == 1 || replace_rarb_rr(head_tmp3) == 1 \
		|| replace_rrarrb_rrr(head_tmp2) == 1 ))
	{
		head_tmp = head->next;
		head_tmp1 = head->next;
		head_tmp2 = head->next;
		head_tmp3 = head->next;
	}
}
