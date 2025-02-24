/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:28:51 by qbaret            #+#    #+#             */
/*   Updated: 2024/11/06 10:37:59 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	
	d = dest;
	s = src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
/*int	main(void)
{
	char src[10] = "OpenAI";
	char dest[10];

	memcpy(dest, src, sizeof(src));

	printf("Source : %s\n", src);
	printf("Destination : %s\n", dest);

	return (0);
}*/