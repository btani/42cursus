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

void	ft_ss(t_stack *stka, t_stack *stkb)
{
	t_stack *temp;
	
	temp = stka->next;
	stka->next = temp->next;
	temp->next = stka;
	stka = temp;
	temp = stkb->next;
	stkb->next = temp->next;
	temp->next = stkb;
	stkb = temp;
	printf("ss\n");
}

void	ft_rr

void	ft_rrr

