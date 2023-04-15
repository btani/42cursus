/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoidptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:06:36 by btani             #+#    #+#             */
/*   Updated: 2022/10/25 15:06:40 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printvoidptr(unsigned long n)
{
	int	len;

	len = 0;
	if ((void *)n == NULL)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	ft_printhexa(n);
	len += ft_counthexa(n);
	return (len);
}
