/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:56:14 by jotong            #+#    #+#             */
/*   Updated: 2025/08/29 15:28:46 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_command(char *arg)
{
	char	**str;

	str = ft_split(arg, ' ');
	if (ft_strncmp(str[0], "wc", 2) == 0 && str[1][0] == '-'
		&& (str[1][1] == 'l' || str[1][1] == 'w'))
		return (str);
	return (NULL);
}

int	start_piping(char **argv)
{
	int 	pipe_fd[2];
	int		pid1;
	char	**environ;

	if (pipe(pipe_fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 == 0)
	{ // Child process 1
		close(pipe_fd[0]); // Close read end, we won't use it
		// Redirect stdin to read from the file
		int input_fd = open(argv[1], O_RDONLY);
		if (input_fd == -1)
		{
			printf("bad file, aborting\n");
			return (-1);
		}
		dup2(input_fd, STDIN_FILENO); // Now stdin comes from the file
		close(input_fd);
		
		// Redirect stdout to write to the pipe
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		
		// Execute the first command
		char **cmd1_args = parse_command(argv[2]);
		if (!cmd1_args)
			return (-1);
		execve(cmd1_args[0], cmd1_args, environ);
	}
	return (0);
}

int	arg_checks(char **argv) // this needs to be changed to support more commands
{
	if (ft_strncmp(argv[2], "wc -l", 5) != 0 || ft_strncmp(argv[3], "wc -w", 5) != 0)
		return (-1);
	if (ft_strncmp(argv[3], "wc - l", 5) != 0 || ft_strncmp(argv[3], "wc -w", 5) != 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("not enough arguments\n");
		return (1);
	}
	if (arg_checks(argv) == -1)
	{
		printf("invalid arguments\n");
		return (1);
	}
	if (start_piping(argv) == -1)
	{
		printf("an error occurred\n");
		return (1);
	}
	return (0);
}
