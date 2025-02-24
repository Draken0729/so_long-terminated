/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:38:48 by quentin           #+#    #+#             */
/*   Updated: 2025/02/20 18:25:00 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
int	ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
unsigned int	ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;
	int src_len;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[src_len] != '\0')
		src_len++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i);
}
char *ft_strjoin(char *s1, char *s)
{
	size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s);
    char *result = malloc(len1 + len2 + 1);

    if (result == NULL)
        return NULL;

    ft_strcpy(result, s1);

    ft_strcat(result, s);

    return result;
}
/*int main()
{
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *joined = ft_strjoin(s1, s2);

    if (joined != NULL)
    {
        printf("%s\n", joined);  // Affiche : Hello, world!
        free(joined);            // Libère la mémoire allouée
    }

    return 0;
}*/