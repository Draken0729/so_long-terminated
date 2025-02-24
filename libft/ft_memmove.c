/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:06:40 by qbaret            #+#    #+#             */
/*   Updated: 2024/11/05 14:10:56 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*nd;
	const unsigned char	*ns;

	nd = dest;
	ns = src;
	if (nd > ns && nd < ns + n)
	{
		nd += n;
		ns += n;
		while (n--)
		{
			*(--nd) = *(--ns);
		}
	}
	else
	{
		while (n--)
		{
			*nd++ = *ns++;
		}
	}
	return (dest);
}
/*int	main(void)
{
	char str[] = "Hello, world!";
	memmove(str + 7, str, 5);
	printf("%s\n", str);
	return (0);
}*/