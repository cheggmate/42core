/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:15:24 by jotong            #+#    #+#             */
/*   Updated: 2025/09/30 23:10:03 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "history.h"
#include "libft.h"

char	*getenv_value(char **env, const char *key)
{
	int		i;
	size_t	len;

	if (!env || !key)
		return (NULL);
	len = strlen(key);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
			return(env[i] + len + 1); // skip "KEY="
		i++;
	}
	return (NULL);
}

static int	handle_pid_err(int pid, char **argv, char **envp, t_token *tokens)
{
	if (pid == 0)
	{
		execve(argv[0], argv, envp);
		perror("execve");
		token_free_all(&tokens);
		return (-1);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (-2);
	}
	else
		return (0);
}

static void	init_vars_signals(t_shell *shell, char **envp, int argc,
	char **argv)
{
	(void)argc;
	(void)argv;
	shell->env = envp;
	shell->exit_code = 0;
	shell->running = 1;
	set_signals();
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	t_token	*tokens;
	pid_t	pid;
	int		status;
	char	*line;

	init_vars_signals(&shell, envp, argc, argv);
	while(1)
	{
		line = readline("minishell$ ");
		if (!line)					// ctrl-D (EOF)
		{
			printf("exit\n");		// remove this to save lines?
			break ;
		}
		history_add(line);
		tokens = lex_input(line);
		pid = fork();
		if (handle_pid_err(pid, argv, envp, tokens) == -1)
			exit(1);
		if (pid > 0)
			waitpid(pid, &status, 0);
		free(line);
		token_free_all(&tokens);
	}
	return (0);
}
