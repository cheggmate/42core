/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:39:44 by jotong            #+#    #+#             */
/*   Updated: 2025/06/14 00:25:28 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "globals.h"			// remove before submission!

int	check_order(int len, int *stack)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		// printf("checking %d\n", i);
		// printf("stack[0] = %d\n", stack[0]);
		// printf("stack1 = %d\n", stack[1]);
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	printf("finished check order\n");
	return (1);
}

// int	check_copy_str(int *len, int *stack, char **argv)
// {
// 	int		i;
// 	char	**str;
// 	char	*str_check;
// 	i = 0;
// 	if (*len == 1)
// 	{
// 		str = ft_split_count(argv[1], ' ', len);
// 		stack = create_check_stack(stack, *len);
// 		while (i < *len)
// 		{
// 			str_check = ft_itoa(ft_atoi(str[i]));
// 			if (ft_strncmp(str_check, str[i], ft_strlen(str[i]))!= 0)
// 				return (0);
// 			else
// 				stack[i] = ft_atoi(str[i]);
// 			free (str_check);
// 			i++;
// 		}
// 		free (str);
// 		return (1);
// 	}
// 	return (0);
// }
