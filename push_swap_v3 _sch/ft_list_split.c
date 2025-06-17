/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:04:00 by jotong            #+#    #+#             */
/*   Updated: 2025/06/17 23:46:05 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list_split	*ft_lstnew_splt(int start, int end)
{
	t_list_split	*new;

	new = malloc(sizeof(t_list_split));
	if (!new)
		return (NULL);
	else
	{
		new->start = start;
		new->end = end;
		new->next = NULL;
		return (new);
	}
}

t_list_split	*ft_lstlast_splt(t_list_split *lst)
{
	t_list_split	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next)
	{
		curr = curr -> next;
	}
	return (curr);
}

int	ft_lstsize_splt(t_list_split *list)
{
	int				count;
	t_list_split	*curr;

	count = 0;
	curr = list;
	while (curr)
	{
		count++;
		curr = curr -> next;
	}
	return (count);
}

static void	ft_lstdelone_splt(t_list_split *lst)
{
	free(lst);
}

void	ft_lstclear_splt(t_list_split **lst)
{
	t_list_split	*curr;
	t_list_split	*succ;

	curr = *lst;
	while (curr -> next)
	{
		succ = curr -> next;
		ft_lstdelone_splt(curr);
		curr = succ;
	}
	ft_lstdelone_splt(curr);
	*lst = NULL;
}
