/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:53:57 by btani             #+#    #+#             */
/*   Updated: 2022/11/09 15:56:52 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	if (nmemb == 0 || size == 0)
		a = malloc(1);
	else
	{
		a = (void *)malloc(nmemb * size);
		if (nmemb > SIZE_MAX / size || !a)
			return (NULL);
		ft_memset(a, 0, nmemb * size);
	}
	return (a);
}
