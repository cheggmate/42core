/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:56:00 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 17:12:00 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			return (0);
		str++;
	}
	return (1);
}
/*
int     main(void)
{
    char    *str = "hellAo";
    int     result;
    
    result = ft_isalpha(str);
    printf("%i\n", result);
    return(0);
}*/
