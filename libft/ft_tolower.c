/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:55:02 by qbaret            #+#    #+#             */
/*   Updated: 2024/11/08 13:45:24 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	{
		if (c >= 'A' && c <= 'Z')
			return (c + 32);
	}
	return (c);
}

/*int main(void) 
{
    char upper = 'A';
	
	printf("%c\n", ft_tolower(upper));
	return 0;
}*/