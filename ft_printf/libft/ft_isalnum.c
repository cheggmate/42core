/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:10:26 by jotong            #+#    #+#             */
/*   Updated: 2025/05/11 20:47:31 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if (c == 0)
		return (0);
	if (!((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || \
	(c >= 97 && c <= 122)))
		return (0);
	return (1);
}
/* #include <stdio.h>
int	main(void)
{
	char	input[10] = "test";
	int		out;

	out = ft_isalnum(&input);
	printf("result is %d\n", out);
} */