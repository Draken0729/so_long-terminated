/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:46:23 by qbaret            #+#    #+#             */
/*   Updated: 2024/11/05 17:53:42 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n && (s1[a] != '\0' || s2[a] != '\0'))
	{
		if (s1[a] != s2[a])
			return s1[a] - s2[a];
		a++;
	}
	return (0);
}

/*int	main()
{
	const char	*s1 = "hellob";
	const char	*s2 = "hello";
	size_t 	n = 6;

	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
}*/
