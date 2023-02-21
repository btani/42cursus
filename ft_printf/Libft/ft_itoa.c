/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:40:36 by btani             #+#    #+#             */
/*   Updated: 2022/10/17 16:41:15 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int		i;
	unsigned int		n2;
	char				*s1;

	i = ft_count(n);
	s1 = (char *)malloc(sizeof(char) * i + 1);
	if (s1 == 0)
		return (NULL);
	s1[i] = '\0';
	if (n == 0)
		s1[0] = '0';
	if (n < 0)
	{
		s1[0] = '-';
		n2 = -n;
	}
	else
		n2 = n;
	while (n2)
	{
		s1[--i] = n2 % 10 + 48;
		n2 = n2 / 10;
	}
	return (s1);
}
