/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:28:02 by jotong            #+#    #+#             */
/*   Updated: 2025/07/15 17:16:45 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	pid_t		s_pid;
	int			i;

	i = 2;
	if (argc <= 2)
		return (write(2, "wrong num of args.\n", 20), 1);
	s_pid = ft_atoi(argv[1]);
	if (s_pid < 0 || s_pid > INT_MAX)
		return (write(2, "invalid PID.\n", 14), 1);
	else if (argc >= 3)
	{
		while (i < argc - 1)
		{
			send_signal(s_pid, argv[i]);
			send_signal(s_pid, " ");
			i++;
		}
		send_signal(s_pid, argv[i]);
	}
	return (0);
}
