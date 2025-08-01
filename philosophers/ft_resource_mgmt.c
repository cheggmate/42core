/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource_mgmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:53:16 by jotong            #+#    #+#             */
/*   Updated: 2025/08/01 22:15:04 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	updt_frk(pthread_mutex_t *thrd, size_t i, unsigned char *act)
{
	int	result;

	result = pthread_mutex_lock(&thrd);
	// if this returns an error?
	update_fkr_status(i, act);
	pthread_mutex_unlock(&thrd);
}
