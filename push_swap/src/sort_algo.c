/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:37:06 by btani             #+#    #+#             */
/*   Updated: 2023/05/18 20:37:18 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//DA CONTROLLARE RR E RRR

/*Questa fuzione si itera attraverso ogni elemento nello stack a e 
calcola il numero minimo di operazioni necessarie per portare ogni
elemento dallo stack a allo stack b usando differenti tipi di rotazione;
ritorna il numero minimo assoluto di operazioni per ogni elento nell stack*/
int ft_combo_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals)
{
	t_stack *tmp;
	int     bestcombo;

	tmp = a;
	bestcombo = ft_rrarrb_ab(nbr, a, b, vals);
	while (tmp)
	{
		if (bestcombo > ft_rarb_ab(tmp->n, a, b, vals))
			bestcombo = ft_rarb_ab(tmp->n, a, b, vals);
		if (bestcombo > ft_rrarrb_ab(tmp->n, a, b, vals))
			bestcombo = ft_rrarrb_ab(tmp->n, a, b, vals);
		if (bestcombo > ft_rrbra_ab(tmp->n, a, b, vals))
			bestcombo = ft_rrbra_ab(tmp->n, a, b, vals);
		if (bestcombo > ft_rrarb_ab(tmp->n, a, b, vals))
			bestcombo = ft_rrarb_ab(tmp->n, a, b, vals);
		tmp = tmp->next;
	}
	return (bestcombo);
}

int ft_combo_ba(int nbr, t_stack *a, t_stack *b, t_vals *vals)
{
	t_stack *tmp;
	int     bestcombo;

	tmp = b;
	bestcombo = ft_rrbrra_ba(nbr, a, b, vals);
	while (tmp)
	{
		if (bestcombo > ft_rbra_ba(tmp->n, a, b, vals))
			bestcombo = ft_rbra_ba(tmp->n, a, b, vals);
		if (bestcombo > ft_rrbrra_ba(tmp->n, a, b, vals))
			bestcombo = ft_rrbrra_ba(tmp->n, a, b, vals);
		if (bestcombo > ft_rrbra_ba(tmp->n, a, b, vals))
			bestcombo = ft_rrbra_ba(tmp->n, a, b, vals);
		if (bestcombo > ft_rrarb_ba(tmp->n, a, b, vals))
			bestcombo = ft_rrarb_ba(tmp->n, a, b, vals);
		tmp = tmp->next;
	}
	return (bestcombo);
}

/*Funzione che sceglie la combo piu conveniente basandosi sulla 
comparazione fra mosse migliori e risultati delle varie operazioni;
fatto quato applica l'operazione indicata con ft_apply* per modificare 
gli stack in modo corretto*/
void ft_apply_combo_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals)
{
	t_stack	*tmp;
	int		bestcombo;

	tmp = *a;
	bestcombo = ft_combo_ab(nbr, *a, *b, vals);
	if (tmp)
	{
		if (bestcombo = ft_rarb_ab(tmp->n, a, b, vals))
			bestcombo = ft_rarb_ab(tmp->n, a, b, vals);
		else if (bestcombo = ft_rrarrb_ab(tmp->n, a, b, vals))
			bestcombo = ft_rrarrb_ab(tmp->n, a, b, vals);
		else if (bestcombo = ft_rrbra_ab(tmp->n, a, b, vals))
			bestcombo = ft_rrbra_ab(tmp->n, a, b, vals);
		else if (bestcombo = ft_rrarb_ab(tmp->n, a, b, vals))
			bestcombo = ft_rrarb_ab(tmp->n, a, b, vals);
	}
}

void ft_apply_combo_ba(int nbr, t_stack **a, t_stack **b, t_vals *vals)
{
	t_stack	*tmp;
	int		bestcombo;

	tmp = *a;
	bestcombo = ft_combo_ba(nbr, *a, *b, vals);
	if (tmp)
	{
		if (bestcombo = ft_rbra_ba(tmp->n, *a, *b, vals))
			bestcombo = ft_rbra_ba(tmp->n, a, b, vals);
		else if (bestcombo = ft_rrbrra_ba(tmp->n, *a, *b, vals))
			bestcombo = ft_rrbrra_ba(tmp->n, a, b, vals);
		else if (bestcombo = ft_rrbra_ba(tmp->n, *a, *b, vals))
			bestcombo = ft_rrbra_ba(tmp->n, a, b, vals);
		else if (bestcombo = ft_rrarb_ba(tmp->n, *a, *b, vals))
			bestcombo = ft_rrarb_ba(tmp->n, a, b, vals);
		//ft_updatevals
	}
}