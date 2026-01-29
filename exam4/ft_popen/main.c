#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"

char *ft_putstr(char *str)
{
	if (!str)
		return NULL;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return str;
}

int ft_popen(const char *file, char *const argv[], char type)
{
	int fd[2];
	int pid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;
	if (pipe(fd) < 0)
		return -1;
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return -1;
	}
	if (!pid)
	{
		if (type == 'r')
		{
			if (dup2(fd[1], 1) < 0)
				exit(-1);
		}
		if (type == 'w')
			if (dup2(fd[0], 0) < 0)
				exit(-1);
		close(fd[0]);
		close(fd[1]); // always close the fds since they will be duplicated during fork
		execvp(file, argv);
		exit(-1); // exec fail
	}
	if (type == 'r')
	{
		close(fd[1]);
		return fd[0];
	}
	close(fd[0]);
	return fd[1];
}
// int main()
// {
// 	int fd;
// 	char *line;
// 	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
// 	while ((line = get_next_line(fd)))
// 		ft_putstr(line);
// 	return (0);
// }

int main()
{
	int fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	dup2(fd, 0);
	fd = ft_popen("grep", (char *const []){"grep", "c", NULL}, 'r');
	char *line;
	while ((line = get_next_line(fd)))
		printf("%s", line);
}