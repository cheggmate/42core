#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int picoshell(char **cmds[])
{
	int i;
	int in_fd;
	int fd[2];
	pid_t pid;

	i = 0;
	in_fd = 0;
	while (cmds[i])
	{
		if (cmds[i+1] && pipe(fd) < 0)
			return (1);
		pid = fork();
		if (pid == 0)
		{
			if (in_fd != 0)
			{
				dup2(in_fd, 0);
				close(in_fd);
			}
			if (cmds[i+1])
			{
				dup2(fd[1], 1);
				close (fd[1]);
				close (fd[0]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit (1);
		}
		if (in_fd != 0)
		{
			close(in_fd);
		}
		if (cmds[i+1])
		{
			close (fd[1]);
			in_fd = fd[0];
		}
		i++;
	}
	int status;
	while (wait(&status) > 0)
		continue ;
	return (0);
}