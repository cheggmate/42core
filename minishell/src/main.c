/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:15:24 by jotong            #+#    #+#             */
/*   Updated: 2025/09/20 00:46:57 by jotong           ###   ########.fr       */
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
	t_token	*tokens;
	pid_t	pid;
	int		status;
	char	*line;

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
		history_add(line);

		// TODO: split args
		tokens = lex_input(line);

		pid = fork();
		if (pid == 0)
		{
			execve(argv[0], argv, envp);
			perror("execve");
			token_free_all(tokens);
			exit(1);			// check if should exit or return value
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
		}
		else
			perror("fork");
		free(line);
		token_free_all(tokens);
	}
	return (0);
}
