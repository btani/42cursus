/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:53:57 by btani             #+#    #+#             */
/*   Updated: 2022/11/09 15:56:52 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr)
	{
		if(!ft_isdigit(*nptr))
			write(1, "Error not a digit\n", 18);
		i = (i * 10) + (*nptr - '0');
		nptr++;
	}
	if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
		write(1, "Error int min/max\n", 18);
	return (sign * i);
}