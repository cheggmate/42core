/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:27:29 by jotong            #+#    #+#             */
/*   Updated: 2025/05/10 23:25:07 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char    convert_to_char(int c)
{
    if (!(c >= 0 && c <= 127))
        return ('\0');
    else
        return (c + '0');
}

char    *ft_strrchr(const char *str, int c)
{
    char    *ptr;
    char    char_c;
    char    *latest;

    ptr = (char *)str;
	latest = NULL;
    char_c = convert_to_char(c);
    while (*ptr)
    {
		printf("checking ptr (%c) against c\n", *ptr);
        if (*ptr == char_c)
            latest = ptr;
        ptr++;
    }
	printf("latest is now pointing to %c\n", *latest);
	printf("the while loop is completed\n");
    if (c == '\0')
	{
		printf("first if cause hit\n");
		return (ptr);
	}
        
    else if (latest == NULL || *latest != char_c)
    {
		printf("trying to check if the charc is a match\n");
        return ((void *)0);
    }
	printf("else clause\n");
    return (latest);
}
/* int main(void)
{
    char        *out;
    const char  str[] = "testz";
    int         c;

    c = 97;
    out = ft_strrchr(&str, c);
    printf("out is %c\n", out);
} */