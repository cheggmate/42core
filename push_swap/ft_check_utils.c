/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:39:44 by jotong            #+#    #+#             */
/*   Updated: 2025/06/13 01:25:19 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "globals.h"			// remove before submission!

int	check_copy_inputs(int len, int *stack, char **argv)
{
	int	counter;
	int	i;

	counter = 1;
	while (counter <= len)
	{
		if (is_num(argv[counter]))
		{
			i = 0;
			while (i < len)
			{
				if (stack[i] && ft_atoi(argv[counter]) == stack[i])
					return (0);
				else
					i++;
			}
			stack[counter-1] = ft_atoi(argv[counter]);
		}
		else
			return (0);
		counter++;
	}
	return (1);
}

int	check_order(int len, int *stack)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_copy_str(int *len, int *stack, char **argv)
{
	int		i;
	char	**str;
	char	*str_check;

	i = 0;
	if (*len != 1)
		return (0);
	else
	{
		str = ft_split(argv[1], ' ');
		while (str[i])
		{
			str_check = ft_itoa(ft_atoi(str[i]));
			if (str[i] && ft_strncmp(str_check, str[i], ft_strlen(str[i])!= 0))
				return (0);
			else
				stack[i] = ft_atoi(str[i]);
			i++;
		}
		free (str);
		free (str_check);
		*len = i - 1;
		return (1);
	}
}
