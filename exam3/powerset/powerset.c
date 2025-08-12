#include "powerset.h"

// int	check_valid_int(int argc, char *argv)
// {
// 	int i;
// 	int j;
// 	int	s_len;

// 	i = 0;
// 	while (++i < argc)
// 	{
// 		j = 0;
// 		s_len = strlen(argv[i]);
// 		if (argv[i][j] == '-')
// 		while (++j < s_len)
// 		{

// 		}
// 	}
// }
char	**clean_dups(int *nums, char *argv)
{
	int 	count;
	int		filled;
	int		check;
	char	**cleaned;

	count = 0;
	filled = 0;
	cleaned = (char *)malloc(*nums * sizeof(char *));
	if (!cleaned)
		return (NULL);
	cleaned[0] = &argv[1];
	filled = 1;
	while (++count < *nums)
	{
		cleaned[count] = NULL;
	}
	count = 1;
	while (++count < *nums)
	{
		check = -1;
		while (++check < filled)
		{
			if (cmp(cleaned[check], argv[count]) == 0)
				break;
		}
		if (check != filled)
		{
			cleaned[filled] = &argv[count];
			count++;
			filled++;
		}
		// check = count + 1;
		
		// while (++check < *nums)
		// {
		// 	if (cmp(argv[check], argv[count]) == 0)
		// 	{

		// 	}
		// }
	}
}

void	solve(int argc, char **argv)
{
	int 	i;
	char	**cleaned;
}

int	main(int argc, char **argv)
{
	int	nums;
	char *cleaned;

	nums = argc - 1;
	if (argc == 1)
		return (1);
	else
	{
		cleaned = clean_dups(&nums, argv);
		solve(nums, cleaned);
		return(0);
	}
}
