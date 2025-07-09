/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:28:08 by jotong            #+#    #+#             */
/*   Updated: 2025/07/09 23:20:53 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft/libft.h"

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

int	main(int argc, char **argv)
{
	pid_t	s_pid;

	s_pid = getpid();
	ft_printf("PID of this server: %s\n", s_pid);
	
	return (0);
}
