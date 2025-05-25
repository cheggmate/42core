/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:40:24 by jotong            #+#    #+#             */
/*   Updated: 2025/05/25 22:59:08 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		read_b;
	char		*buf;
	char		*out;
	
	read_b = 0;
	if (!(fd > 0 && fd < 1023) || BUFFER_SIZE == 0) //legally supported file descriptors. adjust this later to meet any strict requirements for this fn.
		return (NULL);
	
	read_b = check_or_read(out, fd);
	// read_b = read(fd, buf, BUFFER_SIZE);
	if (read_b == -1 || read_b == 0)
		return (NULL);
	return (buf);
}
