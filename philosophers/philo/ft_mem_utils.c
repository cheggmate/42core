/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:07:20 by jotong            #+#    #+#             */
/*   Updated: 2025/07/29 23:43:27 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// t_pool	*init_mem_pool(size_t size)
// {
// 	t_pool	*mem_p;

// 	mem_p = ft_calloc(1, sizeof(t_pool));
// 	if (!mem_p)
// 	{
// 		printf("Failed to initialise mem_p\n");
// 		return (NULL);
// 	}
// 	mem_p->head = ft_calloc(size, sizeof(char));
// 	if (!mem_p->head)
// 	{
// 		printf("Failed to initialise mem_p->head\n");
// 		return (NULL);
// 	}
// 	mem_p->total = size;
// 	mem_p->used = 0;
// 	return (mem_p);
// }

// void	*alloc_mem(t_pool *mem_p, size_t size)
// {
// 	void	*sub_pool;

// 	sub_pool = NULL;
// 	if (!mem_p || !mem_p->head)
// 		return (NULL);
// 	if (mem_p->used + size > mem_p->total)
// 	{
// 		printf("Mem overflow\n");
// 		return (NULL);
// 	}
// 	sub_pool = mem_p->head + mem_p->used;
// 	mem_p->used += size;
// 	return (sub_pool);
// }

// void	free_pool(t_pool *mem_p)
// {
// 	if (mem_p->head)
// 	{
// 		free(mem_p->head);
// 		mem_p->head = NULL;
// 	}
// 	free(mem_p);
// 	mem_p = NULL;
// }

// void	free_everything(t_pool *mem_p, t_tab **tab)
// {
// 	free_pool(mem_p);
// 	(*tab)->forks = NULL;
// 	(*tab)->phils = NULL;
// 	(*tab) = NULL;
// }

void free_everything(t_tab **tab)
{
	if (!tab)
		return ;
	if ((*tab)->forks)
	{
		destroy_forks((*tab)->forks);
		free((*tab)->forks);
	}
	if((*tab)->phils)
	{
		close_threads(tab);
		free((*tab)->phils);
	}
	free((*tab)->threads);
	free((*tab));
	(*tab)->forks = NULL;
	(*tab)->phils = NULL;
	*tab = NULL;
}
