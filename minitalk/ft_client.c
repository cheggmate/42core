/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:28:02 by jotong            #+#    #+#             */
/*   Updated: 2025/07/11 23:33:33 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	pid_t		s_pid;
	char		*sig;
	
	if (argc != 3)
	{
		ft_printf("Wrong number of arguments!\n");
		return (1);
	}
	s_pid = ft_atoi(argv[1]);
	ft_printf("s_pid is %d\n", s_pid);
	sig = argv[2];
	// if (!(sig >= 1 && sig <= 22))
	// {
	// 	ft_printf("Invalid signal sent\n");
	// 	return (1);
	// }
	send_signal(s_pid, sig);
	ft_printf("signal sent!\n");
	return (0);	
}
