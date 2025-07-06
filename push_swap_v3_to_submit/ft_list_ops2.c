/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ops2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:17:15 by jotong            #+#    #+#             */
/*   Updated: 2025/07/05 22:30:00 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list_ops	*del_two_and_replace(t_list_ops *del1, t_list_ops *del2,
	char *op_type, int length)
{
	t_list_ops	*new;
	t_list_ops	*prev;
	t_list_ops	*nxt;

	new = ft_lstnew_ops(op_type, length);
	if (new)
	{
		prev = del1->before;
		nxt = del1->next;
		ft_lst_delone(&del1);
		new->before = prev;
		new->next = nxt;
		prev->next = new;
		nxt->before = new;
		ft_lst_delone(&del2);
	}
	return (new);
}
