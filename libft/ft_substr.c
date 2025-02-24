/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:37:08 by quentin           #+#    #+#             */
/*   Updated: 2024/11/07 11:09:22 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t ts;
	size_t i;
	char *substr;

	ts = 0;
	i = 0;
	while (s[ts])
	{
		ts++;
	}
	
	if (start >= ts)
        return (char *)malloc(1);
	
	if (len > ts - start)
        len = ts - start;
		
	substr = (char *) malloc((len + 1) * sizeof(char));
	while(i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return(substr);
}
/*int main(void)
{
    const char s[] = "bonjour";
    char *new_substr = ft_substr(s, 2, 10);

    if (new_substr != NULL)
    {
        printf("%s\n", new_substr);
        free(new_substr);  // Libérer la mémoire allouée pour éviter les fuites
    }

    return (0);
}*/