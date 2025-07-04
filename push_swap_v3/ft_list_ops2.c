/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ops2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:17:15 by jotong            #+#    #+#             */
/*   Updated: 2025/07/02 20:01:23 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list_ops	*del_two_and_replace(t_list_ops *del1, t_list_ops *del2, \
	char *op_type, int length)
{
	t_list_ops	*new;
	t_list_ops	*prev;
	t_list_ops	*to_delete;

	new = ft_lstnew_ops(op_type, length);
	if (new)
	{
		new->next = del1->next->next;
		new->before = del1->before;
		prev = del1->before;
		prev->next = new;
		to_delete = del1;
		ft_lst_delone(&to_delete);
		to_delete = del2;
		ft_lst_delone(&to_delete);
		del1 = new;
	}
	return (new);
}

