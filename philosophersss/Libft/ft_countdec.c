/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:50:50 by btani             #+#    #+#             */
/*   Updated: 2022/10/26 16:51:00 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_countdec(int n)
{	
	int			i;
	long int	a;

	a = n;
	if (a == 0)
		return (1);
	i = 0;
	if (a < 0)
	{
		a *= -1;
		i = 1;
	}
	while (a > 0)
	{
		i++;
		a = a / 10;
	}
	return (i);
}
