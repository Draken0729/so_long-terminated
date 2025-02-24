/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:06:26 by quentin           #+#    #+#             */
/*   Updated: 2024/11/08 11:20:43 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	int i;

	if (!s)
		return;
	
	i = 0;
	while(s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*int main ()
{
	ft_putstr_fd("bonjour\n", 1);
	ft_putstr_fd("toi\n", 2);
    return 0;
}*/