/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:18:57 by btani             #+#    #+#             */
/*   Updated: 2023/03/13 22:22:22 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ritorna l'ultimo elemento della lista
t_stack	*ft_lst_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
	ft_printf("%s\n", lst);

}

//ritorna la grandezza della lista
int	ft_lst_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
	ft_printf("%d\n", i);
}

//crea nuovo nodo della grandezza data
t_stack	*ft_newlst(int data)
{
	t_stack *new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		write(2,"Error\n", 7);
	new->n = data;
	new->next = NULL;
	return (new);
}

void	ft_add_front(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	new->next = *lst;
	*lst = new;
}

//aggiunge un nodo in fondo alla lista 
void	ft_add_back(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		(ft_lst_last(*lst))->next = new;
}