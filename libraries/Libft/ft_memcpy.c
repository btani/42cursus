/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:46:59 by btani             #+#    #+#             */
/*   Updated: 2022/10/03 19:07:01 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				a;
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	a = 0;
	if (!src && !dest)
		return (NULL);
	while (a < n)
	{
		d[a] = s[a];
		a++;
	}
	return (dest);
}
