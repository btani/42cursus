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

//sort >5
void ft_sort_big(t_stack **a, t_stack **b)
{
     int min;
     int ind;

     while (ft_lst_size(*a) > 3)
     {
          min = ft_find_min(*a);
          ind = ft_index(*a, min);
          if (ind < 3)
          {
               while ((*a)->n != min)
                    ft_ra(a, 0);
          }
          else
          {
               while ((*a)->n != min)
                    ft_rra(a, 0);
          }
          ft_pb(a, b, min);
     }
     ft_sort_three(a);
     while (*b)
          ft_pa(a, b, min);
}

//sorta lo stack di grandezza 4 
/*void ft_sort_four(t_stack **a, t_stack **b)
{
     int min;
     int ind;

     min = ft_find_min(*a);
     ind = ft_index(*a, min);
     if (ind == 0)
     {
          ft_pb(a, b, min);
     }
     if (ind == 1)
     {
          ft_sa(a, min);
          ft_pb(a, b, min);
     }
     if (ind == 2)
     {
          ft_ra(a, min);
          ft_ra(a, min);
          ft_pb(a, b, min);
     }
     if (ind == 3)
     {
          ft_rra(a, min);
          ft_pb(a, b, min);
     }
     ft_sort_three(a);
     ft_pa(a, b, min);
}*/

//sorta lo stack di grandezza 3
void ft_sort_three(t_stack **a)
{
     if (ft_find_min(*a) == (*a)->n)
     {
          ft_rra(a, 0);
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
               ft_rra(a, 0);
          else
               ft_sa(a, 0);
     }
}

void ft_sort(t_stack **a)
{
     t_stack **b;

     b = malloc(sizeof(t_stack));
     if (ft_lst_size(*a) == 2)
          ft_sa(a, 0);
     else if (ft_lst_size(*a) == 3)
          ft_sort_three(a);
     //else if (ft_lst_size(*a) == 4)
     //        ft_sort_four(a, b);
     else if (ft_lst_size(*a) >= 4)
          ft_sort_big(a, b);
     free(b);
}
     