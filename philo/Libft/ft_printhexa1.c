/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:54:28 by btani             #+#    #+#             */
/*   Updated: 2022/10/26 16:54:51 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa1(unsigned int n, char type)
{
	char			*s;
	unsigned long	a;

	a = n;
	if (type == 'x')
		s = "0123456789abcdef";
	else if (type == 'X')
		s = "0123456789ABCDEF";
	else
		return (0);
	if (a == 0)
		return (write (1, "0", 1));
	if (a >= 16)
		ft_printhexa1 (a / 16, type);
	write (1, &s[(int)(a % 16)], 1);
	return (ft_counthexa(a));
}
