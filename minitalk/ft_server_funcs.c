/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:29:57 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 15:51:27 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft/libft.h"

void	free_gword(void)
{
	if (g_word)
		free(g_word);
	g_word = NULL;
	exit(EXIT_SUCCESS);
}

void	print_bits(unsigned char c)
{
	int				i;
	unsigned char	b;

	i = 7;
	b = c;
	while (i--)
	{
		b = ((c >> i) & 1) + '0';
		write(1, &b, 1);
	}
	write(1, "\n", 1);
}

void	process_other_signals(int s)
{
	if (s == SIGHUP || s == SIGQUIT || s == SIGILL || s == SIGABRT
		|| s == SIGFPE || s == SIGSEGV || s == SIGPIPE || s == SIGTERM
		|| s == SIGCHLD || s == SIGINT || s == SIGTSTP)
	{
		ft_printf("Server hung up / quit. \n");
		free_gword();
	}
	else if (s == SIGALRM)
		ft_printf("Server timer received.\n");
	else if (s == SIGCONT)
		ft_printf("Continuing with action..\n");
}

void	process_sigusr(int s)
{
	if (s == SIGUSR1)
	{
		g_word->sig_char <<= 1;
		g_word->sig_char |= 1;
	}
	else if (s == SIGUSR2)
	{
		g_word->sig_char <<= 1;
	}
	g_word->b_count += 1;
	if (g_word->b_count == 8)
	{
		write(1, &g_word->sig_char, 1);
		g_word->sig_char = 0;
		g_word->b_count = 0;
	}
}
