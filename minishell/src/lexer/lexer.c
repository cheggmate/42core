/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 22:10:50 by jotong            #+#    #+#             */
/*   Updated: 2025/09/28 23:41:36 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

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

	while (s[*i] && !is_space((unsigned char)s[*i]) && s[*i] != '|'
		&& s[*i] != '<' && s[*i] != '>')
		(*i)++;
	return (ft_strndup(s + start, *i - start));
}

t_token *lex_input(const char *s)
{
	size_t			i;
	t_token			*tokens;
	t_token_type	t;
	char			*word;

	i = 0;
	tokens = NULL;
	while (s[i])
	{
		if (is_space((unsigned char)s[i]))
		{
			i++;
			continue ;
		}
		if (s[i] == '|' || s[i] == '<' || s[i] == '>')
		{
			t = get_operator_type(s, &i);
			add_token_back(&tokens, token_new(t, NULL));
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
