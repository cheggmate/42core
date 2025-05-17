/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:10:45 by jotong            #+#    #+#             */
/*   Updated: 2025/05/17 15:34:59 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char		*hay;
	char		*needle;
	size_t		pos;
	size_t		str_len;

	pos = 0;
	if (*str == '\0' && *to_find == '\0')
		return ((char *)str);
	else if (*str == '\0')
		return (NULL);
	while (*str && pos <= len)
	{
		str_len = 0;
		hay = (char *)str;
		needle = (char *)to_find;
		while (*hay && *needle && (*hay == *needle) && (pos + str_len) < len)
		{
			hay++;
			needle++;
			str_len++;
		}
		if (*needle == '\0')
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