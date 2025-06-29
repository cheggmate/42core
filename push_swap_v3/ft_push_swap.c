/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:57:46 by jotong            #+#    #+#             */
/*   Updated: 2025/06/29 18:06:58 by jotong           ###   ########.fr       */
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

int push_swap(int *stack, int *len)
{
	int	*stacks[2];
	int	*copy;
	static int	iter = 0;		// remove later
	int	**counts;

	len[1] = 0;
	if (len[0] > 1 && !check_order(len[0], stack))
	{
		stacks[1] = malloc(len[0] * sizeof(int));
		copy = malloc(len[0] * sizeof(int));
		if (stacks[1] && copy)
		{
			stacks[1][0] = 0;
			stacks[0] = stack;
			replace_with_rank(stacks[0], len[0], copy);
			stacks[0] = copy;
			printf("before sorting\n");
			print_stack(stacks[0], len, 'a');			// remove this before submission.
			counts = presort_stack(stacks, len, len[0], iter);
			if (!counts)
				return (0);
			int j;
			j = 0;
			while (j < counts[0][0])
			{
				printf("counts[%d][0] = %d\n", j, counts[j][0]);
				printf("counts[%d][1] = %d\n", j, counts[j][1]);
				printf("counts[%d][2] = %d\n", j, counts[j][2]);
				j++;
			}
			printf("sorting back\n");
			sort_back(stacks, len, counts, &iter);
			// ft_sort_b(stacks, len, counts, iter);								// this needs to change one instance of count later counts[3] for example.
			// ft_sort_a(stacks, len, sml_bg, len[0], iter);					// remoive iter
			printf("after sorting\n");
			fflush(stdout);
			print_stack(stacks[0], len, 'a');			// remove this before submission.
			print_stack(stacks[1], len, 'b');		// remove this before submission.
			fflush(stdout);
			free (stacks[1]);
			free (copy);
			free (counts);
		}
		if (!stacks[1])
			return (0);
	}
	return (1);
}

int	pswap_for_int(int *len, char **argv)
{
	int			*stack;
	int			result;

	result = 0;
	stack = malloc ((len[0] + 1) * sizeof(int));
	if (stack)
	{
		result = prep_values(len[0], stack, argv);
		// print_stack(stack, len, 'a');
		if (result == 1)
			result = check_dups(stack, len[0]);
		if (result == 0)
			return (0);
		// print_stack(stack, len, 'a');
		result = push_swap(stack, len);
		if (!stack || result == 0)
			return (0);
		return (1);
	}
	free(stack);
	return (0);
}

int	pswap_for_string(int *len, char **argv)
{
	int			*stack;
	char		**str;
	int			result;

	result = 0;
	stack = NULL;
	str = ft_split_count(argv[1], ' ', len);
	stack = malloc ((len[0] + 1) * sizeof(int));
	if (stack)
	{
		result = prep_string(len[0], str, stack);
		if (result == 1)
			result = check_dups(stack, len[0]);
		// print_stack(stack, len, 'a');
		if (result == 0)
			return (0);
		result = push_swap(stack, len);
		if (result == 0)
			return (0);
		free(stack);
		free_entire_str_array(str);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	len[2];
	int	result;

	setvbuf(stdout, NULL, _IONBF, 0);
	result = 0;
	len[0] = argc - 1;
	if (argc == 2)
	{
		// printf("inputs; %s\n", argv[1]);
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

