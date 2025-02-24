/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:10:59 by quentin           #+#    #+#             */
/*   Updated: 2024/11/06 11:56:19 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t j;
	size_t i;

	j = 0;
	i = 0;
	if (needle[i] == '\0')
			return ((char*)haystack);
	while (i < len && haystack[i] != '\0') 
	{
		i++;
        if (haystack[i] == needle[0]) 
		{ 
    			while (haystack[i + j] == needle[j] && (i + j) < len)
				{
						j++;
						if (needle[j] == '\0')
							return (char *)&haystack[i];
							
				}
		}

	}
	return(NULL);
}

/*int main(void) 
{
    const char *haystack = "Hello, world!";
    const char *needle = "kogk";
    size_t len = 7;

    char *result = ft_strnstr(haystack, needle, len);
    if (result) {
        printf("Sous-chaîne trouvée : %s\n", result);
    } else {
        printf("Sous-chaîne non trouvée dans la limite spécifiée.\n");
    }
    return 0;
}*/