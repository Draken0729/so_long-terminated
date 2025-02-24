/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbaret <qbaret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:43 by qbaret            #+#    #+#             */
/*   Updated: 2024/11/05 15:46:35 by qbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
	}
	return (c);
}

/*int main(void) 
{
    char lower = 'a';
	
	printf("%c\n", ft_toupper(lower));
	return 0;
}*/