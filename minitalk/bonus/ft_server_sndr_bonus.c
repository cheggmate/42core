/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_sndr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:29:09 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 12:34:44 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"
#include "libft.h"

static void	send_server_null_terminator(pid_t c_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(c_pid, SIGUSR2);
		i++;
		usleep(400);
	}
}

static void	send_server_character(pid_t c_pid, char sig)
{
	int	i;
	int	s_bit;

	i = 7;
	s_bit = sig;
	while (i >= 0)
	{
		if (((s_bit >> i) & 1) == 1)
			kill(c_pid, SIGUSR1);
		else
			kill(c_pid, SIGUSR2);
		usleep(400);
		i--;
	}
}

void	send_server_signal(pid_t c_pid, char *sig)
{
	int					i;
	unsigned int		s_bit;
	int					s_len;

	s_len = ft_strlen(sig);
	while (s_len--)
	{
		i = 7;
		s_bit = *sig;
		send_server_character(c_pid, *sig);
		sig++;
	}
	send_server_null_terminator(c_pid);
}
