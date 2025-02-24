/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:18:59 by qbaret            #+#    #+#             */
/*   Updated: 2024/11/05 17:44:35 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int len;

	len = 0;
	while(s[len])
	{
		len++;
	}
	while(len >= 0)
	{
		if (s[len] == (char)c)
			return ((char*)&s[len]);
		len--;
	}
	return(NULL);
}
/*int	main(void)
{
	const char str[] = "Bonjour tout le monde";

	printf("%s\n", ft_strrchr(str, 'o'));
	return (0);
}*/