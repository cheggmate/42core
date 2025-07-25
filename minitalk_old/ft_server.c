/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:28:08 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 15:47:49 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft/libft.h"

t_word	*g_word;

void	sig_processor(int s)
{
	if (s == SIGUSR1 || s == SIGUSR2)
		process_sigusr(s);
	else
		process_other_signals(s);
}

int	main(void)
{
	pid_t			s_pid;

	g_word = (t_word *)malloc(sizeof(t_word));
	g_word->b_count = 0;
	g_word->sig_char = 0;
	s_pid = getpid();
	ft_printf("PID of this server: %d\n", s_pid);
	signal(SIGUSR1, sig_processor);
	signal(SIGUSR2, sig_processor);
	while (1)
	{
		pause();
	}
	return (0);
}
