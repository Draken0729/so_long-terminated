/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:11:43 by qbaret            #+#    #+#             */
/*   Updated: 2024/11/05 17:04:00 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;

	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

/*int	main(void)
{
	const char src[] = "Hello";
	char dest[10];
	const char src1[] = "Hello";
	char dest1[10];

	printf("%ld\n", ft_strlcpy(dest, src, 0));
	printf("dest: %s\n", dest);
	printf("%ld\n", strlcpy(dest1, src1, 0));
	printf("dest: %s\n", dest1);
	return 0;
}*/
