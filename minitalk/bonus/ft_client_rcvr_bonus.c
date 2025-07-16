/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_rcvr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:22:33 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 13:25:34 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#include "libft.h"

static void	free_gword_ack(void)
{
	if (g_word_ack)
		free(g_word_ack);
}

void	process_other_signals(int s)
{
	if (s == SIGHUP || s == SIGQUIT)
		ft_printf("Server hung up / quit. \n");
	else if (s == SIGILL || s == SIGABRT)
		ft_printf("Server received an illegal instruction/ aborted\n");
	else if (s == SIGFPE)
		ft_printf("Floating point exception occurred.\n");
	else if (s == SIGKILL)
		kill(getpid(), 1);
	else if (s == SIGSEGV)
		ft_printf("Server encountered a segmentation fault.\n");
	else if (s == SIGPIPE)
		ft_printf("Broken pipe encountered.\n");
	else if (s == SIGALRM)
		ft_printf("Server timer received.\n");
	else if (s == SIGTERM || s == SIGCHLD || s == SIGINT)
	{
		free_gword_ack();
		ft_printf("Server / process received a termination signal.\n");
	}
	else if (s == SIGCONT)
		ft_printf("Continuing with action.\n");
	else if (s == SIGSTOP || s == SIGTSTP)
		ft_printf("Process stopped.\n");
}

void	process_cli_sigusr(int s)
{
	if (s == SIGUSR1)
	{
		g_word_ack->sig_char <<= 1;
		g_word_ack->sig_char |= 1;
	}
	else if (s == SIGUSR2)
	{
		g_word_ack->sig_char <<= 1;
	}
	g_word_ack->b_count += 1;
	if (g_word_ack->b_count == 8)
	{
		write(1, &g_word_ack->sig_char, 1);
		g_word_ack->sig_char = 0;
		g_word_ack->b_count = 0;
	}
}

void	cli_sig_processor(int s)
{
	if (s == SIGUSR1 || s == SIGUSR2)
		process_cli_sigusr(s);
}
