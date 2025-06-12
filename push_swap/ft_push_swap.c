/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:57:46 by jotong            #+#    #+#             */
/*   Updated: 2025/06/13 01:31:27 by jotong           ###   ########.fr       */
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
#include "globals.h"  // remove this before submission!!!

int	num_ops = 0; // remove this before submission!!!

void push_swap(int *stack, int len, int median)
{
	int	*stack_b;
	int	b_len;

	stack_b = malloc((len + 1) * sizeof(len));
	if (stack_b)
	{
		stack_b[0] = 0;
		split_stack (stack, stack_b, &len, median);
		b_len = ft_arr_len(stack_b);
		// print_stack(stack, &len, 'a');			// remove this before submission.
		// print_stack(stack_b, &b_len, 'b');		// remove this before submission.
		sort_stack (stack, len);
		while (b_len > 0)
			pusha(stack, stack_b, &len, &b_len);
		// print_stack(stack, &len, 'a');			// remove this before submission.
		// print_stack(stack_b, &b_len, 'b');		// remove this before submission.
		free (stack_b);
	}
}

int	get_med(int	*arr, int arr_len)
{
	int	median;
	int	i;

	median = 0;
	i = 0;
	while (i < arr_len)
	{
		if (i == 0)
			median = arr[i];
		else
			median = ((median * i) + arr[i]) / (i + 1);
		i++;
	}
	return (median);
}

int	main(int argc, char **argv)
{
	int			len;
	int			*stack;
	int			median;

	len = argc - 1;
	if (len >= 1)
	{
		stack = malloc((len + 1) * sizeof (int));
		if (stack)
		{
			median = 0;
			if (check_copy_str(&len, stack, argv) == 0 && (check_copy_inputs(len, stack, argv)) == 0)
			{
				write(1, "Error\n", 6);
				return (1);
			}                
			else if (len >= 1 && !check_order(len, stack))
			{                                  
				median = get_med(stack, argc);
				push_swap(stack, len, median);
			}
			free (stack);  // check if this is correct before submission.
		}
		else
			write(1, "Error\n", 6);
	}
	// printf("num ops: %d\n", num_ops);
	return (0);
}
