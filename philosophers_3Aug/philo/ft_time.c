/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:20:47 by jotong            #+#    #+#             */
/*   Updated: 2025/08/02 19:39:31 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	now;
	long long		curr;

	curr = 0;
	gettimeofday(&now, NULL);
	curr = now.tv_sec * 1000;
	curr += now.tv_sec / 1000;
	return (curr);
}
