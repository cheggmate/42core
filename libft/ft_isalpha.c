/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:56:00 by jotong            #+#    #+#             */
/*   Updated: 2025/05/10 23:59:53 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if (c == 0)
		return (1);
	if (!((c >= 97 && c <= 122) || (c >= 65 && c <= 90)))
		return (0);
	return (1);
}
/*
int     main(void)
{
    int		c = 97;
    int     result;
    
    result = ft_isalpha(c);
    printf("%d\n", result);
    return(0);
}*/
