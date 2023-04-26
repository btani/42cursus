/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:33:31 by btani             #+#    #+#             */
/*   Updated: 2023/03/30 16:33:34 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//cerca il n piu piccolo nello stack
int ft_find_min(t_stack *a)
{
    int i;

    i = a->n;
    while (a)
    {
        while (i > a->n)
            i = a->n;
        a = a->next;    
    }   
    return (i);
}

//cerca il n piu grande nello stack
int ft_find_max(t_stack *a)
{
    int i;

    i = a->n;
    while (a)
    {
        while (i < a->n)
            i = a->n;
        a = a->next;
    }
    return (i);
}

//controlla in che indirizzo e' un elemento della lista
int    ft_index(t_stack *a, int n)
{
    int j;
    
    j = 0;
    while (a->n != n)
    {
        j++;
        a = a->next;
    }
    a->index = 0;
    return (j);
}