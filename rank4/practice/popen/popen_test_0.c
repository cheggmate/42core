#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int ft_popen(const char *file, char *const av[], char type)
{
	int	fd[2];
	pid_t	pid;

	if (!file || !av || (type != 'r' && type !='w') || pipe (fd) < 0)
		return (-1);
	pid =  fork();
	if (pid == 0)
	{
		dup2(fd[type == 'r'? 1 : 0], type == 'r'? 1 : 0);
		close (fd[1]);
		close (fd[0]);
		execvp(file, av);
		exit (1);
	}
	close (fd[type == 'r'? 1 : 0]);
	return (fd[type == 'r'? 0 : 1]);
}