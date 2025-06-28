/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:04:00 by jotong            #+#    #+#             */
/*   Updated: 2025/06/18 22:26:41 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list_split	*ft_lstnew_splt(int *sml_bg)
{
	t_list_split	*new;

	new = malloc(sizeof(t_list_split));
	if (!new)
		return (NULL);
	else
	{
		new->start = sml_bg[2];
		new->end = sml_bg[3];
		new->smlr = sml_bg[0];
		new->bgr = sml_bg[1];
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
