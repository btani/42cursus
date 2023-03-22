/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:57:21 by btani             #+#    #+#             */
/*   Updated: 2023/03/13 16:21:12 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	n;
	struct s_stack *next;
}		t_stack;


void	ft_sa(t_stack **a, int i);
void	ft_sb(t_stack **b, int i);
void	ft_ss(t_stack **a, t_stack **b, int i);
void	ft_pa(t_stack **a, t_stack **b, int i);
void	ft_pb(t_stack **a, t_stack **b, int i);

#endif
