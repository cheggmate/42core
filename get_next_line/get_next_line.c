/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:40:24 by jotong            #+#    #+#             */
/*   Updated: 2025/05/28 23:45:48 by jotong           ###   ########.fr       */
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
	new_buf = (char *)malloc((ft_strlen(i + buf)) * sizeof(char));
	ft_strlcpy(new_buf, &buf[i + 1], ft_strlen(buf) + i);
	free(buf);
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
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (i == 0 && buf[i] != '\n')
		return (NULL);
	if (buf[i] == '\n')
		extra_byte += 1;
	out = (char *)malloc((i + extra_byte) * sizeof(char));
	ft_strlcpy(out, buf, i + extra_byte);
	return (out);
}

char	*get_next_line(int fd)
{
	ssize_t		b;
	char		*out;
	static char	*buf[1024];
	char		*tmp;

	b = 0;
	out = NULL;
	tmp = NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf[fd])
		buf[fd] = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		tmp = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(buf[fd], '\n') && (b = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[b] = '\0';
		buf[fd] = ft_strjoin(buf[fd], tmp);
	}
	if (b == -1 || !buf[fd] || buf[fd][0] == '\0')
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	if (b == 0)
	{
		if (buf[fd])
			free(buf[fd]);
		if (tmp)
			free(tmp);
		if (out)
			free(out);
	}
	out = get_line(buf[fd]);
	buf[fd] = rem_printed(buf[fd]);
	return (out);
}
