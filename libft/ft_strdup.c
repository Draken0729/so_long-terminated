/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:42:11 by quentin           #+#    #+#             */
/*   Updated: 2025/02/25 13:32:32 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s);
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	ft_memcpy(copy, s, len + 1);
	return (copy);
}

/*int main()
{
	const char *source = "Hello, world!";
	char *copy = ft_strdup(source);

	if (copy == NULL) {
		printf("Échec de l'allocation mémoire.\n");
		return (1);
	}

	printf("Source: %s\n", source);
	printf("Copie: %s\n", copy);

	free(copy);

	return (0);
}*/