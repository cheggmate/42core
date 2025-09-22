/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:21:47 by jotong            #+#    #+#             */
/*   Updated: 2025/09/23 00:05:10 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

// focus on functions that run commands, deciding how to execute them, and calling
// the right low level functions. 

// Other responsibilities:
// manage piping between multiple commands
// call redirections handling functions before executing the command
// Wait for child processes and manage exit statuses
// Optionally, handle signals like SIGINT and SIGQUIT in the executor context

int	execute_ast(t_ast *root, t_shell *shell)
{
	int		prev_fd;
	t_ast	*ast;
	int		pipe_fd[2];
	pid_t	pid;
	
	prev_fd = -1;	// for pipe chaining
	ast = root;
	while (ast)
	{
		if (ast->right)	// if there is a command to the right
			pipe(pipe_fd);
		pid = fork();
		if (pid == 0)	// child
		{
			if (prev_fd != -1)	// handle input from previous pipe
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			if (ast->right)	// handle output to the next pipe
			{
				close(pipe_fd[0]);		// close read end
				dup2(pipe_fd[1], STDOUT_FILENO);
				close(pipe_fd[1]);
			}
			apply_redirect(ast);	// handle redirections
			if (is_buildin(ast))
				execute_builtin(ast);
			else
				execve(cmd->path, ast->argv, shell->env); // path should be in the first arg, args = second arg, g_env = third arg
			perror("execve"); // if execve fails
			exit(1);
		}
		if (prev_fd != -1)	// parent
			close(prev_fd);	// close prev pipe read end
		if (ast->right)
		{
			close(pipe_fd[1]);	// close write end
			prev_fd = pipe_fd[0];
		}
		else
			prev_fd = -1;
		ast = ast->right;
	}
	wait_for_all_children();
	return (0);
}
