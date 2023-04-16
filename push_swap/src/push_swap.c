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

int ft_print_testa(t_stack *a)
{
	while (a)
	{
		ft_printf("stack a:%d\n", a->n);
		a = a->next;
	}
	return (0);
}

t_stack	*ft_process2(char **av)
{
	t_stack *a;
	char **temp;
	int	i;
	int	j;

	i = 0;
	a = NULL;
	temp = ft_split(av[1], 32);
	while (temp[i])
	{
		j = ft_atoi(temp[i]);
		ft_add_back(&a, ft_newlst(j));
		i++;
	}
	ft_free_str(temp);
	free(temp);
	return (a);
}

// 1. Controllo se ac < 2: errore
// 2. Controllo se ac == 2: chiamo ft_process2
// 3. Controllo se ac > 2:gli ac vengono inseriti nella lista
t_stack	*ft_process(int ac, char **av)
{
	t_stack *a;
	int	i;
	int j;

	i = 1;
	a = NULL;
	if (ac < 2)
		ft_printf("\033[0;31mError!Too few arguments!\033[0m");
	if (ac == 2)
		a = ft_process2(av);
	else
	{
		while (i < ac)
		{
			j = ft_atoi(av[i]);
			ft_add_back(&a, ft_newlst(j));
			i++;
			ft_printf("%d\n", j);
		}
	}
	return (a);
}

int main(int ac, char **av)
{
	t_stack *a;

	a = ft_process(ac, av);
	if (!a || ft_check_duplicates(a))
	{
		ft_free(&a);
		ft_printf("\033[0;31mError the list dosn't exist!\033[0m");
	}
	if (!ft_check_sort(a))
	{
		ft_sort(&a);
		ft_print_testa(a);
	}
	ft_free(&a);
	return (0);
}