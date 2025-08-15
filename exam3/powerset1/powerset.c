#include "powerset.h"

// void	clear_list(char *list)
// {
// 	int	l_len;

// 	l_len = strlen(list);
// 	while (l_len-- > 0)
// 	{
// 		list[l_len] = '\0';
// 	}
// }

int	in_list(char *list, char to_print)
{
	int	l_len;
	int	j;

	j = -1;
	l_len = strlen(list);
	if (l_len == 0)
		return (0);
	while (++j < l_len)
	{
		if (list[j] == to_print)
			return (1);
	}
	return (0);
}

void	solve(char *list)
{
	int		i;
	int		l_len;

	i = -1;
	l_len = strlen(list);
	write(1,"[", 1);
	while(++i < l_len)
	{
		write(1, &list[i], 1);
		if (i < l_len - 1)
			write(1,",", 2);
	}
	write(1,"]", 1);
	if (l_len > 1)
	{
		write(1, "\n", 1);
		solve(list + 1);
	}
}

void	remove_dups(char *src, char *list)
{
	int	s_len;
	int	x;
	int y;

	s_len = strlen(src);
	x = -1;
	y = 0;
	while(++x < s_len)
	{
		if (!in_list(list, src[x]))
		{
			list[y] = src[x];
			y++;
		}
	}
}

int	main(int argc, char **argv)
{
	char	*list;

	if(argc != 2)
		return (1);
	if(strlen(argv[1]) == 0)
		return (1);
	list = malloc(strlen(argv[1] + 1));
	if (!list)
		return (1);
	list[0] = '\0';
	remove_dups(argv[1], list);
	write(1, "[]\n", 3);
	solve(list);
	free(list);
	return (0);
}