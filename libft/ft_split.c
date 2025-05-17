/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:03:51 by jotong            #+#    #+#             */
/*   Updated: 2025/05/17 14:51:54 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	free_arr(char **arr, int str_count)
{
	int	strings_left;

	strings_left = str_count;
	while (strings_left > 0)
	{
		free(arr[strings_left]);
		strings_left--;
	}
	free(arr);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int		str_count;
	int		within_str;

	str_count = 0;
	within_str = 0;
	if (!s)
		return (str_count);
	else if (c == '\0')
		return (1);
	while (*s)
	{
		if (*s != c)
			within_str = 1;
		else if (*s == c && within_str == 1)
		{
			within_str = 0;
			str_count++;
		}
		s++;
	}
	s--;
	if (*s != c)
		str_count += 1;
	return (str_count);
}

char	*get_insert_word(char **split_str, const char *start, int index, char c)
{
	char		*new_word;
	const char	*curr_char;
	int			str_len;

	str_len = 0;
	curr_char = start;
	while (*curr_char && *curr_char != c)
	{
		str_len++;
		curr_char++;
	}
	new_word = malloc(str_len + 1);
	if (new_word)
	{
		ft_strlcpy(new_word, start, str_len + 1);
		split_str[index] = new_word;
	}
	else
		free_arr(split_str, index);
	return ((char *)curr_char);
}

char	**ft_split(const char *s, char c)
{
	char		**split_str;
	int			curr_str_n;
	int			word_count;

	curr_str_n = 0;
	word_count = count_words(s, c);
	split_str = malloc((word_count + 1) * sizeof(char *));
	if (!split_str)
		return (NULL);
	if (word_count == 0)
		return (split_str);
	while (*s && curr_str_n < word_count)
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			s = get_insert_word(split_str, s, curr_str_n, c);
			if (!split_str[curr_str_n])
				return (NULL);
			curr_str_n++;
		}
	}
	return (split_str);
}
