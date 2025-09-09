/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:50:38 by jotong            #+#    #+#             */
/*   Updated: 2025/08/28 18:20:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_tab *tab)
{
	int			num;
	int			i;
	int			result;

	i = -1;
	result = 0;
	if (!tab)
		return (-1);
	num = tab->p_total;
	while (++i < num)
	{
		result = pthread_create(&tab->threads[i], NULL, keep_philos_alive, &tab->phils[i]);
		if (result != 0)
		{
			printf("failed to create thread %d\n", i);
			return (-1);
		}
	}
	// printf("%d threads created \n", i);
	result = pthread_create(&tab->threads[num], NULL, monitoring, tab);
		if (result != 0)
			return (-1);
	return (0);	
}

int	join_threads(t_tab *tab)
{
	int	i;

	i = -1;
	// printf("p_total = %d\n", tab->p_total);
	while(tab->eat_count != 0 && ++i < tab->p_total)
		pthread_join(tab->threads[i], NULL);
	// printf("i is %d\n", i);
	// printf("joining monitoring thread\n");
	pthread_join(tab->threads[tab->p_total], NULL);
	// printf("joined monitoring thread\n");
	return (0);
}

void	bar_init(t_bar *s_block, int count)
{
	pthread_mutex_init(&s_block->mutex, NULL);
	pthread_cond_init(&s_block->cond, NULL);
	s_block->count = 0;
	s_block->total = count;
	s_block->generation = 0;
}

void bar_wait(t_bar *b) {
    pthread_mutex_lock(&b->mutex);

    int gen = b->generation;

    b->count++;
    if (b->count == b->total) {
        b->generation++;
        b->count = 0;
        pthread_cond_broadcast(&b->cond);
    } else {
        while (gen == b->generation) {
            pthread_cond_wait(&b->cond, &b->mutex);
        }
    }

    pthread_mutex_unlock(&b->mutex);
}
