/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:28:02 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 17:19:13 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#include "../libft/libft.h"

t_word_ack	*g_word_ack;

void	intialise_g_word(void)
{
	g_word_ack = (t_word_ack *)malloc(sizeof(t_word_ack));
	if (!g_word_ack)
		exit(EXIT_FAILURE);
	g_word_ack->b_count = 0;
	g_word_ack->sig_char = 0;
}

int	main(int argc, char **argv)
{
	pid_t		s_pid;
	int			i;

	i = 2;
	signal(SIGUSR1, cli_sig_processor);
	signal(SIGUSR2, cli_sig_processor);
	if (argc <= 2)
		return (write(2, "wrong num of args.\n", 20), 1);
	s_pid = ft_atoi(argv[1]);
	if (s_pid < 0 || s_pid > INT_MAX)
		return (write(2, "invalid PID.\n", 14), 1);
	intialise_g_word();
	while (i < argc - 1)
	{
		send_signal(s_pid, argv[i]);
		send_signal(s_pid, " ");
		i++;
	}
	send_signal(s_pid, argv[i]);
	while (1)
		pause();
	return (0);
}
