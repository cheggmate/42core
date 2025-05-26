/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:40:24 by jotong            #+#    #+#             */
/*   Updated: 2025/05/26 23:35:37 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rem_printed(char *buf)
{
	int		i;
	char	*new_buf;

	i = 0;
	if (!buf || buf[0] == '\0')
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	new_buf = (char *)malloc((i + 1) * sizeof(char *));
	ft_strlcpy(new_buf, &buf[i], ft_strlen(buf) + 1);
	return (new_buf);
}

char	*get_line(char *buf)
{
	size_t	i;
	char	*out;
	int		extra_byte;

	i = 0;
	extra_byte = 1;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (i == 0)
		return (NULL);
	if (buf[i] != '\n')
		extra_byte += 1;
	out = (char *)malloc((i + extra_byte) * sizeof(char *));
	ft_strlcpy(out, buf, i + 1);
}

char	*get_next_line(int fd)
{
	ssize_t		b;
	char		*out;
	static char	*buf;
	char		tmp[BUFFER_SIZE + 1];

	
	b = 0;
	if (!(fd > 0 && fd < 1023) || BUFFER_SIZE == 0) //legally supported file descriptors. adjust this later to meet any strict requirements for this fn.
		return (NULL);
	while (!ft_strchr(buf, '\n') && (b = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		tmp[b] = '\0';
		buf = ft_strljoin(buf, tmp);
	}
	if (b == -1 || b == 0 || !buf || buf[0] == '\0')
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	out = get_line(buf);
	buf = rem_printed(buf);
	return (buf);
}
