/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 22:10:50 by jotong            #+#    #+#             */
/*   Updated: 2025/10/02 21:48:54 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

char *ft_strndup(const char *src, size_t num)
{
	size_t		len;
	char		*dup;

	len = ft_strlen(src) + 1;
	if (num < len - 1)
		len = num + 1;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	else
	{
		ft_memcpy(dup, src, len);
		return (dup);
	}
}

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

static void	print_tokens(t_token *token)
{
	printf("starting to parse tokens\n");
	while (token)
	{
		printf("token value = %s\n", token->value);
		printf("token type: %d\n", token->type);
		if (token->next)
			printf("address of next token: %p\n", token->next);
		else
			printf("no next token\n");
		token = token->next;
	}
	printf("done parsing and printing tokens\n");
}

t_token *lex_input(const char *s, size_t s_len)
{
	size_t			i;
	t_token			*tokens;
	t_token_type	t;
	char			*word;

	i = 0;
	// printf("s_len = %zu\n", s_len);		// TODO: Remove later
	tokens = NULL;
	while (s[i] && i < s_len)
	{
		if (is_space((unsigned char)s[i]))
		{
			i++;
			continue ;
		}
		if (s[i] == '|' || s[i] == '<' || s[i] == '>')
		{
			t = get_op_type(&s[i], &i);
			add_token_back(&tokens, token_new(t, NULL));
			i += 1;
		}
		else
		{
			printf("extracting word\n");
			printf("i(before): %d\n", i);
			word = extract_word(&s[i], &i);
			// printf("word = %s\n", word);
			add_token_back(&tokens, token_new(T_WORD, word));
			printf("i(after): %d\n", i);
			// i += ft_strlen(word);
			free(word);
		}
		// printf("s_len = %zu, i = %zu\n", s_len, i);
	}
	print_tokens(tokens);	// TODO: remove this later
	return (tokens);
}
