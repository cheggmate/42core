/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:27:29 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 21:04:43 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	char	*latest;

	ptr = (char *)str;
	latest = (void *)0;
	while (*ptr)
	{
		if (*ptr == c)
			latest = ptr;
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	else if (!latest)
		return ((void *)0);
	else
		return (latest);
}
/* #include <stdio.h>
int main(void)
{
	int		input10 = '!';
	char	search10[] = "C is fun!";
	char	*result10 = ft_strrchr(search10, input10);
    printf("result10 is %c\n", *result10);
} */