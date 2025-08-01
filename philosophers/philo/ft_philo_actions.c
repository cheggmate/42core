/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:27:11 by jotong            #+#    #+#             */
/*   Updated: 2025/08/01 23:52:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	let_philo_eat(t_phil *phil)
{
	pick_up_frks(phil);
	usleep(phil->tab->t_eat);
	put_down_frks(phil);
	phil->t_last_ate = get_time();
	phil->eat_count += 1;
}

int	let_philo_sleep(t_phil *phil)
{
	usleep(phil->tab->t_slp);
}

int	let_philo_think(t_phil *phil)
{
	
}
