/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:45 by btani             #+#    #+#             */
/*   Updated: 2023/05/14 19:28:16 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*Il numero in testa allo stack a diventa il nuovo maggiore nello stack b*/
void	ft_newbiggest_ab(t_stack **a, t_stack **b, t_vals *vals)
{
	if ((*a)->n < vals->biggest_b)
		return ;
	while ((*b)->n != vals->biggest_b)
		ft_rb(b, 0);
	ft_pb(a, b, 0);
	vals->biggest_b = (*b)->n;
	vals->size_a--;
	vals->size_b++;
}

/*Il numero in testa allo stack a diventa il nuovo minore nello stack b*/
void	ft_newsmallest_ab(t_stack **a, t_stack **b, t_vals *vals)
{
	if ((*a)->n > vals->smallest_b)
		return ;
	while (vals->biggest_b != (*b)->n)
		ft_rb(b, 0);
	ft_pb(a, b, 0);
	vals->smallest_b = (*b)->n;
	vals->size_a--;
	vals->size_b++;
}

/*Il numero in testa allo stack b diventa il nuovo maggiore nello stack a*/
void	ft_newbiggest_ba(t_stack **b, t_stack **a, t_vals *vals)
{
	if (vals->size_b > 0)
	{
		if ((*b)->n < vals->biggest_a)
			return ;
		while (vals->biggest_a != (*a)->n)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
		vals->biggest_a = (*a)->n;
		vals->size_b--;
		vals->size_a++;
	}
}

/*Il numero in testa allo stack b diventa il nuovo minore nello stack a*/
void	ft_newsmallest_ba(t_stack **b, t_stack **a, t_vals *vals)
{
	if (vals->size_b > 0)
	{
		if ((*b)->n > vals->smallest_a)
			return ;
		while (vals->smallest_a != (*a)->n)
			ft_ra(a, 0);
		ft_pa(b, a, 0);
		vals->smallest_a = (*a)->n;
		vals->size_b--;
		vals->size_a++;
	}
}
