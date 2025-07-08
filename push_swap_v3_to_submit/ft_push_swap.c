/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:57:46 by jotong            #+#    #+#             */
/*   Updated: 2025/07/08 13:32:17 by jotong           ###   ########.fr       */
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

int	push_swap(t_stack *stack)
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
		sort_back(stack, curr, counts);
		optimise_list(curr);
		ft_print_lst(curr);
		free (stack->stack_b);
		ft_lstclear_ops(curr);
		free_entire_array(counts, counts[0][0]);
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
			free_entire_str_array(str);
			return (0);
		}
		result = push_swap(stack);
		free_entire_str_array(str);
		if (result == 0)
			return (0);
		return (1);
	}
	free_entire_str_array(str);
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
		free(stack->stack_a);
		free(stack);
	}
	return (0);
}
