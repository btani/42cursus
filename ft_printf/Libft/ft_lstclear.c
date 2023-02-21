/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:57:32 by btani             #+#    #+#             */
/*   Updated: 2022/10/20 14:05:27 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;

	if (!*lst)
		return ;
	while (*lst)
	{
		a = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = a;
	}
}
