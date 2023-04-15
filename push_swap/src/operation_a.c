/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:26:00 by btani             #+#    #+#             */
/*   Updated: 2023/03/13 20:34:46 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//swap dei primi due elementi della lista
void	ft_sa(t_stack **a, int i)
{
	t_stack *temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (i == 0)
		write(1, "sa\n", 3);
}

//pusha il primo elemento della lista b nella lista a
void	ft_pa(t_stack **a, t_stack **b, int i)
{
	t_stack *temp;
	
	if (!b)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
	if (i == 0)
		write(1, "pa\n", 3);
}

//shifta in alto di uno ogni elemento della lista a
void	ft_ra(t_stack **a, int i)
{
	t_stack *temp;
	
	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	ft_lst_last((*a)->next = temp);
	temp->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

//shifta in basso  di uno di ogni elemento della lista b
void	ft_rra(t_stack **a, int i)
{
	t_stack *temp;
	
	i = 0;
	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
}