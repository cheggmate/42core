/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:40:24 by jotong            #+#    #+#             */
/*   Updated: 2025/05/25 20:02:45 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		read_b;
	char		*buf;
	ssize_t		b_total;
	
	b_total = 0;
	if (!(fd > 0 && fd < 1023)) //legally supported file descriptors. adjust this later to meet any strict requirements for this fn.
		return (NULL);
	if (BUFFER_SIZE == 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buf)
		return (NULL);
	read_b = read(fd, buf, BUFFER_SIZE);
	if (read_b == -1 || read_b == 0)
		return (NULL);
	else
		write(1, buf, sizeof(buf));
	/* while (read_b > 0)
	{
		ft_bzero (buf, BUFFER_SIZE);
		read_b = read(fd, buf, BUFFER_SIZE);
		write (1, buf, sizeof(buf));
	} */
	b_total += read_b;
	return (buf);
}
