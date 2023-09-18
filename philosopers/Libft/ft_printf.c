/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:29:59 by btani             #+#    #+#             */
/*   Updated: 2022/10/24 19:47:31 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flags(va_list arg, const char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_printchar(va_arg(arg, int));
	if (type == 's')
		count += ft_printstr(va_arg(arg, char *));
	if (type == 'p')
		count += ft_printvoidptr(va_arg(arg, unsigned long));
	if (type == 'd' || type == 'i')
		count += ft_printnbr(va_arg(arg, int));
	if (type == 'u')
		count += ft_printunsnbr(va_arg(arg, unsigned int));
	if (type == 'x')
		count += ft_printhexa1(va_arg(arg, int), 'x');
	if (type == 'X')
		count += ft_printhexa1(va_arg(arg, int), 'X');
	if (type == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start (arg, s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count += ft_flags(arg, s[i + 1]);
			i++;
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}		
