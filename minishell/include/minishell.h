/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:17:56 by jotong            #+#    #+#             */
/*   Updated: 2025/09/13 23:51:55 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/wait.h>
# include <limits.h>

# include "parser.h"
# include "executor.h"
# include "lexer.h"
# include "builtins.h"

# define PROMPT	"minishell$"
# define BUFFER_SIZE 1024

typedef struct s_shell
{
	char	**env;
	int		exit_code;
	int		running;
}	t_shell;

void	start_shell(t_shell *shell);

#endif
