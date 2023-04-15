/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:12:37 by btani             #+#    #+#             */
/*   Updated: 2023/03/13 22:12:57 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//swap dei primi due elementi di b
void    ft_sb(t_stack **b, int i)
{
    t_stack *temp;

    if (!*b || !((*b)->next))
        return ;
    temp = *b;
    *b = (*b)->next;
    temp->next =(*b)->next;
    (*b)->next = temp;
    if (i == 0)
        write(1, "sb\n", 3);
}

//shifta in alto di uno tutti gli elementi di b
void    ft_rb(t_stack **b, int i)
{
    t_stack *temp;

    if (!*b || !((*b)->next))
        return ;
    temp = *b;
    *b = ft_lst_last(*b);
    (*b)->next = temp;
    *b = temp->next;
    temp->next = NULL;
    if (i == 0)
        write (1, "rb\n", 3);
}

//pusha il primo elemento della lista a nella lista b
void ft_pb(t_stack **a, t_stack **b, int i)
{
    t_stack *temp;

    if (!*a)
        return ;
    temp = *b;
    *b = *a;
    *a = (*a)->next;
    (*b)->next = temp;
    if (i == 0)
        write(1, "pb\n", 3);
}

//shifta in basso di uno tutti gli elementi di b
void    ft_rrb(t_stack **b, int i)
{
	t_stack *temp;

	i = 0;
	if (!*b || !((*b)->next))
		return ;
	temp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (i == 0)
		write(1, "rrb\n", 4);
}