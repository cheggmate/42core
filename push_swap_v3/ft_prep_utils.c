/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:58:46 by jotong            #+#    #+#             */
/*   Updated: 2025/06/29 22:37:09 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	prep_values(int len, int *stack, char **argv)
{
	int 	i;
	int		to_save;
	char	*str_chk;

	i = -1;
	if (!stack)
		return (0);
	if (is_num(argv[1]))
	{
		while (i++ < len - 1)
		{
			to_save = ft_atoi(argv[i + 1]);
			str_chk = ft_itoa(to_save);
			if (to_save > INT_MAX || to_save < INT_MIN || to_save == 0 || \
				ft_strncmp(str_chk, argv[i + 1], ft_strlen(argv[i + 1])) != 0)
				return (0);
			else
				stack[i] = to_save;
		}
		return (1);
	}
	return (0);
}

int	prep_string(int len, char **str, int *stack)
{
	char		*str_check;
	int			i;
	long		to_save;

	i = -1;
	to_save = 0;
	if (!stack)
		return (0);
	while (i++ < len - 1)
	{
		str_check = ft_itoa(ft_atoi(str[i]));
		to_save = ft_atoi(str[i]);
		if (to_save > INT_MAX || to_save < INT_MIN || to_save == 0 || \
			ft_strncmp(str_check, str[i], ft_strlen(str[i]))!= 0)
			return (0);
		else
			stack[i] = (int)to_save;
		free (str_check);
	}
	return (1);
}

