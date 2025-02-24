/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:00:52 by quentin           #+#    #+#             */
/*   Updated: 2024/11/06 12:38:10 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr) 
{
    int i = 0;
    int sign = 1;
    int result = 0;

    
    while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\v') 
	{
        i++;
    }

    if (nptr[i] == '-') 
	{
        sign = -1;
        i++;
    } 
	else if (nptr[i] == '+') 
	{
        i++;
    }

    while (nptr[i] >= '0' && nptr[i] <= '9') 
	{
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
	return result * sign;
}

/*int main (void)
{
    const char *nptr1 = "12345";
    const char *nptr2 = "   -42";
    const char *nptr3 = "42abc";

    printf("%d\n", ft_atoi(nptr1));
    printf("%d\n", ft_atoi(nptr2));
    printf("%d\n", ft_atoi(nptr3));

    return 0;
}*/