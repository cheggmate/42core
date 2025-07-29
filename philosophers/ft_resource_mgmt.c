/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource_mgmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:53:16 by jotong            #+#    #+#             */
/*   Updated: 2025/07/28 22:14:07 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	updt_frk(pthread_mutex_t *thrd, t_frk *frk, size_t i, unsigned char *act)
{
	int	result;

	result = pthread_mutex_lock(&thrd);
	// if this returns an error?
	update_fkr_status(i, act);
	pthread_mutex_unlock(&thrd);
}
