/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:05:07 by jotong            #+#    #+#             */
/*   Updated: 2025/07/11 23:50:48 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft/libft.h"

void	send_null_terminator(pid_t s_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(s_pid, SIGUSR2);
		i++;
	}
}


void	send_signal(pid_t s_pid, char *sig)
{
	int	i;
	int	s_bit;
	int	s_len;

	s_len = ft_strlen(sig);
	ft_printf("start sending\n");
	while (s_len--)
	{
		i = 7;
		s_bit = *sig;
		while (i >= 0)
		{
			if (((s_bit >> i) & 1) == 1)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			usleep(100);
			ft_printf("sent bit no '%d'\n", i);
			i--;
		}
		sig++;
	}
	send_null_terminator(s_pid);
	
}
