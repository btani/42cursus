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

//controlla se gli argomenti sono validi
int ft_check_error(char **av, int i, int j)
{
    int c;
    
    while (av[i])
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if () 
        }
    }
}
int ft_check_if_alpha(char **av, int c)
{
    int i;
    int j;
    
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if (c >= 58 || c <= 126)
        }
    }
}

int ft_check_alphanumeric(char **av)
{
    ft_check_if_alpha(av);
    if (!c)
}