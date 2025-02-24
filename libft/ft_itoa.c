/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:41:07 by quentin           #+#    #+#             */
/*   Updated: 2024/11/12 10:28:46 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_length(int n)
{
	int	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length = get_num_length(n);
	char	*str = (char *)malloc(sizeof(char) * (length + 1));
	unsigned int num;

	if (!str)
		return (NULL);
	str[length] = '\0';
	if (n < 0) 
    	num = -n;
	else
    	num = n;
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (num != 0)
	{
		str[--length] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/*int main()
{
    int number = -156987452;
    char *str = ft_itoa(number);
    if (str)
    {
        printf("%s\n", str);
        free(str);
    }
    return 0;
}*/