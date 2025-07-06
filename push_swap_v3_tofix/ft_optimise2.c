/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimise2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:33:52 by jotong            #+#    #+#             */
/*   Updated: 2025/07/07 00:48:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	cancel_ra_rra(t_list_ops *curr)
{
	int			changed;
	t_list_ops	*to_delete;

	changed = 0;
	if (!curr || !(curr->next))
		return (-1);
	while (curr->next)
	{
		if ((ft_strncmp(curr->op_type, "ra\n", 3) == 0
				&& ft_strncmp(curr->next->op_type, "rra\n", 4) == 0)
			|| (ft_strncmp(curr->op_type, "rra\n", 4) == 0
				&& ft_strncmp(curr->next->op_type, "ra\n", 3) == 0))
		{
			to_delete = curr;
			curr = curr->next;
			ft_lst_delone(&to_delete);
			to_delete = curr;
			curr = curr->next;
			ft_lst_delone(&to_delete);
			changed = 1;
		}
		curr = curr->next;
	}
	return (changed);
}

int	cancel_pa_pb(t_list_ops *curr)
{
	int			changed;
	t_list_ops	*to_delete;

	changed = 0;
	while (curr->next)
	{
		if ((ft_strncmp(curr->op_type, "pa\n", 3) == 0
				&& ft_strncmp(curr->next->op_type, "pb\n", 3) == 0)
			|| (ft_strncmp(curr->op_type, "pb\n", 3) == 0
				&& ft_strncmp(curr->next->op_type, "pa\n", 3) == 0))
		{
			to_delete = curr;
			curr = curr->next;
			ft_lst_delone (&to_delete);
			to_delete = curr;
			curr = curr->next;
			ft_lst_delone (&to_delete);
			changed = 1;
		}
		curr = curr->next;
	}
	return (changed);
}

int	cancel_rb_rrb(t_list_ops *curr)
{
	int			changed;
	t_list_ops	*to_delete;

	changed = 0;
	if (!curr || !(curr->next))
		return (-1);
	while (curr->next)
	{
		if ((ft_strncmp(curr->op_type, "rb\n", 3) == 0
				&& ft_strncmp(curr->next->op_type, "rrb\n", 4) == 0)
			|| (ft_strncmp(curr->op_type, "rrb\n", 4) == 0
				&& ft_strncmp(curr->next->op_type, "rb\n", 3) == 0))
		{
			to_delete = curr;
			curr = curr->next;
			ft_lst_delone(&to_delete);
			to_delete = curr;
			curr = curr->next;
			ft_lst_delone(&to_delete);
			changed = 1;
		}
		curr = curr->next;
	}
	return (changed);
}

int	opt_checker(t_list_ops *frnt, t_list_ops *bk, char	*op1, char *op2)
{
	if (!frnt || !bk || !frnt->op_type || !bk->op_type)
		return (0);
	else if ((ft_strncmp(frnt->op_type, op1, ft_strlen(op1)) == 0
			&& ft_strncmp(bk->op_type, op2, ft_strlen(op2)) == 0)
		|| (ft_strncmp(frnt->op_type, op2, ft_strlen(op2)) == 0
			&& ft_strncmp(bk->op_type, op1, ft_strlen(op1)) == 0))
		return (1);
	else
		return (0);
}

int	cancel_out_chks(t_list_ops *head)
{
	t_list_ops	*head_tmp1;
	t_list_ops	*head_tmp2;
	t_list_ops	*head_tmp3;
	int			changed;

	head_tmp1 = head->next;
	head_tmp2 = head->next;
	head_tmp3 = head->next;
	changed = 0;
	while (head_tmp1 && (cancel_ra_rra(head_tmp1) == 1
			|| cancel_rb_rrb(head_tmp2) == 1 || cancel_pa_pb(head_tmp3) == 1))
	{
		head_tmp1 = head->next;
		head_tmp2 = head->next;
		head_tmp3 = head->next;
		changed = 1;
	}
	return (changed);
}
