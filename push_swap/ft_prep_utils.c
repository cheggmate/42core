/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:58:46 by jotong            #+#    #+#             */
/*   Updated: 2025/06/15 00:51:18 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


int	prep_values(int len, int *stack, char **argv)
{
	int 	i;

	i = -1;
	while (*stack && i++ < len)
	{
		if (is_num(argv[i + 1]))
		{
			i = 0;
			while (i < len)
			{
				if (stack[i] && stack[i] <= INT_MAX && stack[i] >= INT_MIN && \
					ft_atoi(argv[i + 1]) == stack[i])
					return (0);
				else
					i++;
			}
			stack[i] = ft_atoi(argv[i + 1]);
		}
	}
	return (1);
}

int	prep_string(int len, char **str, int *stack)
{
	char		*str_check;
	int			i;
	long		to_save;

	i = -1;
	to_save = 0;
	if (!stack)
	{
		free (stack);
		return (0);
	}
	while (i++ < len - 1)
	{
		str_check = ft_itoa(ft_atoi(str[i]));
		to_save = ft_atoi(str[i]);
		if (to_save > INT_MAX && to_save < INT_MIN && \
			ft_strncmp(str_check, str[i], ft_strlen(str[i]))!= 0)
			return (0);
		else
			stack[i] = (int)to_save;  // stack[i] = ft_atoi(str[i]);
		free (str_check);
	}
	free (str);
	return (1);
}

