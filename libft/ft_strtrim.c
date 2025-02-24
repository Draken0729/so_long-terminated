/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:12:22 by quentin           #+#    #+#             */
/*   Updated: 2024/11/07 11:41:11 by quentin          ###   ########.fr       */
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

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

	i = 0;
	while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
		i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
		i++;
    }
	return dest;
}
int is_in_set(char c, const char *set)
{
    while (*set)
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

char *strtrim(const char *s1, const char *set)
{
    size_t start = 0;
    size_t end = ft_strlen(s1);

    while (s1[start] && is_in_set(s1[start], set))
        start++;

    while (end > start && is_in_set(s1[end - 1], set))
        end--;

    char *trimmed = (char *)malloc((end - start + 1) * sizeof(char));
    if (!trimmed)
        return NULL;

    ft_strncpy(trimmed, &s1[start], end - start);
    trimmed[end - start] = '\0';

    return trimmed;
}
/*int main(void)
{
    const char *s = "   Hello, world!   ";
    const char *set = " ";
    char *trimmed = strtrim(s, set);

    if (trimmed)
    {
        printf("%s\n", trimmed);
        free(trimmed);
    }

    return 0;
}*/