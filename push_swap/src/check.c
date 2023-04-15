/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:21:54 by btani             #+#    #+#             */
/*   Updated: 2023/03/27 20:21:57 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//controlla se ci sono doppi nella lista
int    ft_check_duplicates(t_stack *a)
{
    t_stack *temp;
    
    while (a)
    {
        temp = a->next;
        while (temp)
        {
            if (a->n == temp->n)
                return (1);
            temp = temp->next;
        }
        a = a->next;
    }
    return (0);
}

//controllo ascii
void ft_check_if_alpha(char **av)
{
    int i;
    int j;
    int c;

    c = 0;
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42) || c == 44 || c == 46 || c == 47)
                ft_check_error(av, i , j);
            c++;
            j++;
        }
        i++;
    }
}

int ft_check_alphanumeric(char **av)
{
    ft_check_if_alpha(av);
    if (!ft_check_error(av, 1, 0))
        return (false);
    return (true);
}

//controlla se la lista e' sortata
int    ft_check_sort(t_stack *a)
{
    int i;

    i = a->n;
    while (a)
    {
        if (i > a->n)
            return(0);
        i = a->n;
        a = a->next;
    }
    return(1);
}