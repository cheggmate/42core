#include "get_next_line.h"
//not sure if this function is working

char	*ft_strchr(char *s, char search)
{
	if (!s || search < 0)
		return (-1);

	while (*s)
	{
		if (*s != search)
			s++;
		else
			return (search - *s);
	}
	return (0);
}
char	*ft_strjoin(char *dest, char *src)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (!s)
		return (-1);
	while (dest[len])
		len++;
	while (src[i])
	{
		i++;
		len += 1;
	}
	char	*new_dest = malloc(len + 1);
	if (!new_dest)
		return (-1);
	new_dest[len + 1] = '\0';
	int x = len - i;
	int y;
	y = 0;
	while (y < x)
	{
		new_dest[y] = dest[y];
		y++;
	}
	int j;
	j = 0;
	while(j < i)
	{
		new_dest[j + x] = src[j];
		j++;
	}
	return (new_dest);
}

char	*get_next_line(int fd)
{
	static char s[999999] = {'\0'};
	static int	i = 0;

	int		j;
	int		k;
	char	*r;

	j = 1; k = 0;
	while (j > 0)
	{
		j = read(fd, s+k, BUFFER_SIZE);
		if (j == -1 || !*(s+i))
			return (NULL);
		k += j;
		if (ft_strncmp(s, '\n') == 0)
			break;
	}
}