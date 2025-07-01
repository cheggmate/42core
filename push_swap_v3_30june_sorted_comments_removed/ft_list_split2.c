/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_split2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:00:29 by jotong            #+#    #+#             */
/*   Updated: 2025/07/01 21:26:46 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// void	ft_lstadd_front_split(t_list_split **lst, t_list_split *new)
// {
// 	new -> next = *lst;
// 	*lst = new;
// }

// void	ft_lstadd_back_splt(t_list_split **lst, t_list_split *new)
// {
// 	t_list_split	*curr;

// 	if (!(!lst || !new))
// 	{
// 		if (!*lst)
// 			*lst = new;
// 		else
// 		{
// 			curr = *lst;
// 			while (curr->next)
// 				curr = curr->next;
// 			curr->next = new;
// 		}
// 	}
// }

// void	create_list_split(int *sml_bg, t_list_split **lsts)
// {
// 	if (lsts[0] == NULL)
// 		lsts[0] = ft_lstnew_splt(sml_bg);
// 	else
// 	{
// 		lsts[1] = ft_lstnew_splt(sml_bg);
// 		ft_lstadd_back_splt(&lsts[0], lsts[1]);
// 	}
// }

// int	ft_lstsize(t_list_split *list)
// {
// 	int				count;
// 	t_list_split	*curr;

// 	count = 0;
// 	curr = list;
// 	while (curr)
// 	{
// 		count++;
// 		curr = curr -> next;
// 	}
// 	return (count);
// }

// int	is_in_range(int	*stack, int len, t_list_split *curr)
// {
// 	if ((stack[len - 1] > curr->start && stack[len - 1] < curr->end) || \
// 		(stack[0] > curr->start && stack[0] < curr->end))
// 		return (1);
// 	else
// 		return (0);
// }
