/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort_logic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:27:07 by jotong            #+#    #+#             */
/*   Updated: 2025/06/10 10:47:50 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	split_stack(int *stack, int  *stack_b, int len, int median)
{
	int	i;
	int	b_len;

	i = 0;
	b_len = 0;
	while (i < len)
	{
		if (stack[i] > median)
			pushb(stack_b, stack, &len, &b_len);
		else
			i++;
	}
}

void	sort_stack(int *stack, int  *stack_b, int len, int median)
{
	
}
