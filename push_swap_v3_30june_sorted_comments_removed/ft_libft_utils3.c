/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:48:06 by jotong            #+#    #+#             */
/*   Updated: 2025/06/30 20:48:24 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static char	**count_words_create_result(const char *s, char c, int *word_count)
{
	int		count;
	int		in_word;
	char	**result;

	count = 0;
	in_word = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	word_count[0] = count;
	result = malloc((word_count[0] + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[word_count[0]] = NULL;
	return (result);
}

static void	free_split(char **arr, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
		free(arr[i]);
	free(arr);
}

static char	*word_dup(const char *start, char c, char **result, int i)
{
	char	*word;
	int		len;

	len = 0;
	while (start[len] && start[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
	{
		free_split(result, i);
		return (NULL);
	}
	ft_strlcpy(word, start, len + 1);
	return (word);
}

char	**ft_split_count(const char *s, char c, int *word_count)
{
	int		i;
	char	**result;

	i = 0;
	result = count_words_create_result(s, c, word_count);
	if (!result)
		return (NULL);
	while (*s && i < word_count[0])
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = word_dup(s, c, result, i);
			if (!result[i])
			{
				free_split(result, i);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (result);
}

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char		*arr;

	arr = NULL;
	if (num <= 0 || size <= 0)
		return (malloc(0));
	if (num == (size_t)INT_MAX || size == (size_t)INT_MAX)
		return (NULL);
	if ((num > 0 && size > SIZE_MAX / num) || (num * size) / num != size)
		return (NULL);
	arr = malloc(num * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, (num * size));
	return (arr);
}
