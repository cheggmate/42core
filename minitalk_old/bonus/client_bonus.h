/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:31:14 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 17:17:16 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <time.h>

typedef struct s_word_ack
{
	int				b_count;
	unsigned char	sig_char;
}				t_word_ack;

extern t_word_ack	*g_word_ack;

void	send_signal(pid_t s_pid, char *sig);
void	cli_sig_processor(int s);
void	intialise_g_word(void);

#endif