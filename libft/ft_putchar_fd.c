/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:04:07 by quentin           #+#    #+#             */
/*   Updated: 2024/11/08 13:38:30 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*int main()
{
    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);
    ft_putchar_fd('B', 2); 
    ft_putchar_fd('\n', 2);
    return 0;
}*/