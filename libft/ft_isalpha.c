/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:56:00 by jotong            #+#    #+#             */
/*   Updated: 2025/05/07 19:04:07 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_isalpha(int c)
{
	if (c == NULL)
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
