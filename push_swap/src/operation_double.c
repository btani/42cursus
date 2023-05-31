/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:52:21 by btani             #+#    #+#             */
/*   Updated: 2023/04/14 10:52:23 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//ra + rb
void	ft_rr(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	temp = *a;
	*a = ft_lst_last(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	temp = *b;
	*b = ft_lst_last(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	if (i == 0)
		write(1, "rr\n", 3);
}

void	ft_rrr2(t_stack **b, int i)
{
	t_stack	*temp;
	int		j;

	j = 0;
	temp = *b;
	while ((*b)->next)
	{
		j++;
		*b = (*b)->next;
	}
	(*b)->next = temp;
	while (j > 1)
	{
		temp = temp->next;
		j--;
	}
	temp->next = NULL;
	if (i == 0)
		write(1, "rrr\n", 4);
}

//rra +rrb
void	ft_rrr(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;
	int		j;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	j = 0;
	temp = *a;
	while ((*a)->next)
	{
		j++;
		*a = (*a)->next;
	}
	(*a)->next = temp;
	while (j > 1)
	{
		temp = temp->next;
		j--;
	}
	temp->next = NULL;
	ft_rrr2(b, i);
}
