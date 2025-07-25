/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:29:17 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 14:42:02 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# define _GNU_SOURCE
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

typedef struct s_word
{
	int				b_count;
	unsigned char	sig_char;
}				t_word;

extern t_word	*g_word;

void	process_sigusr(int s, pid_t c_pid);
void	process_other_signals(int s);
void	send_server_signal(pid_t c_pid, char *sig);
void	free_gword_bonus(void);

#endif