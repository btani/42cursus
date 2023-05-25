/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ab_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:15:48 by btani             #+#    #+#             */
/*   Updated: 2023/05/17 18:16:11 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*Funzione che calcola il numero di rotazioni richieste per per 
portare n nella sua posizione corretta nei due stack; ritorna 
il numero minimo di rotazioni necessarie */
int ft_rarb_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals)
{
    int moves;

    moves = ft_finddst_ab(nbr, b, vals);
    if (moves < ft_index(a, nbr))
        moves = ft_index(a, nbr);
    return (moves);
}

/*Funzione che clacola il numero di reverse rotation richieste 
per per portare n nella sua posizione corretta nei due stack;
compara il numero di reverse rotations necessarie per ognuno 
dei due stack; ritorna il numero minimo di revers rotations 
necessarie fra i due stack*/
int ft_rrarrb_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals)
{
    int moves;

    moves = 0;
    //ft_stackprint(a);
    //ft_stackprint(b);
    if (ft_finddst_ab(nbr, b, vals))
    {
        //ft_stackprint(a);
        //ft_stackprint(b);
        // esegue ft_newbiggest() cosi a diventa 3 2 1 e b rimane 2 1
        moves = ft_lst_size(b) - ft_finddst_ab(nbr, b, vals);
    }
    if (moves < (ft_lst_size(a) - ft_index(a, nbr)) && ft_index(a, nbr))
        moves = ft_lst_size(a) - ft_index(a, nbr);
    return (moves);
}

/*Funzione che calcola il numero totale di reverse rotations per ognuno 
dei due stack necessarie per portare n nella sua posizione corretta nei 
due stack; considera l'indirizzo attuale di n nello stack a e la posizione 
in cui n dovrebbe essere inserito nello stack b. Sommando questi due valori 
si ricava il totale delle rotazioni necessarie per entrambi gli stack*/
int ft_rrarb_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals)
{
    int moves;
    
    moves = 0;
    if (ft_finddst_ab(nbr, b, vals))
    	moves = ft_lst_size(a) - ft_index(a, nbr);
    moves = ft_finddst_ab(nbr, b, vals) + moves;
    return (moves);
}

/*Funzione che clacola il numero totale di reverse rotations per ognuno dei 
due stack necessarie per portare n nella sua positione corretta nei due stack; 
considera l'indirizzo attuale di n nello stack b e la posizione in cui n 
dovrebbe essere inserito nello stack a. Sommando questi due valori si ricava 
il totale delle rotazioni necessarie per entrambi gli stack.*/
int ft_rrbra_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals)
{
	int moves;
	
	moves = 0;
	if (ft_finddst_ab(nbr, b, vals))
		moves = ft_lst_size(b) - ft_finddst_ab(nbr, b, vals);
	moves = ft_index(a, nbr) + moves;
    return (moves);
}