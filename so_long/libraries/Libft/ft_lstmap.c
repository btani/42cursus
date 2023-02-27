/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:40:31 by btani             #+#    #+#             */
/*   Updated: 2022/10/21 17:01:31 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*a;

	new = NULL;
	while (lst)
	{
		a = ft_lstnew((*f)(lst->content));
		if (!a)
		{
			while (new)
			{
				a = new->next;
				(*del)(new->content);
				new = a;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new, a);
		lst = lst-> next;
	}
	return (new);
}
