/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:55:34 by jotong            #+#    #+#             */
/*   Updated: 2025/07/28 00:23:38 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_frk(t_tab **tab, t_pool *mem_p)
{
	(*tab)->forks = alloc_mem(mem_p, sizeof(t_frk));
	if (!((*tab)->forks))
	{
		free_everything(mem_p, tab);
		return (1);
	}
	return (0);	
}

static int	init_phil(t_tab **tab, t_pool *mem_p)
{
	(*tab)->phils = alloc_mem(mem_p, sizeof (t_phil));
	if (!init_frk(tab, mem_p) || !((*tab)->phils))
	{
		free_everything(mem_p, tab);
		return (1);
	}
	return (0);
}

int	init_tab(t_tab **tab, t_pool *mem_p)
{
	*tab = alloc_mem(mem_p, sizeof(t_tab));
	if (!init_phil(tab, mem_p) || !(*tab))
	{
		free_everything(mem_p, tab);
		return (1);
	}
	return (0);
}
