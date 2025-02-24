/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:53:55 by quentin           #+#    #+#             */
/*   Updated: 2024/11/08 15:32:41 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *current;

    if (!new)
        return;

    if (!*lst)
    {
        *lst = new;
        return;
    }

    current = *lst;
    while (current->next)
        current = current->next;

    current->next = new;
}