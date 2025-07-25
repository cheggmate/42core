/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:29:17 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 14:40:04 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
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

void	process_sigusr(int s);
void	process_other_signals(int s);
void	sig_processor(int s);
void	free_gword(void);

#endif