/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:26:00 by btani             #+#    #+#             */
/*   Updated: 2023/03/13 20:34:46 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int i)
{
	t_stack *temp;
	
	if (!*a || !*a->next)
		return;
	temp = *a;
	*a = *a->next;
	temp->next = *a->next;
	*a->next = temp;
}

void	ft_pa(t_stack **a, t_stack **b, int i)
{
	t_stack *temp;
	
	if (!*b)
		return;
	temp = *a;
	*a = *b;
	*b = *b->next;
	*a->next = temp;	
}

void	ft_ra(t_stack **a, int i)
{
	t_stack *temp;
	
	temp = *a;
	*a = ft_lst_last(&a)
}
