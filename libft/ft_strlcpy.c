/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:40:10 by jotong            #+#    #+#             */
/*   Updated: 2025/05/05 22:31:37 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (size == 0)
		return (i);
	/* while (*dest)
	{
		dest++;
		len++;
	} */
	while (*src && len + i < size)
	{
		*dest = *src;
		dest++;
		src++;
		len++;
		i++;
	}
	*dest = '\0';
	return (i);
}
/*
int	main(void)
{
	char 			src[] = "HELLO THERE";
	char 			dest[100] = "HEY,";
	unsigned int	size = 100;
	unsigned int	out = 0;

	out = ft_strlcpy(dest, src, size);
	printf("out = %i", out);
	return(0);
}*/