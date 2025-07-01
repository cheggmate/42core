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

void	ft_lstadd_front_ops(t_list_ops **lst, t_list_ops *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ft_lstadd_back_ops(t_list_ops **lst, t_list_ops *new)
{
	t_list_ops	*curr;

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

t_list_ops	*ft_lstnew_ops(char *op_type)
{
	t_list_ops	*new;

	new = malloc(sizeof(t_list_ops));
	if (!new)
		return (NULL);
	else
	{
		new->op_type = op_type;
		new->next = NULL;
		return (new);
	}
}

// t_list_ops	*ft_lstlast(t_list_ops *lst)
// {
// 	t_list_ops	*curr;

// 	if (!lst)
// 		return (NULL);
// 	curr = lst;
// 	while (curr->next)
// 	{
// 		curr = curr -> next;
// 	}
// 	return (curr);
// }

int	ft_lstsize_ops(t_list_ops *list)
{
	int				count;
	t_list_ops	*curr;

	count = 0;
	curr = list;
	while (curr)
	{
		count++;
		curr = curr -> next;
	}
	return (count);
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
