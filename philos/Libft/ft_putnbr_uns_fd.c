/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:30:03 by btani             #+#    #+#             */
/*   Updated: 2022/10/27 17:30:07 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uns_fd(unsigned int n, int fd)
{
	unsigned long int	i;

	i = n;
	if (i > 9)
		ft_putnbr_uns_fd(i / 10, fd);
	ft_putchar_fd(i % 10 + 48, fd);
}
