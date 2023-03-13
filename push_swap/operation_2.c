/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:12:37 by btani             #+#    #+#             */
/*   Updated: 2023/03/13 22:12:57 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

void	ft_sb(t_stack **b, int i)
{
	if (!*b || *b->next)
		return;
	temp = *b;
	*b = *b->next;
	temp->next = *a->next;
	*a->next = temp;
}

void	ft_pb(t_stack **a, t_stack **b, int i)
{
	t_stack *temp;
	
	if (!*a)
		return;
	temp = *b;
	*b = *a;
	*a = *a->next;
	*a->next = temp;
}
