/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:40:24 by jotong            #+#    #+#             */
/*   Updated: 2025/05/28 21:24:34 by jotong           ###   ########.fr       */
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
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	new_buf = (char *)malloc((ft_strlen(&buf[i + 1]) + 1));
	ft_strlcpy(new_buf, &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
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
	out = (char *)malloc((i + extra_byte));
	ft_strlcpy(out, buf, i + extra_byte);
	return (out);
}

char	*get_next_line(int fd)
{
	ssize_t		b;
	char		*out;
	static char	*buf[1024];
	char		*tmp;
	char		*tmp_buf;

	b = 0;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!buf[fd])
		buf[fd] = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(buf[fd], '\n'))
	{
		b = read(fd, tmp, BUFFER_SIZE);
		if (b <= 0)
			break;
		tmp[b] = '\0';
		tmp_buf = ft_strjoin(buf[fd], tmp);
		if (buf[fd])
			free(buf[fd]);
		buf[fd] = tmp_buf;
	}
	if (b == -1 || !buf[fd] || buf[fd][0] == '\0')
	{
		free(buf[fd]);
		free(tmp);
		buf[fd] = NULL;
		return (NULL);
	}
	out = get_line(buf[fd]);
	printf("out is %s\n", out);
	tmp_buf = rem_printed(buf[fd]);
	printf("tmp_buf is %s\n", tmp_buf);
	// free(buf[fd]);
	buf[fd] = tmp_buf;
	if (b == 0)
	{
		if (buf[fd])
			free(buf[fd]);
		if (out)
			free(out);
		if (tmp)
			free(tmp);
		return (NULL);
	}
	return (out);
}
