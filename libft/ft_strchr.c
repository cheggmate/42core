/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:37:43 by jotong            #+#    #+#             */
/*   Updated: 2025/05/10 22:37:36 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static char	convert_to_char(int c)
{
	if (!(c >= 0 && c <= 127))
		return ('0');
	else
		return (c + '\0');
}

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	char	char_c;
	int		is_found;

	is_found = 0;
	ptr = (char *)str;
	char_c = convert_to_char(c);
	while (*ptr)
	{
		if (*ptr == char_c)
			return (ptr);
		ptr++;
	}
	if (c == '\0')
	{
		ptr++;
		is_found = 1;
		return (ptr);
	}
	return ((void *)0);
}
/* int main(void)
{
    int         c;
    const char  str;
    char        *out;

    c = 2;
    out = ft_strchr(&str, c);
    printf("string is %c\n", out);
} */