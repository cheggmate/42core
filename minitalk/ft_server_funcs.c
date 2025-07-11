/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:29:57 by jotong            #+#    #+#             */
/*   Updated: 2025/07/11 23:58:30 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft/libft.h"


void	process_other_signals(int s)
{
	if (s == SIGHUP)
		ft_printf("Server hung up.\n");
	else if (s == SIGINT)
		ft_printf("Server interrupted.\n");
	else if (s == SIGQUIT)
		ft_printf("Server quit.\n");
	else if (s == SIGILL)
		ft_printf("Server received an illegal instruction\n");
	else if (s == SIGABRT)
		ft_printf("Server instruction aborted.\n");
	else if (s == SIGFPE)
		ft_printf("Floating point exception occurred.\n"); // floating point exception (divide by zero)
	else if (s == SIGKILL)
		kill(getpid(), 1);
	else if (s == SIGSEGV)
		ft_printf("Server encountered a segmentation fault.\n");
	else if (s == SIGPIPE)
		ft_printf("Broken pipe encountered.\n");
	else if (s == SIGALRM)
		ft_printf("Server timer received.\n");
	else if (s == SIGTERM || s == SIGCHLD)
		ft_printf("Server / process received a termination signal.\n");
	else if (s == SIGCONT)
		ft_printf("Continuing with action..\n"); // continue (if stoppped)
	else if (s == SIGSTOP || s == SIGTSTP)
		ft_printf("Process stopped.\n");
}

void	process_sigusr(int s)
{
	if (s == SIGUSR1)
	{
		printf("SIGUSR1 received!\n");
		word->sig_char <<= 1;
	}
	else if (s == SIGUSR2)
	{
		printf("SIGUSR2 received!\n");
		word->sig_char <<= 0;
	}
	word->b_count+= 1;
	if (word->b_count == 8)
	{
		word->sig_wrd[word->sig_wrd_len] = word->sig_char;
		ft_printf("sig_wrd = %s\n", word->sig_wrd);
		word->sig_wrd_len += 1;
		if (word->sig_char == '\0')
		{
			ft_printf("%c", word->sig_wrd);
			ft_bzero(word->sig_wrd, word->sig_wrd_len);
			word->sig_wrd_len = 0;
		}
		word->sig_char = 0;
		word->b_count = 0;
	}
}

