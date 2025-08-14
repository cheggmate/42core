/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:39:19 by jotong            #+#    #+#             */
/*   Updated: 2025/08/06 15:57:05 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char		*arr;

	arr = NULL;
	if (num <= 0 || size <= 0)
		return (malloc(0));
	if (num == (size_t)INT_MAX || size == (size_t)INT_MAX)
		return (NULL);
	if ((num > 0 && size > SIZE_MAX / num) || (num * size) / num != size)
		return (NULL);
	arr = malloc(num * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, (num * size));
	return (arr);
}

int	check_is_num(char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (!str)
		return (0);
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str)
	{
		printf("checking %c\n", *str);
		if (*str == '+' || *str == '-' || !(*str >= '0' && *str <= '9'))
			return (-1);
		num *= 10;
		num += *str - '0';
		str++;
	}
	num *= sign;
	return (num);
}

int	check_num_limits(int num)
{
	if (num > 0 || num <= INT_MAX)
		return (0);
	else if (num == 0)
		return (1);
	else
		return (-1);
}

// int	ft_atoi(const char *str)
// {
// 	unsigned int	final_int;
// 	int				sign;
// 	unsigned char	*ptr;

// 	ptr = (unsigned char *)str;
// 	final_int = 0;
// 	sign = 1;
// 	while (*ptr == '\t' || *ptr == '\n' || *ptr == '\v'
// 		|| *ptr == '\f' || *ptr == '\r' || *ptr == ' ')
// 		ptr++;
// 	if ((*ptr == '-' || *ptr == '+'))
// 	{
// 		if (*ptr == '-')
// 			sign *= -1 ;
// 		ptr++;
// 	}
// 	while (*ptr >= '0' && *ptr <= '9')
// 	{
// 		final_int = final_int * 10 + *ptr - '0';
// 		ptr++;
// 	}
// 	return (final_int * sign);
// }

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			count;
	unsigned char	*dest;

	count = 0;
	dest = (unsigned char *)ptr;
	while (count < num)
	{
		dest[count] = value;
		count++;
	}
	return (ptr);
}


void	print_safely(t_phil *phil)
{
	pthread_mutex_lock(&phil->tb->print);
	if (phil)
	{
		if (phil->state == 'e')
			printf("%lld %d is eating\n", get_time(), phil->n);
		else if (phil->state == 's')
			printf("%lld %d is sleeping\n", get_time(), phil->n);
		else if (phil->state == 't')
			printf("%lld %d is thinking\n", get_time(), phil->n);
		else if (phil->state == 'f')
			printf("%lld %d has taken a fork\n", get_time(), phil->n);
		else if (phil->state == 'd')
			printf("%lld %d died\n", get_time(), phil->n);
	}
	pthread_mutex_unlock(&phil->tb->print);
	return ;
}
