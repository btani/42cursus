/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanicalturk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:53:20 by btani             #+#    #+#             */
/*   Updated: 2023/05/15 15:53:40 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//pusha in b i primi due elementi in testa allo stack a
void	ft_push_first2(t_stack **a, t_stack **b, t_vals *vals)
{
	ft_pb(a, b, 0);
	ft_pb(a, b, 0);
	vals->size_a = ft_lst_size(*a);
	vals->size_b = ft_lst_size(*b);
	if ((*b)->n > (*b)->next->n)
	{
		vals->biggest_b = (*b)->n;
		vals->smallest_b = (*b)->next->n;
	}
	else
	{
		vals->biggest_b = (*b)->next->n;
		vals->smallest_b = (*b)->n;
	}
}

void	ft_sort_togheter(t_stack **a, t_stack **b, t_vals *vals)
{
	while (vals->size_a > 3 && !ft_check_sort(*a))
		ft_apply_combo_ab((*a)->n, a, b, vals);
	if (!ft_check_sort(*a))
		ft_sort_three(a);
	vals->smallest_a = ft_find_min(*a);
	vals->biggest_a = ft_find_max(*a);
	while (vals->size_b > 0)
		ft_apply_combo_ba((*b)->n, a, b, vals);
}

void	ft_update_vals(t_stack *a, t_stack *b, t_vals *vals, char c)
{
	if (c == 'a')
	{
		vals->size_a--;
		vals->size_b++;
	}
	else if (c == 'b')
	{
		vals->size_b--;
		vals->size_a++;
	}
	vals->biggest_a = ft_find_max(a);
	vals->smallest_a = ft_find_min(a);
	vals->biggest_b = ft_find_max(b);
	vals->smallest_b = ft_find_min(b);
	if (c == '0')
		return ;
}

//algoritmo
void	ft_mechanicalturk(t_stack **a, t_stack **b)
{
	t_vals	vals;

	ft_push_first2(a, b, &vals);
	ft_sort_togheter(a, b, &vals);
	vals.smallest_a = ft_find_min(*a);
	vals.biggest_a = ft_find_max(*a);
	if (vals.size_a > 2 && !ft_check_sort(*a))
	{
		if (ft_index(*a, vals.smallest_a) < ft_lst_size(*a) - vals.smallest_a)
		{
			while ((*a)->n != vals.smallest_a)
				ft_ra(a, 0);
		}
		else
		{
			while ((*a)->n != vals.smallest_a)
				ft_rra(a, 0);
		}
	}
}
