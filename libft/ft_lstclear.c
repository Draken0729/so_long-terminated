/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:40:20 by quentin           #+#    #+#             */
/*   Updated: 2024/11/08 15:46:34 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *current;
    t_list *next_node;

    if (!lst || !del)
        return;

    current = *lst;
    while (current)
    {
        next_node = current->next;    // Sauvegarde du nœud suivant
        del(current->content);        // Libère le contenu du nœud courant
        free(current);                // Libère le nœud lui-même
        current = next_node;          // Passe au nœud suivant
    }
    *lst = NULL; // Met la tête de la liste à NULL pour indiquer que la liste est vide
}