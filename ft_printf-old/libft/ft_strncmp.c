/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:12:53 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 20:48:24 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((*s1 == *s2 && *s1 != '\0' && *s2 != '\0') && i < n -1)
	{
		s1++;
		s2++;
		i++;
	}
	if (n == 0)
		return (0);
	else
		return (*s1 - *s2);
}
/* 
#include <stdio.h>
#include <string.h>
int     main(void)
{
    int     out;
    int     size = 50;
    char    str1[] = "cc";
    char    str2[50] = "world";

    out = ft_strncmp(str1, str2, size);
    printf("%i\n", out);

	out = strncmp(str1, str2, size);
	printf("control: %i\n", out);
    return(0);
} */