/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:57:46 by jotong            #+#    #+#             */
/*   Updated: 2025/07/05 21:11:47 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	init_entities(t_stack *stack, int **copy,
	t_list_ops **curr, int **sml_bg)
{
	stack->stack_b = (int *)ft_calloc(stack->len_a, sizeof(int));
	*copy = (int *)ft_calloc((stack->len_a + 1), sizeof(int));
	*curr = ft_lstnew_ops("x", stack->len_a);
	*sml_bg = (int *)ft_calloc(2, sizeof(int));
	if (!(stack->stack_b) || !(*copy) || !(*curr) || !(*sml_bg))
	{
		if (stack->stack_b)
			free(stack->stack_b);
		if (*copy)
			free(*copy);
		if (*curr)
			free(*curr);
		if (*sml_bg)
			free(*sml_bg);
		return (0);
	}
	return (1);
}

int push_swap(t_stack *stack)
{
	int			*copy;
	int			**counts;
	t_list_ops	*curr;
	int			*sml_bg;

	stack->len_b = 0;
	if (stack->len_a > 1 && !check_order(stack->len_a, stack->stack_a))
	{
		if (!init_entities(stack, &copy, &curr, &sml_bg))
			return (0);
		replace_with_rank(stack->stack_a, stack->len_a, copy);
		free (stack->stack_a);
		stack->stack_a = copy;
		counts = presort_stack(stack, curr, sml_bg);
		if (!counts)
			return (0);
		// printf("after presort\n");
		// print_stack(stack, 'a');
		// print_stack(stack, 'b');
		sort_back(stack, curr, counts);
		optimise_list(curr);
		ft_print_lst(curr);
		// printf("after all sorting\n");
		// print_stack(stack, 'a');
		fflush(stdout);//remove before submission
		free (stack->stack_b);
		ft_lstclear_ops(curr);
		free_entire_array(counts, counts[0][0]);
	}
	return (1);
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
		if (argc == 1)
			return (0);
		else if (argc == 2)
			result = pswap_for_string(stack, argv);
		else if (argc > 2)
			result = pswap_for_int(stack, argv);
		if (result == 0)
			write(2, "Error\n", 6);
		free(stack->stack_a);
		free(stack);
	}
	return (0);
}
