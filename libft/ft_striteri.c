/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:48:05 by quentin           #+#    #+#             */
/*   Updated: 2024/11/08 11:01:33 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*int	ft_toupper(int c)
{
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
	}
	return (c);
}
void to_upper_if_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = ft_toupper(*c);
}
int main()
{
	char str[] = "hello world!";
	ft_striteri(str, to_upper_if_even);
	printf("%s\n", str);
	return 0;
}*/