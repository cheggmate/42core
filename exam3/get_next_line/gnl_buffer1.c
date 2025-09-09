#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	buf[9999999] = {'\0'};
	static int	i = 0; // index of where we are in buf
	int			read_bytes;
	int			j;
	char		*r;

	// keep reading until we find a newline or EOF
	while (1)
	{
		// if buffer already contains a newline from previous reads, stop
		j = i;
		while (buf[j])
		{
			if (buf[j] == '\n')
				break;
			j++;
		}
		if (buf[j] == '\n' || buf[j] == '\0')
			break;

		// otherwise read more from fd
		read_bytes = read(fd, buf + j, BUFFER_SIZE);
		if (read_bytes <= 0)
			break;
		buf[j + read_bytes] = '\0';
	}

	// if no more data, return NULL
	if (!buf[i])
		return (NULL);

	// find length of line until newline or end
	j = 0;
	while (buf[i + j] && buf[i + j] != '\n')
		j++;

	// allocate space for line (+1 if newline exists, +1 for '\0')
	r = malloc(j + 1 + (buf[i + j] == '\n'));
	if (!r)
		return (NULL);

	// copy into result
	read_bytes = 0;
	while (read_bytes < j)
	{
		r[read_bytes] = buf[i];
		read_bytes++;
		i++;
	}
	if (buf[i] == '\n')
		r[read_bytes++] = buf[i++];
	r[read_bytes] = '\0';

	return (r);
}
