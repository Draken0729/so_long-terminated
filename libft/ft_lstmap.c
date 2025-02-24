/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:52:30 by quentin           #+#    #+#             */
/*   Updated: 2024/11/08 16:00:28 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    t_list *new_lst = NULL;
    t_list *new_node;
    void *new_content;

    if (!lst || !f)
        return NULL;

    while (lst)
    {
        new_content = f(lst->content);
        if (!new_content)
        {
            ft_lstclear(&new_lst, del);
            return NULL;
        }
        new_node = ft_lstnew(new_content);
        if (!new_node)
        {
            ft_lstclear(&new_lst, del);
            return NULL;
        }
         ft_lstadd_back(&new_lst, new_node);
		 lst = lst->next;
    }
	return new_lst;
}
