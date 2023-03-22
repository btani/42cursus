/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:27:27 by btani             #+#    #+#             */
/*   Updated: 2022/10/03 17:47:25 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	a;
	char	*f;

	f = s;
	a = 0;
	while (a < n)
	{
		*f = c;
		f++;
		a++;
	}
	return (s);
}