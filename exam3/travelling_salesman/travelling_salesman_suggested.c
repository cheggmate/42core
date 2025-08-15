#include <unistd.h>
#include <stdlib.h>

#define MAX_CITIES 10

typedef struct s_tsp
{
	int n;
	int **dist;
	int *path;
	int *best_path;
	int best_cost;
}	t_tsp;

static int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putnbr(int n)
{
	char c;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

static void	swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	calc_cost(t_tsp *tsp)
{
	int cost = 0;
	int i;

	for (i = 0; i < tsp->n - 1; i++)
		cost += tsp->dist[tsp->path[i]][tsp->path[i + 1]];
	cost += tsp->dist[tsp->path[tsp->n - 1]][tsp->path[0]];
	return (cost);
}

static void	save_best(t_tsp *tsp, int cost)
{
	int i;
	tsp->best_cost = cost;
	for (i = 0; i < tsp->n; i++)
		tsp->best_path[i] = tsp->path[i];
}

static void	permute(t_tsp *tsp, int l)
{
	if (l == tsp->n)
	{
		int cost = calc_cost(tsp);
		if (tsp->best_cost == -1 || cost < tsp->best_cost)
			save_best(tsp, cost);
		return ;
	}
	for (int i = l; i < tsp->n; i++)
	{
		swap(&tsp->path[l], &tsp->path[i]);
		permute(tsp, l + 1);
		swap(&tsp->path[l], &tsp->path[i]);
	}
}

int	main(void)
{
	t_tsp tsp;
	int i, j;
	int matrix[MAX_CITIES][MAX_CITIES] = {
		{0, 10, 15, 20},
		{10, 0, 35, 25},
		{15, 35, 0, 30},
		{20, 25, 30, 0}
	};

	tsp.n = 4; // number of cities
	tsp.dist = malloc(tsp.n * sizeof(int *));
	for (i = 0; i < tsp.n; i++)
	{
		tsp.dist[i] = malloc(tsp.n * sizeof(int));
		for (j = 0; j < tsp.n; j++)
			tsp.dist[i][j] = matrix[i][j];
	}
	tsp.path = malloc(tsp.n * sizeof(int));
	tsp.best_path = malloc(tsp.n * sizeof(int));
	for (i = 0; i < tsp.n; i++)
		tsp.path[i] = i;
	tsp.best_cost = -1;

	permute(&tsp, 1); // keep city 0 fixed as start

	ft_putstr("Best path: ");
	for (i = 0; i < tsp.n; i++)
	{
		ft_putnbr(tsp.best_path[i]);
		if (i < tsp.n - 1)
			ft_putstr(" -> ");
	}
	ft_putstr(" -> 0\nCost: ");
	ft_putnbr(tsp.best_cost);
	write(1, "\n", 1);

	for (i = 0; i < tsp.n; i++)
		free(tsp.dist[i]);
	free(tsp.dist);
	free(tsp.path);
	free(tsp.best_path);
	return (0);
}
