/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:43:09 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 16:43:09 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
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