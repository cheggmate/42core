/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:10:45 by jotong            #+#    #+#             */
/*   Updated: 2025/05/16 01:02:14 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* static char	*search_str(const char *s_space, const char *s_term, size_t len, size_t *pos)
{
	size_t	str_len = 0;

	while (*s_space && *s_term && \
		(*s_space == *s_term) && (*pos + str_len) < len)
	{
		s_space++;
		s_term++;
		str_len++;
	}
	if (*s_term == '\0')
		return ((char *)s_space);
	return (NULL);
} */

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char		*s_space;
	char		*s_term;
	size_t		pos;
	size_t		str_len;

	pos = 0;
	if (*str == '\0')
	{
		if (*to_find == '\0')
			return ((char *)str);
		else
			return (NULL);
	}
	while (*str && pos <= len)
	{
		str_len = 0;
		s_space = (char *)str;
		s_term = (char *)to_find;
		while (*s_space && *s_term && \
			(*s_space == *s_term) && (pos + str_len) < len)
		{
			s_space++;
			s_term++;
			str_len++;
		}
		if (*s_term == '\0')
			return ((char *)str);
		str++;
        pos++;
	}
	return (NULL);
}
/* 
#include <stdio.h>
#include <string.h>
int     main(void)
{
    char    str1[] = "hello, ";
    char    str2[] = "hello, world";
    char    *result;

    result = ft_strnstr(str2, str1);
	if (result)
   		printf("%s\n", result);
	result = strstr(str2, str1);
	if (result)S
		printf("control: %s\n", result);
    return(0);
} */