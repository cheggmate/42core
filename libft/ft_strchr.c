/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:37:43 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 21:10:49 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (c == '\0')
	{
		ptr++;
		return (ptr);
	}
	return ((void *)0);
}
/* #include <stdio.h>
int main(void)
{
    int		input2 = 'l';
	char	search2[] = "hello";
	char	*result2 = ft_strchr(search2, input2);
    printf("string is %c\n", *result2);
} */