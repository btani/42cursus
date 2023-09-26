/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:25:33 by btani             #+#    #+#             */
/*   Updated: 2022/10/18 19:42:06 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = nb * -1;
	}
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		i++;
	}
	i++;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	a[12];

	i = ft_nbr(n);
	a[i] = '\0';
	if (n == 0)
		write (fd, "0", 1);
	else if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n = n * -1;
		}
		while (n > 0)
		{
			a[--i] = (n % 10 + 48);
			n = n / 10;
		}
		i = 0;
		while (a[i] != '\0')
			write (fd, &a[i++], 1);
	}
}
