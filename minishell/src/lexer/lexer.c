/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 22:10:50 by jotong            #+#    #+#             */
/*   Updated: 2025/09/20 00:35:42 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// char **simple_split(char *s)
// {
// 	char	**split_args;
// 	int		arg_count;
// 	int		index;
// 	t_token	*tok;

// 	arg_count = 0;
// 	index = 0;
// 	tok = malloc(sizeof(t_token));
// 	tok->type = T_WORD;
	
// 	while (s[index])
// 	{
// 		if (s[index] == '|' || s[index] == '<' || s[index] == '>')
// 		{
// 			arg_count += 1;
// 			index++;
// 		}
// 		else if (s[index] == '>' && s[index + 1] == '>')
// 		{
// 			arg_count += 1;
// 			index += 2;
// 		}
// 		else if (s[index] == '<' && s[index + 1] == '<')
// 		{
// 			arg_count += 1;
// 			index += 2;
// 		}
// 	}
// }

t_token_type	get_op_type(const char *s, size_t *i)
{
	if (s[*i] == '|')
	{
		(*i)++;
		return (T_PIPE);
	}
	else if (s[*i] == '<')
	{
		if (s[*i + 1] == '<')
		{
			*i += 2;
			return (T_HEREDOC);
		}
		(*i)++;
		return (T_REDIR_IN);
	}
	else if (s[*i] == '>')
	{
		if (s[*i + 1] == '>')
		{
			*i += 2;
			return (T_REDIR_APPEND);
		}
		(*i)++;
		return (T_REDIR_OUT);
	}
	return (T_WORD);
}

char	*extract_word(const char *s, size_t *i)
{
	size_t	start = *i;

	while (s[*i] && !isspace((unsigned char)s[*i]) && s[*i] != '|'
		&& s[*i] != '<' && s[*i] != '>')
		(*i)++;
	return (ft_strndup(s + start, *i - start));
}

t_token *lex_input(const char *s)
{
	size_t			i;
	t_token			*tokens;
	t_token_type	t;
	char			*word

	i = 0;
	tokens = NULL;
	while (s[i])
	{
		if (isspace((unsigned char)s[i]))
		{
			i++;
			continue ;
		}
		if (s[i] == '|' || s[i] == '<' || s[i] == '>')
		{
			t = get_operator_type(s, &i);
			token_add_back(&tokens, token_new(t, NULL));
		}
		else
		{
			word = extract_word(s, &i);
			add_token_back(&tokens, token_new(T_WORD, word));
			free(word);
		}
	}
	return (tokens);
}