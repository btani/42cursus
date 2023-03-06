/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:48:37 by btani             #+#    #+#             */
/*   Updated: 2023/03/05 12:48:42 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_sig(int signal, siginfo_t *si, void *data)
{
	static int	bit;
	static int	n;

	(void)data;
	if (bit < 7)
	{
		n += (signal == SIGUSR1) << bit;
		bit++;
	}
	else
	{
		n += (signal == SIGUSR1) << bit;
		if (n)
			write (1, &n, 1);
		else
			kill(si->si_pid, SIGUSR1);
		n = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{	
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error!");
		return (0);
	}
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_sig;
	ft_printf("Il pid del server e':%d\n", (int)getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
	}
	return (0);
}
