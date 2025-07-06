/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:58:03 by jotong            #+#    #+#             */
/*   Updated: 2025/07/07 00:56:58 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	replace_sasb_ss(t_list_ops *c, t_list_ops *bk_op)
{
	if (!c || !(c->next))
		return (-1);
	while (c->next)
	{
		if (ft_strncmp(c->op_type, "sa\n", 3) == 0
			|| ft_strncmp(c->op_type, "sb\n", 3) == 0)
		{
			bk_op = c->next;
			while (bk_op->next)
			{
				if (ft_strncmp(bk_op->op_type, "ss\n", 3) == 0)
				{
					bk_op = bk_op->next;
					continue ;
				}
				else if (opt_checker(c, bk_op, "sa\n", "sb\n"))
				{
					bk_op = del_two_and_replace(c, bk_op, "ss\n", c->len);
					return (1);
				}
				else
					break ;
				bk_op = bk_op->next;
			}
		}
		c = c->next;
	}
	return (0);
}

static int	replace_rarb_rr(t_list_ops *curr, t_list_ops *bk_op)
{
	if (!curr || !(curr->next))
		return (-1);
	while (curr && curr->next)
	{
		bk_op = curr->next;
		if ((ft_strncmp (curr->op_type, "ra\n", 3) == 0
				&& ft_strncmp (bk_op->op_type, "rb\n", 3) == 0)
			|| (ft_strncmp (curr->op_type, "rb\n", 3) == 0
				&& ft_strncmp (bk_op->op_type, "ra\n", 3) == 0))
		{
			bk_op = del_two_and_replace(curr, bk_op, "rr\n", curr->len);
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

static int	replace_rrarrb_rrr(t_list_ops *c, t_list_ops *bk_op)
{
	if (!c || !c->next)
		return (-1);
	while (c->next)
	{
		if (ft_strncmp(c->op_type, "rra\n", 4) == 0
			|| ft_strncmp(c->op_type, "rrb\n", 4) == 0)
		{
			bk_op = c->next;
			while (bk_op && bk_op->next)
			{
				if (ft_strncmp (bk_op->op_type, "rrr\n", 4) == 0)
					bk_op = bk_op->next;
				else if (opt_checker(c, bk_op, "rra\n", "rrb\n"))
				{
					bk_op = del_two_and_replace(c, bk_op, "rrr\n", c->len);
					bk_op = bk_op->next;
					return (1);
				}
				else
					break ;
			}
		}
		c = c->next;
	}
	return (0);
}

void	optimise_list(t_list_ops *head)
{
	t_list_ops	*head_tmp;
	t_list_ops	*head_tmp1;
	t_list_ops	*head_tmp2;
	t_list_ops	*head_tmp3;
	t_list_ops	*bk_op;

	bk_op = NULL;
	head_tmp = head->next;
	head_tmp1 = head->next;
	head_tmp2 = head->next;
	head_tmp3 = head->next;
	while (head_tmp && (cancel_out_chks (head_tmp) == 1
			|| replace_sasb_ss (head_tmp1, bk_op) == 1
			|| replace_rarb_rr (head_tmp2, bk_op) == 1
			|| replace_rrarrb_rrr (head_tmp3, bk_op) == 1))
	{
		head_tmp = head->next;
		head_tmp1 = head->next;
		head_tmp2 = head->next;
		head_tmp3 = head->next;
	}
}
