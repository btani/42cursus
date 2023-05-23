/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:58:10 by btani             #+#    #+#             */
/*   Updated: 2023/05/19 17:58:27 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*Funzione che gestisce diversi casi basati sulla relazione
fra il nbr e la testa, l'ultimo elemento, il minimo
e il massimo valore dello stack b e, in base al caso,
determina quali rotazioni sono necessarie o meno e 
calcola la corretta posizione che nbr deve avere in b*/
int ft_finddst_ab(int nbr, t_stack *b, t_vals *vals)
{
    int dest;

    dest = 1;
    if(nbr > b->n && nbr < ft_lst_last(b)->n)
        dest = 0;
    else if (nbr < vals->smallest_b || nbr > vals->biggest_b)
        dest = ft_index(b, vals->biggest_b);
    else
    {
        while (nbr > b->n || nbr < b->n)
        {
            dest++;
            b = b->next;
        }
    }
    return (dest);
}

/*Funzione che gestisce diversi casi basati sulla relazione
fra il nbr e la testa, l'ultimo elemento, il minimo
e il massimo valore dello stack b e, in base al caso,
determina quali rotazioni sono necessarie o meno e 
calcola la corretta posizione che nbr deve avere in b*/
int ft_finddst_ba(int nbr, t_stack *a, t_vals *vals)
{
    int dest;

    dest = 1;
    if(nbr > a->n && nbr < ft_lst_last(a)->n)
        dest = 0;
    else if (nbr < vals->smallest_a || nbr > vals->biggest_a)
        dest = ft_index(a, vals->biggest_a);
    else
    {
        while (nbr < a->n || nbr > a->next->n)
        {
            dest++;
            a = a->next;
        }
    }
    return (dest);
}