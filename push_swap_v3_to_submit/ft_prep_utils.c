/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:58:46 by jotong            #+#    #+#             */
/*   Updated: 2025/07/04 23:51:17 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	prep_values(t_stack *stack, char **argv)
{
	int		i;
	int		to_save;
	char	*str_chk;

	i = -1;
	if (!stack->stack_a)
		return (0);
	if (is_num(argv[1]))
	{
		while (i++ < stack->len_a - 1)
		{
			to_save = ft_atoi(argv[i + 1]);
			str_chk = ft_itoa(to_save);
			if (to_save > INT_MAX || to_save < INT_MIN || to_save == 0
				|| ft_strncmp(str_chk, argv[i + 1],
					ft_strlen(argv[i + 1])) != 0)
				return (0);
			else
				stack->stack_a[i] = to_save;
		}
		return (1);
	}
	return (0);
}

int	prep_string(t_stack *stack, char **str)
{
	char		*str_check;
	int			i;
	long		to_save;

	i = -1;
	to_save = 0;
	if (!stack->stack_a)
		return (0);
	while (i++ < stack->len_a - 1)
	{
		str_check = ft_itoa (ft_atoi (str[i]));
		to_save = ft_atoi(str[i]);
		if (to_save > INT_MAX || to_save < INT_MIN || to_save == 0
			|| ft_strncmp (str_check, str[i], ft_strlen (str[i])) != 0)
			return (0);
		else
			stack->stack_a[i] = (int)to_save;
		free (str_check);
	}
	return (1);
}
