/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:13:44 by btani             #+#    #+#             */
/*   Updated: 2023/03/13 22:13:58 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"#include

void	ft_ss(t_stack **a, t_stack **b, int i)
{
	t_stack *temp;

	if (!*b || !*b->next)
		return;
	temp = *a;
	*a = *a->next;
	temp->next = *a->next;
	*a->next = temp;
	temp = *b;
	*b = *b->next;
	temp->next = *b->next;
	*b->next = temp;
}
