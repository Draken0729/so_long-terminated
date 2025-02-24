/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:15:55 by quentin           #+#    #+#             */
/*   Updated: 2024/11/12 10:10:17 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n) 
{
    unsigned char *ptr = s;
    while (n--) 
	{
        *ptr++ = (unsigned char)c;
    }
    return s;
}

void *ft_calloc(size_t num, size_t size)
{
	size_t total_size = num * size;

    void *ptr = malloc(total_size);

    if (ptr == NULL) 
	{
        return NULL;
    }

    ft_memset(ptr, 0, total_size);

    return ptr;
}
/*int main() 
{
    int *array;
    size_t num_elements = 5;

    array = (int *)ft_calloc(num_elements, sizeof(int));

    if (array == NULL) 
	{
        printf("Échec de l'allocation mémoire.\n");
        return 1;
    }

    for (size_t i = 0; i < num_elements; i++) 
	{
        printf("array[%zu] = %d\n", i, array[i]);
    }
	
    free(array);

    return 0;
}*/
