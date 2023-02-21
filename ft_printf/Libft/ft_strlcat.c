/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:51:12 by btani             #+#    #+#             */
/*   Updated: 2022/10/05 15:51:18 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;

	i = 0;
	lendst = ft_strlen(dst);
	if (size <= lendst)
		return (size + ft_strlen(src));
	while (lendst < size - 1 && src[i] != '\0')
	{
		dst[lendst] = src[i];
		i++;
		lendst++;
	}
	dst[lendst] = '\0';
	return (lendst + ft_strlen(&src[i]));
}
