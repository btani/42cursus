/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:26:47 by btani             #+#    #+#             */
/*   Updated: 2023/05/31 17:27:53 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_atoi_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	ft_norm_atoi(const char *nptr, t_stack **a, char **tmp)
{
	(void)nptr;
	if (tmp != NULL)
		ft_free_str(tmp);
	ft_free(a);
	ft_atoi_err();
}

int	ft_atoi_ps(const char *nptr, t_stack **a, char **tmp)
{
	long long int	res;
	int				sign;

	res = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (!*nptr || !ft_isdigit((int) *nptr))
		ft_norm_atoi(nptr, a, tmp);
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = (res * 10) + (*nptr - '0');
		nptr++;
	}
	if ((sign * res) > 2147483647 || (sign * res) < -2147483648
		|| *nptr != '\0')
		ft_norm_atoi(nptr, a, tmp);
	return (res * sign);
}
