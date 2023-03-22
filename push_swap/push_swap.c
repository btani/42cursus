/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:49:04 by btani             #+#    #+#             */
/*   Updated: 2023/03/13 16:23:19 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	int i;
	t_stack *temp;
	
	while (a != NULL)
	{
		temp = a;
		i = a->n;
		while (temp->next != NULL)
		{
			if (temp->n < i)
				i = temp->n;
			temp = temp->next;
		}
		while (i != a->n)
			ft_ra_rb(&a, 1);
		ft_pa(&b, &a, 2);
	}
	ft_pb(&b, &a);
}

void	ft_list(t_stack **lst, char **av)
{
	int	i;
	t_stack *temp;
	
	i = 2;
	while (av[i])
	{
		temp = ft_newlst(ft_atoi(av[i]));
		ft_add_back(lst, temp);
		i++;
	}
}

int main(int ac, char **av)
{
	t_stack *a;
	int	n;
	
	n = ft_atoi(av[1]);
	a = ft_newlst(n);
	if (ac > 2)
		ft_list(&a, av)
	ft_sort(a, NULL);
	return (0);
}
