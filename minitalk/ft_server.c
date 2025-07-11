/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:28:08 by jotong            #+#    #+#             */
/*   Updated: 2025/07/11 23:53:39 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft/libft.h"

t_word	*word;

// allowed functions:
// write
// ft_printf or any equivalent YOU coded
// signal
// sigemptyset
// sigaddset
// sigaction
// kill
// getpid
// malloc
// free
// pause
// sleep
// usleep
// exit

void	sig_processor(int s)
{
	ft_printf("received signal %d\n", s);
	if (s == SIGUSR1 || s == SIGUSR2)
		process_sigusr(s);
	else
		process_other_signals(s);
	ft_printf("b_count = %d\n", word->b_count);
}

int	main(void)
{
	pid_t			s_pid;
	// int		*sig;

	word = (t_word *)malloc(sizeof(t_word));
	word->b_count = 0;
	word->sig_char = 0;
	word->sig_wrd[0] = '\0';
	word->sig_wrd_len = 0;
	s_pid = getpid();
	ft_printf("PID of this server: %d\n", s_pid);
	ft_printf("Hello world\n");

	ft_printf("Waiting for signal....\n");
	signal(SIGUSR1, sig_processor);
	signal(SIGUSR2, sig_processor);

	while (1)
	{
		pause() ;
	}
	
	return (0);
}
