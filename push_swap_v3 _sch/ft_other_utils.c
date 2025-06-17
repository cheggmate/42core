/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:37:28 by jotong            #+#    #+#             */
/*   Updated: 2025/06/16 22:51:35 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_stack(int	*s, int *len, char ab)			// remove this function before submission.
{
	int		i;
	int		*len_ptr;

	i = 0;
	if (ab == 'a' || ab == 'x')
		len_ptr = &len[0];
	else
		len_ptr = &len[1];
	printf("stack %c = ", ab);
	while (i < *len_ptr)
	{
		printf("%d ", s[i]);
		i++;
	}
	printf("\n");
}

int	ft_arr_len(int	*str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] >= INT_MIN && str[i] <= INT_MAX && str[i] != 0)
			i++;
	}
	return (i);
}

int	is_num(char *str)
{
	int	num;
	int	str_len;

	num = ft_atoi(str);
	str_len = ft_strlen(str);
	if (ft_strncmp(ft_itoa(num), str, str_len) != 0)
		return (0);
	else
		return (1);
}

int	find_pos(int *str, int val, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (val < str[i])
			i++;
		else
			return (i);
	}
	return (i);
}
int	find_largest(int *stack, int len)
{
	int	largest;
	int	i;

	largest = 0;
	i = 0;
	while (i < len)
	{
		if (largest < stack[i])
			largest = stack[i];
		i++;
	}
	return (largest);
}
