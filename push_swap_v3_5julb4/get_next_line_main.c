/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:21:09 by jotong            #+#    #+#             */
/*   Updated: 2025/07/05 17:23:33 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	process_bytes_read(ssize_t bytes_read, t_stack *stack)
{
	if (bytes_read = )
}

int	main(int argc, char **argv)
{
	ssize_t	*bytes_read;
	t_stack	*stack;
	int		result;

	result = 0;
	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		bytes_read = get_next_line(0);
		while (bytes_read)
		{
			process_bytes_read(bytes_read, stack);
			bytes_read = get_next_line(0);
		}
		if (is_sorted(stack->stack_a, stack->len_a))
			write(1, "OK\n", 3);
		else
			write(2, "KO\n", 3);
	}
	return (0);
}
