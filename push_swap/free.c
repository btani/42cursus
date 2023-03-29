/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:22:46 by btani             #+#    #+#             */
/*   Updated: 2023/03/27 20:22:49 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free(t_stack **stack)
{
    t_stack *temp;

    if (!stack)
        return;
    while (*stack)
    {
        temp = (*stack)->next;
        (*stack)->n = 0;
        free(*stack);
        *stack = temp;
    }
}
