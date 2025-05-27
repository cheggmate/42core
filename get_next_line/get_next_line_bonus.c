/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:40:24 by jotong            #+#    #+#             */
/*   Updated: 2025/05/27 22:43:00 by jotong           ###   ########.fr       */
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
	new_buf = (char *)malloc((i + 1) * sizeof(char));
	ft_strlcpy(new_buf, &buf[i], ft_strlen(buf) + 1);
	free(buf);
	return (new_buf);
}

char	*get_line(char *buf)
{
	size_t	i;
	char	*out;
	int		extra_byte;

	i = 0;
	printf("start get_line\n");
	extra_byte = 1;
	if (!buf)
		return (NULL);
	printf("start while loop\n");
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	printf("i is %zu\n", i);
	printf("buf[%zu] = '%c'\n", i, buf[i]);
	if (i == 0)
		return (NULL);
	if (buf[i] == '\n')
		extra_byte += 1;
	out = (char *)malloc((i + extra_byte) * sizeof(char));
	printf("extra byte = %d\n", extra_byte);
	ft_strlcpy(out, buf, i + extra_byte);
	printf("out is '%s'\n",out);
	return (out);
}

char	*get_next_line(int fd)
{
	ssize_t		b;
	char		*out;
	static char	*buf[1024];
	char		tmp[BUFFER_SIZE + 1];
	// ssize_t		b_total;

	// b_total = 0;
	b = 0;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0) //legally supported file descriptors. adjust this later to meet any strict requirements for this fn.
		return (NULL);
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
	out = get_line(buf[fd]);
	buf[fd] = rem_printed(buf[fd]);
	return (out);
}
