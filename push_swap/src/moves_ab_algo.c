/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:45:13 by btani             #+#    #+#             */
/*   Updated: 2023/05/21 16:45:26 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*Queste funzioni eseguono una serie di operazioni sui due stack
per muover eil valore n da uno stack all'altro. Vengono usate le
operazioni dello stack affiche gli elementi negli stack siano ordinati*/

int ft_apply_rarb_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals)
{
    while ((*a)->n != nbr && ft_find_dest_ab(nbr, *b, vals) > 0)
        ft_rr(a, b, 0);
    while ((*a)->n != nbr)
        ft_ra(a, 0);
    while (ft_finddst_ab(nbr, *b, vals) > 0)
        ft_rb(b, 0);
    ft_pb(a, b, 0);
    return(-1);
}

int ft_apply_rr_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals)
{
    if (ft_finddst_ab(nbr, *b, vals) < 0)
        return (0);
    while ((*a)->n != nbr && ft_finddst_ab(nbr, *b, vals) > 0)
        ft_rrr(a, b, 0);
    while ((*a)->n != nbr)
        ft_rra(a, 0);
    while (ft_finddst_ab(nbr, *b, vals) > 0)
        ft_rra(b, 0);
    ft_pb(a, b, 0);
    return (-1);
}

int ft_apply_rrarb_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals)
{
    while ((*a)->n != nbr)
        ft_rra(a, 0);
    while (ft_finddst_ab(nbr, *b, vals) > 0)
        ft_rb(b, 0);
    ft_pb(a, b , 0);
    return (-1);
}

int ft_apply_rrbra_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals)
{
    while ((*b)->n != nbr)
        ft_rrb(b, 0);
    while (ft_finddst(nbr, *b, vals) > 0)
        ft_ra(a, 0);
    ft_pb(a, b, 0);
    return (-1);
}