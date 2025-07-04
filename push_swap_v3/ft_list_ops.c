/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ops_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:09:29 by jotong            #+#    #+#             */
/*   Updated: 2025/06/17 22:09:43 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lst_delone(t_list_ops **delete)
{
	t_list_ops	*tmp_next;
	t_list_ops	*tmp_before;

	if (!delete || !*delete)
		return ;
	else
	{
		tmp_next = (*delete)->next;
		tmp_before = (*delete)->before;
		if (tmp_before)
			tmp_before->next = tmp_next;
		if (tmp_next)
			tmp_next->before = tmp_before;
		free((*delete));
		(*delete) = tmp_next;
	}
}

void	ft_lstadd_back_ops(t_list_ops *lst, t_list_ops *new)
{
	t_list_ops	*curr;

	if (!(!lst || !new))
	{
		if (!lst)
			lst = new;
		else
		{
			curr = lst;
			while (curr->next)
				curr = curr->next;
			curr->next = new;
			new->before = curr;
		}
	}
}

t_list_ops	*ft_lstnew_ops(char *op_type, int length)
{
	t_list_ops	*new;

	new = malloc(sizeof(t_list_ops));
	if (!new)
		return (NULL);
	else
	{
		new->op_type = op_type;
		new->len = length;
		new->next = NULL;
		new->before = NULL;
		return (new);
	}
}

void	ft_print_lst(t_list_ops *lst)
{
	while (lst->next)
	{
		if (ft_strncmp(lst->op_type, "x", 1) != 0)
			write(1, lst->op_type, ft_strlen(lst->op_type));
		lst = lst->next;
	}
	write(1, lst->op_type, ft_strlen(lst->op_type));
}

void	ft_lstclear_ops(t_list_ops *lst)
{
	t_list_ops	*curr;
	t_list_ops	*succ;

	curr = lst;
	while (curr -> next)
	{
		succ = curr -> next;
		free(curr);
		curr = succ;
	}
	free(curr);
	lst = NULL;
}

