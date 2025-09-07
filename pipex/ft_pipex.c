/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:56:14 by jotong            #+#    #+#             */
/*   Updated: 2025/09/07 23:57:04 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_in_path(char *cmd, char **envp)
{
    char *path_env = NULL;
    char **paths;
    char *full_path;
    int i;

    for (i = 0; envp[i]; i++) {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0) {
            path_env = envp[i] + 5;
            break;
        }
    }
    if (!path_env)
        return (NULL);

    paths = ft_split(path_env, ':');
    for (i = 0; paths[i]; i++) {
        full_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
        if (access(full_path, X_OK) == 0)
            return (full_path); // found it!
        free(full_path);
    }
    return (NULL);
}

char	**parse_command(char *arg)
{
	char	**str;

	str = ft_split(arg, ' ');
	if (!str)
		return (NULL);
	return (str);
}

int	start_piping(char **argv, char **envp)
{
	int 	pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	printf("start piping called\n");
	if (pipe(pipe_fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 == 0)
	{
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
		
		char **cmd1_args = parse_command(argv[2]);
		char *cmd_path1 = find_in_path(cmd1_args[0], envp);
		execve(cmd_path1, cmd1_args, envp);
		perror("execve");
		exit(1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);

		int output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (output_fd == -1)
			return (-1);
		
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
		
		char	**cmd2_args = parse_command(argv[3]);
		char *cmd_path2 = find_in_path(cmd2_args[0], envp);
		execve(cmd_path2, cmd2_args, envp);
		perror("execve");
		exit(1);
	}

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		printf("not enough arguments\n");
		return (1);
	}
	// if (arg_checks(argv) == -1)
	// {
	// 	printf("invalid arguments\n");
	// 	return (1);
	// }
	if (start_piping(argv, envp) == -1)
	{
		printf("an error occurred\n");
		return (1);
	}
	return (0);
}
