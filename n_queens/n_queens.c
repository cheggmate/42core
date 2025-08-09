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

void	check_queens(int x, int *m, int num)
{
	int y;

	if (x == num)
	{
		print_map(m, num);
		write(1, "\n", 1);
		return ;
	}
	// TODO: this function needs to be fixed
	// if (y == 4)
	// {
	// 	x += 1;
	// 	y = 0;
	// 	if (x == 4)
	// 		return ;
	// }
	// if (!valid_pos(x, y, m, num))
	// {
	// 	check_queens(x, y+1, m, num);
	// }
}

void	init_m(int **m, int num)
{
	int i;

	i = -1;
	m = malloc(num * sizeof(int));
	if (!m)
		return (NULL);
	while (++i < num)
		m[i] = -1;
}

int	main(int argc, char **argv)
{
	int	num;
	int	*m;
	int	x;
	// int y;

	x = -1;
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
		check_queens(x, m, num);
		// while (++x < num)
		// {
		// 	y = -1;
		// 	while (++y < num)
		// 	{
		// 		check_queens(x, y, m, num);
		// 		print_map(m, num);
		// 	}
		// }
	}
}
