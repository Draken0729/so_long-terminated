/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:26 by qbaret            #+#    #+#             */
/*   Updated: 2024/11/12 11:25:19 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	dest_end;
	unsigned int	j;
	unsigned int	src_end;

	dest_end = 0;
	j = 0;
	src_end = 0;
	while (dest[dest_end] != '\0' && dest_end < size)
		dest_end++;
	while (src[src_end] != '\0')
		src_end++;
	if (dest_end == size)
		return (size + src_end);
	j = 0;
	while (src[j] != '\0' && dest_end < size - 1)
	{
		dest[dest_end] = src[j];
		dest_end++;
		j++;
	}
	if (dest_end < size)
		dest[dest_end] = '\0';
	return (dest_end + src_end - j);
}
/*int	main()
{
	char	dest[30] = "bonjour";
	char	src[] = "hello";
	unsigned int	size = 13;
	
	printf("%u\n", ft_strlcat(dest, src, size));
	printf("%s\n", dest);
	return (0);
}*/