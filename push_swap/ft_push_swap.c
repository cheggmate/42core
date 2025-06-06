/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:57:46 by jotong            #+#    #+#             */
/*   Updated: 2025/06/07 00:10:34 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allowed functions:
// read 
// write 
// malloc  
// free
// exit 
// ft_printf

// Other things to note:
// - Stack a will contain a list of UNIQUE negative and / or positive integers
// - Stack b is empty

// Operations available: 
// - sa (swap a): Swap the first 2 elements at the top of stack a.
//     Do nothing if there is only one element or none.
// - sb (swap b): Swap the first 2 elements at the top of stack b.
//     Do nothing if there is only one element or none.
// - ss : sa and sb at the same time.
// - pa (push a): Take the first element at the top of b and put it at the top of a.
//     Do nothing if b is empty.
// - pb (push b): Take the first element at the top of a and put it at the top of b.
//     Do nothing if a is empty.
// - ra (rotate a): Shift up all elements of stack a by 1.
//     The first element becomes the last one.
// - rb (rotate b): Shift up all elements of stack b by 1.
//     The first element becomes the last one.
// - rr : ra and rb at the same time.
// - rra (reverse rotate a): Shift down all elements of stack a by 1. 
//     The last element becomes the first one.
// - rrb (reverse rotate b): Shift down all elements of stack b by 1.
//     The last element becomes the first one.
// - rrr : rra and rrb at the same time.	

#include "ft_push_swap.h"

// void ft_push_swap(int *stack, int len)
// {
// 	// int			len;
// 	// int			*stack;

// 	// printf("arc = %d\n", argc);
// 	// printf("argv[1][1] = %d\n", argv[1][1]);
// 	// len = (argc - 1);
// 	// if (len == 0)		// if inputs are not null
// 	// 	write (1, "\n", 1);
// 	// else
// 	// {
// 	// 	// Do something here.
// 	// }
// }

int	main(int argc, char **argv)
{
	int			len;
	int			*stack;
	int			stack_len;
	int			counter;

	stack_len = argc - 1;
	len = 1;
	counter = 0;
	if (argc == 1)
	{
		write (1, "\n", 1);
		return (0);
	}
	else
	{
		stack = (int *)malloc(stack_len * sizeof (int));
		while (len < argc)
		{
			if (!ft_isalpha((int)argv[len][0]))
				stack[counter] = argv[len][0] - '0';
			len++;
			counter++;
		}
		push_swap(stack, stack_len);
	}
}
