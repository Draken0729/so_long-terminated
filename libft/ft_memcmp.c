/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:20:21 by qbaret            #+#    #+#             */
/*   Updated: 2024/11/06 11:09:33 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if (((unsigned char*)s1)[a] != ((unsigned char*)s2)[a])
			return ((unsigned char*)s1)[a] - ((unsigned char*)s2)[a];
		a++;
	}
	return (0);
}
/*int	main()
{
	const void	*s1 = "hello";
	const void	*s2 = "hellob";
	size_t 	n = 6;

	printf("%d\n", ft_memcmp(s1, s2, n));
	return (0);
}*/
