#include "travelling_salesman.h"

// kind of works, but does not always return the most optimal route.

void	free_everything(int ***graph, t_input *input)
{
	int	i;

	i = -1;
	if (*graph)
	{
		while (++i < input->total_cities)
		{
			if ((*graph)[i])
				free((*graph)[i]);
		}
		free(*graph);
		*graph = NULL;
	}
	// printf("finished freeing graph\n");
	if (input && input->visited)
		free(input->visited);
	input->visited = NULL;
	// printf("finished freeing input\n");
	free(input);
	input = NULL;
}

int	not_in_visited(int i, t_input **input)
{
	int x;

	x = -1;
	while (++x < (*input)->total_cities)
	{
		if ((*input)->visited[x] == i)
			return (0);
	}
	return (1);
}

void	populate_shortest_route(t_input **input, int ***g)
{
	int	i;
	int	shortest_dist;
	int	s_visited;
	int	last_visited;
	int	shortest_dist_city;

	s_visited = 1;
	last_visited = (*input)->s_city;

	(*input)->visited[0] = (*input)->s_city;
	(*input)->dist = 0;

	// printf("s_city = %d\n", (*input)->s_city);
	// printf("starting to populate shortest route\n");
	while (s_visited < (*input)->total_cities)
	{
		i = -1;
		shortest_dist = 0;
		shortest_dist_city = -1;
		while (++i < (*input)->total_cities)
		{
			if (i != (*input)->s_city && not_in_visited(i, input))
			{
				// printf("checking route %d\n", i);
				// printf("last_visited = %d\n", last_visited);
				// printf("g last visited = %d\n", (*g)[last_visited][i]);
				if (shortest_dist == 0 || shortest_dist > (*g)[last_visited][i])
				{
					// printf("found_shortest_route\n");
					shortest_dist = (*g)[last_visited][i];
					shortest_dist_city = i;

				}
			}
		}
		if (shortest_dist_city == -1)
			break ;

		(*input)->dist += shortest_dist;
		(*input)->visited[s_visited] = shortest_dist_city;
		last_visited = shortest_dist_city;
		s_visited += 1;
		// printf("shortest dist = %d\n", shortest_dist);
	}
	
	(*input)->dist += (*g)[last_visited][(*input)->s_city];

	if ((*input)->min_dist == 0 || (*input)->min_dist > (*input)->dist)
		(*input)->min_dist = (*input)->dist;
	// printf("Dist for this route: %d\n", (*input)->dist);
}

void	solve(t_input **input, int ***g)
{
	int	dist;
	int	i;

	dist = 0;
	i = -1;

	// printf("solving\n");
	if ((*input)->s_city == (*input)->total_cities)
		return ;
	while (++i < (*input)->total_cities)
		(*input)->visited[i] = -1;

	// printf("after zeroing visited\n");
	(*input)->dist = 0;
	// printf("before populating shortest route\n");
	// start at city zero
	populate_shortest_route(input, g);

	if ((*input)->dist < (*input)->min_dist)
		(*input)->min_dist = (*input)->dist;
	(*input)->s_city += 1;
	solve(input, g);
	return ;
}

void	init_graph(int ***graph, t_input *input, char **argv)
{
	int i;
	int j;
	int	x;

	x = 1;
	i = -1;
	j = -1;
	// printf("input->total_cities is %d\n", input->total_cities);
	while (++i < input->total_cities)
	{
		j = -1;
		while (++j < input->total_cities)
		{
			(*graph)[i][j] = atoi(argv[++x]);
		}
	}
}

int	check_inputs(char **argv)
{
	int 	x;
	int		args_c;
	char	*n;

	x = 1;
	args_c = atoi(argv[1]);
	while (++x < args_c)
	{
		n = argv[x];

		if (!n || *n == '\0')
			return (0);
		if (*n == '-' || *n == '+')
			n++;
		while (*n)
		{
			if (!(*n >= '0' && *n <= '9'))
				return (0);	
			n++;
		}
	}
	return (1);
}


void	print_graph(int **graph, t_input *input)
{
	int i;
	int j;

	i = -1;
	j = -1;

	while (++i< input->total_cities)
	{
		j = -1;
		while (++j < input->total_cities)
		{
			printf("%d", graph[i][j]);
			if (j < input->total_cities - 1)
				printf(" ");
		}
		printf("\n");
	}

}

int	main(int argc, char **argv)
{
	int		result;
	t_input	*input;
	int		**graph;
	int	i;
	int	*visited;

	visited = NULL;
	result = 0;
	i = -1;
	if (argc <= 2)
	{
		printf("wrong number of inputs!\n");
		return (1);
	}
	else
	{
		if (!check_inputs(argv))
			return (1);
		input = malloc(1 * sizeof(t_input));
		if (!input)
			return (1);
		input->total_cities = atoi(argv[1]);
		// printf("after init total cities\n");
		graph = (int **)malloc(input->total_cities * sizeof(int *));
		if (!graph)
		{
			free_everything(&graph, input);
			return (1);
		}
		while (++i < input->total_cities)
		{
			graph[i] = (int *)malloc(input->total_cities * sizeof(int));
			if (!graph[i])
			{
				free_everything(&graph, input);
				return (1);
			}
		}
		// printf("before init graph\n");
		init_graph(&graph, input, argv);
		print_graph(graph, input);
		// printf("after init graph\n");
		input->visited = malloc(input->total_cities * sizeof(int));
		input->min_dist = 0;
		input->s_city = 0;
		if (input->total_cities < 0 || input->total_cities > INT_MAX)
			return (1);
		// printf("before solve\n");
		solve(&input, &graph);
		result = input->min_dist;
		printf("minimum distance is %d\n", result);
		// printf("solved, freeing everything\n");
		free_everything(&graph, input);
		return (0);
	}
}
