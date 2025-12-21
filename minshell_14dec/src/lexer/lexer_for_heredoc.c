#include "minishell.h"

/**
 * Handles the expansion of $? and environment variables.
 * Consistent with subject requirements for $?  and $VAR.
 */
static char	*expand_heredoc_line(char *line, t_shell *shell)
{
	int		i;
	char	*expanded;

	i = 0;
	expanded = ft_strdup("");
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1])
		{
			if (line[i + 1] == '?')
				expanded = append_exit_status(expanded, shell); // 
			else
				expanded = append_env_var(expanded, &line, &i, shell); // 
		}
		else
		{
			expanded = append_char(expanded, line[i]);
			i++;
		}
	}
	free(line);
	return (expanded);
}

/**
 * The main heredoc loop.
 * Implements the "read input until delimiter" requirement[cite: 115].
 * Per subject, this does not update history[cite: 116].
 */
char	*process_heredoc(char *delimiter, int is_quoted, t_shell *shell)
{
	char	*line;
	char	*full_content;
	char	*tmp;

	full_content = ft_strdup("");
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		// Only expand if the delimiter itself was not quoted 
		if (!is_quoted)
			line = expand_heredoc_line(line, shell);
		tmp = ft_strjoin(full_content, line);
		free(full_content);
		full_content = ft_strjoin(tmp, "\n");
		free(tmp);
		free(line);
	}
	return (full_content);
}
