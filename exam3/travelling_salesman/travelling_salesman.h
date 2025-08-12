#ifndef TRAVELLING_SALESMAN_H
# define TRAVELLING_SALESMAN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <limits.h>

typedef struct s_input
{
	int	*visited;
	int	min_dist;
	int	total_cities;
	int	dist;
	int	s_city;

}	t_input;

#endif
