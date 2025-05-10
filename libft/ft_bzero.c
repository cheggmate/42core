/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:31:21 by jotong            #+#    #+#             */
/*   Updated: 2025/05/09 17:17:50 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	int		count;

	ptr = s;
	count = 1;
	while (*ptr && (count <= n))
	{
		*ptr = 0;
		ptr++;
		count++;
	}
}
/* 
int main(void)
{
    int     val = 2;
    char    buffer[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    typedef struct {
        int a;
        float b;
    } Data;
    Data    d = {42, 3.14};

    // printf("before\n");
    // for (int i = 0; i < 10; i++) {
    //     printf("%d ", buffer[i]);
    // }
    // printf("\n");
    // ft_bzero(&buffer, val);
    // for (int i = 0; i < 10; i++) {
    //     printf("%d ", buffer[i]);
    // }
    ft_bzero(&d, sizeof(d));
    printf("d.a is %d\n", d.a);
    printf("d.b is %f\n", d.b);
} */