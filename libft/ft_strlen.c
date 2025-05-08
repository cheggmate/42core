/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:43:09 by jotong            #+#    #+#             */
/*   Updated: 2025/05/08 21:41:09 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int     count;
	char    *ptr;

	count = 0;
	while (*ptr)
	{
		count++;
		str++;
	}
	return (count);
}
/* 
#include <stdio.h>
int	main(void)
{
	int count;
	char str[] = "abc\0def";

	count = ft_strlen(str);
	printf("count is %i\n", count);
	return (0);
} */