/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:28:08 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 15:48:31 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"
#include "libft.h"

t_word	*g_word;

static void	sig_action_handler(int s, siginfo_t *i, void *c)
{
	ucontext_t	*u_c;
	pid_t		c_pid;

	u_c = (ucontext_t *)c;
	c_pid = i->si_pid;
	if (s == SIGUSR1 || s == SIGUSR2)
		process_sigusr(s, c_pid);
	else
		process_other_signals(s);
}

int	main(void)
{
	pid_t				s_pid;
	struct sigaction	sig_act;

	ft_memset(&sig_act, 0, sizeof(sigaction));
	sig_act.sa_sigaction = sig_action_handler;
	sig_act.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_act.sa_mask);
	g_word = (t_word *)malloc(sizeof(t_word));
	if (!g_word)
		exit(EXIT_FAILURE);
	g_word->b_count = 0;
	g_word->sig_char = 0;
	s_pid = getpid();
	ft_printf("PID of this server: %d\n", s_pid);
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
