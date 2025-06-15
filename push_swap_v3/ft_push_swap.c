/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:57:46 by jotong            #+#    #+#             */
/*   Updated: 2025/06/15 23:27:35 by jotong           ###   ########.fr       */
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

int push_swap(int *stack, int len)
{
	int	*stack_b;
	int	b_len;

	b_len = 0;
	if (len > 1 && !check_order(len, stack))
	{
		stack_b = malloc((len + 1) * sizeof(len));
		if (stack_b)
		{
			stack_b[0] = 0;
			if (len <= 6)
				sort_stack(stack, len);
			else if (len > 6 && len <= 100)		// chunk sort
				start_chunking(stack, stack_b, &len, &b_len);
			else											// Binary radix sort
			{
				
			}
			// printf("stacks after sorting\n");
			// print_stack(stack, &len, 'a');			// remove this before submission.
			// print_stack(stack_b, &b_len, 'b');		// remove this before submission.
			free (stack_b);
		}
		if (!stack_b)
			return (0);
	}
	return (1);
}

int	pswap_for_int(int len, char **argv)
{
	int			*stack;
	int			result;

	result = 0;
	stack = NULL;
	stack = malloc ((len + 1) * sizeof(int));
	if (stack)
	{
		result = prep_values(len, stack, argv);
		print_stack(stack, &len, 'a');
		if (result == 1)
			result = check_dups(stack, len);
		if (result == 0)
			return (0);
		print_stack(stack, &len, 'a');
		result = push_swap(stack, len);
		if (!stack || result == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	pswap_for_string(int len, char **argv)
{
	int			*stack;
	char		**str;
	int			result;

	result = 0;
	stack = NULL;
	str = ft_split_count(argv[1], ' ', &len);
	stack = malloc ((len + 1) * sizeof(int));
	if (stack)
	{
		result = prep_string(len, str, stack);
		if (result == 1)
			result = check_dups(stack, len);
		// print_stack(stack, &len, 'a');
		if (result == 0)
			return (0);
		// print_stack(stack, &len, 'a');
		result = push_swap(stack, len);
		if (result == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			len;
	int	result;

	result = 0;
	len = argc - 1;
	if (argc == 2)
	{
		result = pswap_for_string(len, argv);
	}
	else if (argc != 1)
	{
		result = pswap_for_int(len, argv);
	}
	if (argc == 1 || result == 0)
		write(2, "Error\n", 6);
	return (0);
}
