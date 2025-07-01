/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:57:46 by jotong            #+#    #+#             */
/*   Updated: 2025/07/02 00:22:30 by jotong           ###   ########.fr       */
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

// static int	push_swap_helper(int **stacks, int *len_smlbg, int *copy, int **counts)
// {
	
// 	return (1);
// }

int push_swap(t_stack *stack)
{
	int			*copy;
	int			**counts;
	t_list_ops	*curr;

	stack->len_b = 0;
	if (stack->len_a > 1 && !check_order(stack->len_a, stack->stack_a))
	{
		stack->stack_b = (int *)ft_calloc(stack->len_a, sizeof(int));
		copy = (int *)ft_calloc((stack->len_a + 1), sizeof(int));
		curr = malloc(sizeof(t_list_ops));
		if (stack->stack_b && copy)
		{
			stack->stack_b[0] = 0;
			replace_with_rank(stack->stack_a, stack->len_a, copy);
			stack->stack_a = copy;
			print_stack(stack, 'a');
			printf("-------\n");
			curr->len = stack->len_a;
			curr->op_type = "x";
			counts = presort_stack(stack, curr);
			if (!counts)
				return (0);
			sort_back(stack, curr, counts);
			print_stack(stack, 'a');
			fflush(stdout);							//remove before submission
			free (stack->stack_b);
			free (copy);
			free_entire_array(counts, counts[0][0]);
		}
		if (!stack->stack_b)
			return (0);
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
			// free_everything(str, stack->stack_a);
			free(str);
			return (0);
		}
		result = push_swap(stack);
		// free_everything(str, stack->stack_a);
		free(str);
		if (result == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		result;
	t_stack	*stack;

	setvbuf(stdout, NULL, _IONBF, 0);
	result = 0;
	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->len_a = argc - 1;
		if (argc == 2)
			result = pswap_for_string(stack, argv);
		else if (argc != 1)
			result = pswap_for_int(stack, argv);
		if (argc == 1 || result == 0)
			write(2, "Error\n", 6);
		free(stack);
	}
	return (0);
}

