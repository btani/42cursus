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

typedef struct s_stack
{
	long			n;
	long			*index;
	struct s_stack	*next;
}		t_stack;

typedef struct s_vals
{
	int	size_a;
	int	biggest_a;
	int	smallest_a;
	int	size_b;
	int	biggest_b;
	int	smallest_b;
}		t_vals;

/*CHECK*/
int		ft_check_double(int ac, char **av);
void	ft_check_if_alpha(char **av);
int		ft_check_if_num(char **av);
int		ft_sign(int c);
int		ft_space(int c);
int		ft_check_error(char **av, int i, int j);
//int		ft_check_duplicates(t_stack *a);

/*CHECKALGO*/
void	ft_newbiggest_ab(t_stack **a, t_stack **b, t_vals *vals);
void	ft_newsmallest_ab(t_stack **a, t_stack **b, t_vals *vals);
void	ft_newbiggest_ba(t_stack **b, t_stack **a, t_vals *vals);
void	ft_newsmallest_ba(t_stack **b, t_stack **a, t_vals *vals);

/*FIND_ALGO*/
int		ft_finddst_ab(int nbr, t_stack *b, t_vals *vals);
int		ft_finddst_ba(int nbr, t_stack *a, t_vals *vals);

/*FREE*/
void	ft_free(t_stack **stack);
void	ft_free_str(char **str);

/*MECHANICALTURK*/
void	ft_mechanicalturk(t_stack **a, t_stack **b);
void	ft_push_first2(t_stack **a, t_stack **b, t_vals *vals);
void	ft_update_vals(t_stack *a, t_stack *b, t_vals *vals, char c);
void	ft_sort_togheter(t_stack **a, t_stack **b, t_vals *vals);

/*MOVES_ALGO*/
int		ft_apply_rarb_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals);
int		ft_apply_rrarrb_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals);
int		ft_apply_rrarb_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals);
int		ft_apply_rrbra_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals);
int		ft_apply_rarb_ba(int nbr, t_stack **a, t_stack **b, t_vals *vals);
int		ft_apply_rrarrb_ba(int nbr, t_stack **a, t_stack **b, t_vals *vals);
int		ft_apply_rrarb_ba(int nbr, t_stack **a, t_stack **b, t_vals *vals);
int		ft_apply_rrbra_ba(int nbr, t_stack **a, t_stack **b, t_vals *vals);

/*OPERATION_A*/
void	ft_sa(t_stack **a, int i);
void	ft_pa(t_stack **a, t_stack **b, int i);
void	ft_ra(t_stack **a, int i);
void	ft_rra(t_stack **a, int i);

/*OPERATION_B*/
void	ft_sb(t_stack **b, int i);
void	ft_pb(t_stack **a, t_stack **b, int i);
void	ft_rb(t_stack **b, int i);
void	ft_rrb(t_stack **b, int i);

/*OPERATION_DOUBLE*/
void	ft_rr(t_stack **a, t_stack **b, int i);
//void	ft_rrr2(t_stack **b, int i);
void	ft_rrr(t_stack **a, t_stack **b, int i);

/*OPERATION_AB*/
int		ft_rarb_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals);
int		ft_rrarrb_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals);
int		ft_rrarb_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals);
int		ft_rrbra_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals);

/*OPERATION_BA*/
int		ft_rarb_ba(int nbr, t_stack *a, t_stack *b, t_vals *vals);
int		ft_rrarrb_ba(int nbr, t_stack *a, t_stack *b, t_vals *vals);
int		ft_rrarb_ba(int nbr, t_stack *a, t_stack *b, t_vals *vals);
int		ft_rrbra_ba(int nbr, t_stack *a, t_stack *b, t_vals *vals);

/*PUSH_SWAP*/
int		main(int ac, char **av);
void	ft_print_stack(t_stack *a);
t_stack	*ft_process(int ac, char **av);
t_stack	*ft_process2(char **av);
int		ft_check_sort(t_stack *a);
int		ft_atoi_ps(const char *nptr, t_stack **a, char **tmp);
void	ft_atoi_err(void);

/*SORT*/
void	ft_sort(t_stack **a);
void	ft_sort_three(t_stack **a);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);

/*SORT_ALGO*/
int		ft_combo_ab(int nbr, t_stack *a, t_stack *b, t_vals *vals);
int		ft_combo_ba(int nbr, t_stack *a, t_stack *b, t_vals *vals);
void	ft_apply_combo_ab(int nbr, t_stack **a, t_stack **b, t_vals *vals);
void	ft_apply_combo_ba(int nbr, t_stack **a, t_stack **b, t_vals *vals);
void	ft_sort_togheter(t_stack **a, t_stack **b, t_vals *vals);

/*UTILS_LST*/
t_stack	*ft_lst_last(t_stack *lst);
int		ft_lst_size(t_stack *lst);
t_stack	*ft_newlst(int data);
void	ft_add_back(t_stack **lst, t_stack *new);
void	ft_add_front(t_stack **lst, t_stack *new);

/*UTILS_LST2*/
int		ft_find_min(t_stack *a);
int		ft_find_max(t_stack *a);
int		ft_index(t_stack *a, int n);

#endif
