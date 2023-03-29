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

int	ft_check_sort(t_stack *a)
{
	int	i;

	i = a->n;
	while (a)
	{
		if (i > a->n)
			return (0);
		i = a->n;
		a->n = a->next;
	}
	return (1);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int i;
	t_stack *temp;
	
	while (a)
	{
		temp = a;
		i = a->n;
		while (temp->next)
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

t_stack	*ft_process2(char **av)
{
	t_stack *a;
	char **temp;
	int	i;
	int	j;

	i = 0;
	a = NULL;
	temp = ft_split(av[1], " ");
	while (temp[i])
	{
		j = ft_atoi(temp[i]);
		ft_add_back(&a, ft_newlst(j));
		i++;
	}
	ft_free(temp);
	free(temp);
	return (a);
}

t_stack	*ft_process(int ac, char **av)
{
	t_stack *a;
	int	i;
	int	j;

	i = 1;
	a = NULL;
	if (ac < 2)
		ft_printf("Too few arguments!");
	if (ac == 2)
		a = ft_process2(av);
	else
	{
		while (i < ac)
		{
			j = ft_atoi(av[i]);
			ft_add_back(&a, ft_newlst(j));
			i++;
		}
	}
	return (a);
}

/*void	ft_create_list(t_stack **lst, char **av)
{
	int	i;
	t_stack *temp;
	
	i = 0;
	while (av[i])
	{
		temp = ft_newlst(ft_atoi(av[i]));
		ft_add_back(lst, temp);
		i++;
	}
}*/

int main(int ac, char **av)
{
	t_stack *a;
	
	a = ft_process(ac, av);
	if (!a|| !(ft_check_duplicates(a)))
	{
		ft_free(&a);
		ft_printf("Error the list dosn't exist!");
	}
	if (!ft_check_sort(a))
		//ft_sort(&a);
	ft_free(a);
	return (0);
}