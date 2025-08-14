#include "gnl_replace.h"

void	*get_next_line(int fd, char *x)
{
	static char s[9999999] = {'\0'};
	static int i = 0;

	int j; 
	// int	k;
	int r;
	char	*out;

	j = 1;
	// k = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// printf("gnl called\n");
	while (j > 0)
	{
		// printf("trying to read\n");
		j = read(fd, s, BUFFER_SIZE);
		// printf("j = %d\n", j);
		if (j == -1 || j == 0)
			break ;
		// k += j;
		r = -1;
		while (++r < j)
		{
			if (s[r] && s[r] == x[0] && strncmp(&s[r], x, strlen(x)) == 0)
			{
				// printf("found a match\n");
				int a;
				a = -1;
				while (++a < strlen(x))
				{
					s[r+a] = '*';
				}
				// printf("done replacing\n");
			}
			write(1, &s[r], 1);
		}
		
	}
	// printf("j = %d\n", j);
	// printf("finished rteading\n");
	// j = 0;
	// while (s[i + j] && s[i+j] != '\n')
	// {
	// 	if (s[i+j] == x[0] && strncmp(&s[i+j], x, strlen(x)) == 0)
	// 	{
	// 		r = i + j -1;
	// 		while (++r < strlen(x))
	// 		{
	// 			s[r] = '*';
	// 		}
	// 	}
	// 	j++;
	// }
	// out = malloc(j + 1);
	// if (!out)
	// 	return (NULL);
	// out[j] = '\0';
	// k = -1;
	// while (++k < j)
	// {
	// 	out[k] = s[i];
	// 	i++;
	// }
	// printf("out is %s\n", out);
	// return (out);

}

int	main(int argc, char **argv)
{
	// char	*print;
	int 	status;
	if (argc != 2)
		return (1);
	// print = NULL;
	status = 1;

	while (status)
	{
		get_next_line(0, argv[1]);
		// printf("%s\n", print);
		// if (!print)
		// 	status = 0;
	}
	// free(print);
	return (0);
	
}