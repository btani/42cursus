/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:17:27 by btani             #+#    #+#             */
/*   Updated: 2023/06/06 15:17:46 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

//controllo gli argomenti
int	ft_check_av(char **av)
{
	int	i;
	int j;
	
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//inizializzo mutex e threads
int	ft_init(t_general general, t_philo philo)
{
}

//funzione che gestisce i mutex
void	ft_routine(t_philo *philo)
{
}
//error msg
void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit (1);
}

int	main(int ac, char **av)
{
	t_general	general;
	t_philo		*philo;

	if (ac != 5 || ac != 6)
		ft_error("Error!Wrong ac\n");
	ft_init_struct(ac, av, &general);
	philo = ft_calloc(general.nbr_philo, sizeof(t_philo));
	if (!philo)
		ft_error("Error!Problem with calloc");
	ft_philos_prepare(av, &general, philo);
	ft_init(&general, philo);
	return (0);
}
