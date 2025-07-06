/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:58:46 by jotong            #+#    #+#             */
/*   Updated: 2025/07/05 17:01:01 by jotong           ###   ########.fr       */
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

int	pswap_for_int(t_stack *stack, char **argv)
{
	int			result;

	result = 0;
	stack->stack_a = ft_calloc ((stack->len_a + 1), sizeof(int));
	if (stack->stack_a)
	{
		result = prep_values(stack, argv);
		if (result == 1)
			result = check_dups(stack);
		if (result == 0)
			return (0);
		result = push_swap(stack);
		if (!stack || result == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	pswap_for_string(t_stack *stack, char **argv)
{
	char		**str;
	int			result;

	result = 0;
	stack->stack_a = NULL;
	str = ft_split_count(argv[1], ' ', &stack->len_a);
	stack->stack_a = ft_calloc ((stack->len_a + 1), sizeof(int));
	if (stack)
	{
		result = prep_string(stack, str);
		if (result == 1)
			result = check_dups(stack);
		if (result == 0)
		{
			free_entire_str_array(str);
			return (0);
		}
		result = push_swap(stack);
		free_entire_str_array(str);
		if (result == 0)
			return (0);
		return (1);
	}
	free_entire_str_array(str);
	return (0);
}
