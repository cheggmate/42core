/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:27:06 by jotong            #+#    #+#             */
/*   Updated: 2025/07/20 18:39:01 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

t_pool	*init_mem_pool(size_t size)
{
	t_pool	*mem_p;

	mem_p = ft_calloc(1, sizeof(t_pool));
	if (!mem_p)
	{
		printf("error initialising mem_p\n");
		return (NULL);
	}

	mem_p->head = ft_calloc(size, sizeof(char));
	if (!mem_p->head)
	{
		printf("error initialising mem_p->head\n");
		return (NULL);
	}
	mem_p->total = size;
	mem_p->used = 0;
	return (mem_p);
}

void	*alloc_mem(t_pool *mem_p, size_t size)
{
	void	*sub_pool;

	sub_pool = NULL;
	if (!mem_p || !mem_p->head)
	{
		printf("mem head NULL\n");
		return (NULL);
	}
		
	if (mem_p->used + size > mem_p->total)
	{
		printf("mem overflow\n");
		return (NULL);
	}
		
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

void	free_and_exit(t_pool *mem_p, int *fd, int status)
{
	free_pool(mem_p);
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
	if (status == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
