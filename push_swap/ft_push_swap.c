/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:57:46 by jotong            #+#    #+#             */
/*   Updated: 2025/06/14 00:21:15 by jotong           ###   ########.fr       */
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

void push_swap(int *stack, int len, double median)
{
	int	*stack_b;
	int	b_len;

	if (len > 1 && !check_order(len, stack))
	{
		median = find_median(stack, len);
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
}

int	prep_values(int len, int *stack, char **argv)
{
	int i;

	i = 0;
	while (*stack && i++ < len)
	{
		if (is_num(argv[i + 1]))
		{
			i = 0;
			while (i < len)
			{
				if (stack[i] && ft_atoi(argv[i + 1]) == stack[i])
					return (0);
				else
					i++;
			}
			stack[i] = ft_atoi(argv[i + 1]);
		}
	}
	return (1);
}

int	prep_string(int len, char **str, int *stack)
{
	char		*str_check;
	int			i;

	i = -1;
	if (!stack)
	{
		free (stack);
		return (0);
	}
	while (i++ < len - 1)
	{
		str_check = ft_itoa(ft_atoi(str[i]));
		if (ft_strncmp(str_check, str[i], ft_strlen(str[i]))!= 0)
			return (0);
		else
			stack[i] = ft_atoi(str[i]);
		free (str_check);
	}
	free (str);
	return (1);
}

int	main(int argc, char **argv)
{
	int			len;
	int			*stack;
	double		median;
	char		**str;

	len = 0;
	median = 0.0;
	stack = NULL;
	if (argc == 2)
	{
		str = ft_split_count(argv[1], ' ', &len);
		stack = malloc ((len + 1) * sizeof(int));
		if (stack)
			prep_string(len, str, stack);
	}
	else if (argc != 1)
	{
		stack = malloc ((len + 1) * sizeof(int));
		if (stack)
			prep_values(argc, &len, argv);
	}
	push_swap(stack, len, median);
	if (argc == 1 || !stack)
		write(2, "Error\n", 6);
	// printf("num ops: %d\n", num_ops);
	return (0);
}
