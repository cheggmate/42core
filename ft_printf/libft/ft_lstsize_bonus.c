/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:45:15 by jotong            #+#    #+#             */
/*   Updated: 2025/05/17 23:54:40 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int		count;
	t_list	*curr;

	count = 0;
	curr = list;
	while (curr)
	{
		count++;
		curr = curr -> next;
	}
	return (count);
}
