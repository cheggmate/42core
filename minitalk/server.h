/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:29:17 by jotong            #+#    #+#             */
/*   Updated: 2025/07/11 23:30:07 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/socket.h>

// typedef struct s_sig // this needs to be updated.
// {
// 	sigset_t	s_mask;
	
// }				t_sig;

typedef struct s_word
{
	int				b_count;
	unsigned char	sig_char;
	char			sig_wrd[1024];
	int				sig_wrd_len;
	
}				t_word;

extern t_word	*word;

void	process_sigusr(int s);
void	process_other_signals(int s);
void	sig_processor(int s);


#endif