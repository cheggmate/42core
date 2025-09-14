/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:15:24 by jotong            #+#    #+#             */
/*   Updated: 2025/09/13 22:39:50 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\nminishell$ ", 12);
}

static void	sigquit_handler(int sig)
{
	(void)sig;
	write(1, "\b\b \b\b", 6);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;
	pid_t	pid;
	int		status;

	(void)argc;
	(void)argv;
	shell.env = envp;
	shell.exit_code = 0;
	shell.running = 1;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	while(1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (*line)
			add_history(line);

		// TODO: split args
		char	**args = simple_split(line);

		pid = fork();
		if (pid == 0)
		{
			execve(args[0], args, envp);
			perror("execve");
			exit(1);
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
		}
		else
			perror("fork");
		free(line);
		//TODO: Free args
	}
	return (0);
}
