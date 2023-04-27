/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:33:42 by btani             #+#    #+#             */
/*   Updated: 2023/04/12 15:34:05 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void ft_sort_four(t_stack **a)
{
     printf("ciao");
     //int i = 0;
     //int size = 0;
     t_stack **b;

     b = malloc(sizeof(t_stack));
     while (ft_lst_size(*a) == 4)
     {
          ft_pb(a, b, 0);
          ft_sort_three(a);
          printf("ciao1");
          while (*b)
          {
               ft_pa(a, b, 0);
               if ((*b)->n > (*a)->n)
                    ft_add_back(a, *b);
          }
     }
}

void ft_sort_three(t_stack **a)
{
     if (ft_find_min(*a) == (*a)->n)
     {
          ft_rra(a, 0);
          write(1, "rra\n", 4);
          ft_sa(a, 0);
     }
     else if (ft_find_max(*a) == (*a)->n)
     {
          ft_ra(a, 0);
          if(!ft_check_sort(*a))
               ft_sa(a, 0);
     }
     else
     {
          if (ft_index(*a, ft_find_max(*a)) == 1)
          {
               ft_rra(a, 0);
               write(1, "rra\n", 4);
          }
          else
          {
               ft_sa(a, 0);
          }
     }
}

void ft_sort(t_stack **a)
{
     if (ft_lst_size(*a) == 2)
          ft_sa(a, 0);
     if (ft_lst_size(*a) == 3)
          ft_sort_three(a);
     if (ft_lst_size(*a) == 4)
          ft_sort_four(a);
}
     