#include "gnl_replace.h"

int		chk_str(char *chk, char *replace, int s_len)
{
	int i;
	int	c_len;

	i = -1;
	c_len = strlen(chk);
	if (c_len < s_len)
		return (1);
	while (++i < s_len)
	{
		if (chk[i] != replace[i])
			return (chk[i] - replace[i]);
	}
	return (0);
}

void	get_next_line(int fd, char *x)
{
	static char s[9999999] = {'\0'};
	static int i = 0;

	int j; 
	int	k;
	int r;
	char	*out;

	j = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return ;
	k = 0;
	while (j > 0)
	{
		j = read(fd, s + k, BUFFER_SIZE);
		if (j == -1 || j == 0)
			break ;
		k += j;
	}
	s[k] = '\0';
	r = -1;
	while (++r < k)
	{
		if (s[r] && s[r] == x[0] && chk_str(&s[r], x, strlen(x)) == 0)
		{
			int a;
			a = -1;
			while (++a < strlen(x))
			{
				s[r+a] = '*';
			}
		}
	}
	write(1, &s[0], k);

}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	get_next_line(0, argv[1]);
	return (0);
	
}