/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:42:11 by quentin           #+#    #+#             */
/*   Updated: 2025/02/20 18:29:40 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s) 
{
    size_t len = ft_strlen(s);
    char *copy = (char *)malloc(len + 1); 

    if (copy == NULL)
	{
		return NULL;
    }

    ft_memcpy(copy, s, len + 1);
    return copy;
}

/*int main() 
{
    const char *source = "Hello, world!";
    char *copy = ft_strdup(source);

    if (copy == NULL) {
        printf("Échec de l'allocation mémoire.\n");
        return 1;
    }

    printf("Source: %s\n", source);
    printf("Copie: %s\n", copy);

    free(copy);

    return 0;
}*/