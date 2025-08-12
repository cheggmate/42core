#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	s[9999999] = {'\0'};
	static int i = 0;

	int		j;
	int		k;
	char	*r;

	j = 1; k = 0;
	while (j > 0)
	{
		j = read(fd, s + k, BUFFER_SIZE);
		if (j == -1 || !*(s + i))
			return (NULL);
		k += j;
	}
	j = 0;
	while (s[i+j] && s[i+j] != '\n')
		j++;
	r = malloc(j+1 + (s[i + j] == '\n'));
	r[j + (s[i+j] == '\n')] = '\0';
	k = 0;
	while (k <= j)
		r[k++] = s[i++];
	return (r);
}
