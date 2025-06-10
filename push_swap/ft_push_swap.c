/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:57:46 by jotong            #+#    #+#             */
/*   Updated: 2025/06/10 09:31:31 by jotong           ###   ########.fr       */
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

void push_swap(int *stack, int len, int argc, int median)
{
	int	*stack_b;

	stack_b = (int)malloc((len + 1) * sizeof(len));
	if (stack_b)
	{
		stack_b[0] = 0;
		split_stack (stack, stack_b, len, median);
		sort_stack (stack, stack_b, len, median);
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
			median = ((median * i - 1) + arr[i]) / i;
		i++;
	}
	return (median);
}

int	check_inputs(int *len, int argc, int *stack, char **argv)
{
	int	counter;


	counter = 0;
	while (len < argc - 1)
	{
		if (!ft_isalpha((int)argv[*len][0]))
			stack[counter] = argv[*len][0] - '0';
		else
			return (0);
		*len++;
		counter++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			len;
	int			*stack;
	int			median;

	len = 1;
	if (argc > 1)
	{
		stack = (int *)malloc((argc) * sizeof (int));
		if (stack)
		{
			if (!(check_inputs(&len, argc, stack, argv)))
				write(1, "Error\n", 6);
			else if (len > 1)
			{
				median = get_med(stack, argc);
				push_swap(stack, len, argc, median); // TODO: Add a extra median to use as the pivot
			}
			free (stack);  // check if this is correct before submission.
		}
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
