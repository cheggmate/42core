/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:03:51 by jotong            #+#    #+#             */
/*   Updated: 2025/05/15 14:18:25 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	chk_or_free_arr(char **arr, int str_count, char oper_type)
{
	int	strings_left;

	strings_left = str_count;
	if (oper_type == 'c')
	{
		if (!arr)
			chk_or_free_arr(arr, str_count, 'f');
		else
			return (1);
	}
	else if (oper_type == 'f')
	{
		while (strings_left > 0)
		{
			free(arr[strings_left]);
			strings_left--;
		}
		free(arr);
		return (0);
	}
	return (1);
}

static int	count_words(char const *s, char c)
{
	int		str_count;
	int		within_str;

	str_count = 0;
	within_str = 0;
	if (ft_strncmp(&c, "", 1) == 0)
		return (str_count);
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
	const char	*start_temp;
	int			str_len;

	str_len = 0;
	start_temp = start;
	while (*start_temp != c && *start_temp)
	{
		str_len++;
		start_temp++;
	}
	new_word = malloc(str_len + 1);
	if (new_word)
	{
		ft_strlcpy(new_word, start, str_len + 1);
		split_str[index] = new_word;
	}
	return ((char *)start_temp);
}

char	**ft_split(const char *s, char c)
{
	char		**split_str;
	int			curr_str_n;
	const char	*start;

	curr_str_n = 0;
	if (!s || ft_strncmp(&c, "", 1) == 0 || count_words(s, c) == 0)
		return (NULL);
	split_str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (chk_or_free_arr(split_str, curr_str_n, 'c') == 0)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			s = get_insert_word(split_str, start, curr_str_n, c);
			if (chk_or_free_arr(&split_str[curr_str_n], curr_str_n, 'c') == 0)
				return (NULL);
			curr_str_n++;
		}
		else
			s++;
	}
	return (split_str);
}
