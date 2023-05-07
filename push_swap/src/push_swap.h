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

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../Libft/libft.h"

# define GREEN = \033[0;32m
# define YELLOW = \033[0;33m
# define PURPLE = \033[0;35m
# define NO_COLOR = \033[0m

typedef struct s_stack
{
	long	n;
	long	*index;
	struct s_stack *next;
}		t_stack;

int		main(int ac, char **av);
int		ft_print_testa(t_stack *a);
t_stack	*ft_process(int ac, char **av);
t_stack	*ft_process2(char **av);
t_stack	*ft_lst_last(t_stack *lst);
int		ft_lst_size(t_stack *lst);
t_stack	*ft_newlst(int data);
void	ft_add_back(t_stack **lst, t_stack *new);
void	ft_add_front(t_stack **lst, t_stack *new);
int		ft_find_min(t_stack *a);
int		ft_find_max(t_stack *a);
void	ft_free(t_stack **stack);
void    ft_free_str(char **str);
int		ft_check_duplicates(t_stack *a);
void	ft_check_if_alpha(char **av);
int		ft_check_if_num(char **av);
int		ft_sign(int c);
int		ft_space(int c);
int		ft_check_error(char **av, int i, int j);
void	ft_sa(t_stack **a, int i);
void	ft_pa(t_stack **a, t_stack **b, int i);
void	ft_ra(t_stack **a, int i);
void	ft_rra(t_stack **a, int i);
void	ft_sb(t_stack **b, int i);
void	ft_pb(t_stack **a, t_stack **b, int i);
void	ft_rb(t_stack **b, int i);
void    ft_rrb(t_stack **b, int i);
void	ft_sort(t_stack **a);
void	ft_sort_three(t_stack **a);
void	ft_sort_big(t_stack **a, t_stack **b);
//void	ft_sort_four(t_stack **a, t_stack **b);
int		ft_check_sort(t_stack *a);
int		ft_index(t_stack *a, int n);
int		ft_check_double(int ac, char **av);
int		ft_find_num(t_stack *a, int num);
void	ft_push(t_stack **a, t_stack **b);

#endif