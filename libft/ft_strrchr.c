/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:27:29 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 23:27:29 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char    convert_to_char(int c)
{
    if (!(c >= 0 && c <= 127))
        return (NULL);
    else
        return (c + '0');
}

char    *ft_strrchr(const char *str, int c)
{
    char    *ptr;
    char    char_c;
    char    *latest;

    ptr = str;
    char_c = convert_to_char(c);
    while (*ptr)
    {
        if (*ptr == char_c)
        {
            latest = ptr;
        }
        ptr++;
    }
    if (c == '\0')
    {
        ptr++;
        return (ptr);
    }
    if (*latest != char_c)
    {
        ptr = NULL;
        return (ptr);
    }
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