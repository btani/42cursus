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

void	ft_sa_sb(t_stack *nd1,t_stack *nd2, int i)
{
	nd1->next = nd2->next;
	nd2->next = nd1;
	nd1 = nd2;
	if (i == 1)
		printf("sa\n");
	if (i == 2)
		printf("sb\n")
}

void	ft_pa(t_stack **stka, t_stack **stkb, int i)
{
	t_stack *temp;
	
	temp = *stka->next;
	if (*stkb == NULL)
		*stkb = ft_newlst(*stka->i);
	else
		ft_add_front(stkb, *stka);
	if (i == 1)
		printf("pa\n");
	if (i == 2)
		printf("pb\n")
}

void	ft_pb(t_stack **b, t_stack **a)
{
	while (*b)
		ft_pa(b, a , 1);
}

void	ft_ra_rb(t_stack **stk, int i)
{
	t_stack *temp;
	
	temp = (*stk);
	*stk = (*stk)->next;
	ft_lst_last((*stk)->next = temp);
	temp->next = NULL;
	if (i == 1)
		printf("ra\n");
	if (i == 2)
		printf("rb\n");
}

void	ft_rra_rrb(t_stack *stk, int i)
{
	t_stack *temp;
	t_stack *temp2;
	
	temp = ft_lst_last(stk);
	temp2 = stk;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp->next = stk;
	if (i == 1)
		printf("rra\n");
	if (i == 2)
		printf("rrb\n");
}