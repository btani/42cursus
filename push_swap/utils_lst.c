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

#include "push_swap"

void	*ft_lst_last(t_stack *lst)
{
	if (lst = NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return(lst);
}

void	*ft_newlst(int i)
{
	t_stack *temp;
	
	temp = malloc(sizeof(*temp));
	if (temp == 0)
		return (NULL);
	temp->i = i;
	temp->next = NULL;
	return (temp);
}

void	ft_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_add_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lst_last(*lst)->next = new;
}
