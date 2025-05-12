/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:03:51 by jotong            #+#    #+#             */
/*   Updated: 2025/05/12 22:30:59 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	free_array(char **arr, int str_count)
{
	int	strings_left;

	strings_left = str_count;
	while (strings_left > 0)
	{
		free(arr[strings_left]);
		strings_left--;
	}
	free(arr);
}

static int	count_words(char const *s, char c)
{
	int		str_count;

	str_count = 0;
	if (ft_strncmp(&c, "", 1) == 0)
		return (str_count);
	while (*s)
	{
		if (!(ft_strchr(s, (int)c)))
			str_count++;
		s++;	
	}
	str_count += 1;
	return (str_count);
}

/* static char	*dup_word(const char *split_str, const char *s, int curr_str_count, int str_count)
{
	char	*new_word;

	new_word = malloc((str_len) + 1);
	if (!(split_str[curr_str_count]))
	{
		free_array(split_str, str_count);
		return (NULL);
	}
	else
	{
		ft_strlcpy(split_str[curr_str_count], s, str_len);
		curr_str_count++;
		s = nxt_delimit + 1;
		nxt_delimit = ft_strchr(s, c);
	}
} */

char	**ft_split(const char *s, char c)
{
	char	**split_str;
	char	*nxt_delimit;
	int		str_count;
	int		curr_str_count;

	printf("starting split\n");
	if (!s)
		return (NULL);
	str_count = count_words(s, c);
	if (str_count == 0 || ft_strncmp(&c, "", 1) == 0)
	{
		split_str = malloc(sizeof(char *) + 1);
		split_str[0] = ft_strdup(s);
		return (split_str); // potentially move this out?
	}
	else 
	{
		split_str = malloc((str_count + 1) * sizeof(char *));
		nxt_delimit = ft_strchr(s, c);
		while (curr_str_count < str_count)
		{
			split_str[curr_str_count] = malloc((nxt_delimit - s) + 1);
			if (!(split_str[curr_str_count]))
			{
				free_array(split_str, str_count);
				return (NULL);
			}
			else
			{
				ft_strlcpy(split_str[curr_str_count], s, nxt_delimit - s);
				curr_str_count++;
				s = nxt_delimit + 1;
				nxt_delimit = ft_strchr(s, c);
			}
		}
		split_str[str_count] = (char *)0;
		return (split_str);
	}
}

/* #include <string.h>
#include <stdio.h>
#include <assert.h>

int	main(void)
{
	char	str1[] = "a,b,c";
	char	delimit1 = ',';
	char	*expected1[] = {"a", "b", "c", NULL};
	char	**results1 = ft_split(str1, delimit1);
	if (!results1)
		printf("results1 is null\n");
	else
	{
		assert(strcmp(results1[0], expected1[0]) == 0);
		assert(strcmp(results1[1], expected1[0]) == 0);
		assert(strcmp(results1[2], expected1[0]) == 0);
		assert(!(results1[3]));
	}
    
    printf("All tests passed!\n");
    return 0;
}
 */