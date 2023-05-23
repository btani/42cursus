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

int ft_print_stack(t_stack *a)
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
		write(2,"Error\n", 7);
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

//controlla se la lista e' sortata
int    ft_check_sort(t_stack *a)
{
    if (!a || !a->next)
        return (1);
    while (a->next)
    {
    if (a->n < a->next->n)
        a = a->next;
    else
        return (0);
    }
    return (1);
}
 
int main(int ac, char **av)
{
	t_stack *a;
	
	if (ft_check_double(ac, av))
		return (1);
	a = ft_process(ac, av);
	if (!a)
		ft_free(&a);
	if (!ft_check_sort(a))
	{
		ft_sort(&a);
		ft_print_stack(a);
	}
	ft_free(&a);
	return (0);
}