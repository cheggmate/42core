/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:40:24 by jotong            #+#    #+#             */
/*   Updated: 2025/05/27 09:56:25 by jotong           ###   ########.fr       */
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
	while (buf[i] && buf[i] != '\n')
		i++;
	if (i == 0)
		return (NULL);
	if (buf[i] != '\n')
		extra_byte += 1;
	out = (char *)malloc((i + extra_byte) * sizeof(char));
	ft_strlcpy(out, buf, i + 1);
	return (out);
}

char	*get_next_line(int fd)
{
	ssize_t		b;
	char		*out;
	static char	*buf;
	char		tmp[BUFFER_SIZE + 1];

	
	b = 0;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0) //legally supported file descriptors. adjust this later to meet any strict requirements for this fn.
		return (NULL);
	while (!ft_strchr(buf, '\n') && (b = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[b] = '\0';
		buf = ft_strjoin(buf, tmp);
	}
	printf("after while loop\n");
	if (b == -1 || !buf || buf[0] == '\0')
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	printf("after checking for valid buf\n");
	out = get_line(buf);
	printf("after get_line, out = '%s'\n", out);
	buf = rem_printed(buf);
	printf("after rem printed\n");
	return (out);
}
