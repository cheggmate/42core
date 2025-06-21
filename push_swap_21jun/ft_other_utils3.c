/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:10:03 by jotong            #+#    #+#             */
/*   Updated: 2025/06/19 21:10:04 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_ind_max(int *stack_b, int b_len)
{
	int	max;
	int	i;
	int	index;

	i = 0;
	max = stack_b[0];
	while (i++ < b_len)
	{
		if (stack_b[i] > max)
		{
			max = stack_b[i];
			index = i;
		} 
	}
	return (index);
}
