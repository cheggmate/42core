/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_funcs_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:05:07 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 14:04:11 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#include "libft.h"

void	send_null_terminator(pid_t s_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(s_pid, SIGUSR2);
		i++;
		usleep(400);
	}
}

static void	send_cli_character(pid_t s_pid, char sig)
{
	int	i;
	int	s_bit;

	i = 7;
	s_bit = sig;
	while (i >= 0)
	{
		if (((s_bit >> i) & 1) == 1)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		usleep(400);
		i--;
	}
}

void	handle_cli_special_char(pid_t s_pid, char *sig)
{
	sig++;
	if (*sig == 't')
		send_cli_character(s_pid, '\t');
	else if (*sig == 'n')
		send_cli_character(s_pid, '\n');
	else if (*sig == 'v')
		send_cli_character(s_pid, '\v');
	else if (*sig == 'f')
		send_cli_character(s_pid, '\f');
	else if (*sig == 'r')
		send_cli_character(s_pid, '\r');
	else if (*sig == 'b')
		send_cli_character(s_pid, '\b');
	else if (*sig == '\\')
		send_cli_character(s_pid, '\\');
	else
	{
		send_cli_character(s_pid, '\\');
		send_cli_character(s_pid, *sig);
	}
}

void	send_signal(pid_t s_pid, char *sig)
{
	int		s_len;

	s_len = ft_strlen(sig);
	while (s_len--)
	{
		if (*sig == '\\')
		{
			handle_cli_special_char(s_pid, sig);
			sig++;
			s_len--;
		}
		else
			send_cli_character(s_pid, *sig);
		sig++;
	}
	send_null_terminator(s_pid);
}
