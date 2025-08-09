#include "n_queens.h"


void	print_map(int *map, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (map[i] != j)
				write(1, "0", 1);
			else
				write(1, "Q", 1);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int	is_safe(int row, int col, int *map)
{
	int i;

	i = -1;
	while(++i < row)
	{
		if (map[i] == col)
			return (0);
		if (map[i] != -1 && ((row - i == col - map[i]) || (i - row == map[i] - col)))
			return (0);
		if (map[i] != -1 && ((i - row == col - map[i]) || (row - i == map[i] - col)))
			return (0);
	}
	return (1);
}

void	solve(int x, int *m, int num)
{
	int i;

	i = -1;
	if (x == num)
	{
		print_map(m, num);
		write(1, "\n", 1);
		return ;
	}
	while(++i < num)
	{
		if (is_safe(x, i, m))
		{
			m[x] = i;
			solve(x+1, m, num);
			m[x] = -1;
		}
	}

}

void	init_m(int **m, int num)
{
	int i;

	i = -1;
	*m = malloc(num * sizeof(int));
	if (!*m)
		return ;
	while (++i < num)
		(*m)[i] = -1;
}

int	main(int argc, char **argv)
{
	int	num;
	int	*m;
	int	x;
	// int y;

	x = 0;
	// y = -1;
	m = NULL;
	num = 0;
	if (argc != 2)
		return (1);
	else
	{
		num = atoi(argv[1]);
		init_m(&m, num);
		if (!m)
			return (1);
		solve(x, m, num);
		free(m);
		return (0);
	}
}
