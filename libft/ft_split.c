/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:03:51 by jotong            #+#    #+#             */
/*   Updated: 2025/05/12 17:37:18 by jotong           ###   ########.fr       */
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

static int	count_delimits(char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	char	*nxt_delimit;
	int		str_count;
	int		curr_str_count;

	if (!s)
		return (NULL);
	str_count = count_delimits(s, c);
	if (str_count == 0 || ft_strncmp(&c, "", 1) == 0)
	{
		split_str = malloc(sizeof(char *) + 1);
		split_str[0] = ft_strdup(s);
		return (split_str); // potentially move this out?
	}
	else 
	{
		split_str = malloc(str_count * sizeof(char *) + 1);
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
