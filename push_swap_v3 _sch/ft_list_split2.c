/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_split2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:00:29 by jotong            #+#    #+#             */
/*   Updated: 2025/06/17 23:53:05 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lstadd_front_split(t_list_split **lst, t_list_split *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ft_lstadd_back_splt(t_list_split **lst, t_list_split *new)
{
	t_list_split	*curr;

	if (!(!lst || !new))
	{
		if (!*lst)
			*lst = new;
		else
		{
			curr = *lst;
			while (curr->next)
				curr = curr->next;
			curr->next = new;
		}
	}
}
