/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:10:45 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 20:46:32 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *str, char *to_find, int len)
{
	char	*s_space;
	char	*s_term;
    int     pos;

    pos = 0;
	if (*str == '\0' || *to_find == '\0')
		return (str);
	while (*str && pos <= len)
	{
		s_space = str;
		s_term = to_find;
		while (*s_space && *s_term && (*s_space == *s_term))
		{
			s_space++;
			s_term++;
		}
		if (*s_term == '\0')
			return (str);
		str++;
        pos++;
	}
	return (0);
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