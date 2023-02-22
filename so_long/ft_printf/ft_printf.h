/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:48:06 by btani             #+#    #+#             */
/*   Updated: 2022/10/28 16:48:15 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "Libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int		ft_countdec(int n);
int		ft_countdec_uns(unsigned int n);
int		ft_counthexa(unsigned long n);
int		ft_printchar(int c);
int		ft_printf(const char *s, ...);
void	ft_printhexa(unsigned long n);
int		ft_printhexa1(unsigned int n, char type);
int		ft_printnbr(int n);
int		ft_printstr(char *str);
int		ft_printunsnbr(unsigned int n);
int		ft_printvoidptr(unsigned long n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_uns_fd(unsigned int n, int fd);
void	ft_putstr_fd(char *s, int fd);
#endif
