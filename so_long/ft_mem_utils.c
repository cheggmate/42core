/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:27:06 by jotong            #+#    #+#             */
/*   Updated: 2025/07/19 00:27:28 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

t_pool	*init_mem_pool(size_t size)
{
	t_pool	*mem_p;

	mem_p = ft_calloc(1, sizeof(t_pool));
	mem_p->head = ft_calloc(size, sizeof(char));
	mem_p->total = size;
	mem_p->used = 0;
	return (mem_p);
}

void	*alloc_mem(t_pool *mem_p, size_t size)
{
	void	*sub_pool;

	sub_pool = NULL;
	if (mem_p->used + size > mem_p->total)
		return (NULL);
	sub_pool = mem_p->head + mem_p->used;
	mem_p->used += size;
	return(sub_pool);
}

void	free_pool(t_pool *mem_p)
{
	if (mem_p->head)
		free(mem_p->head);
	free(mem_p);
}

void	free_end_exit(t_pool *mem_p, int status)
{
	free_poo(mem_p);
	if (status == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
