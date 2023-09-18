/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:41:46 by btani             #+#    #+#             */
/*   Updated: 2023/09/12 18:41:48 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if(!ft_check_av(&data, philo, ac, av))
			ft_exit("invalid input");
		ft_alloc_all(&data);
		philo = (t_philo *)ft_calloc(data.nbr_philo, sizeof(t_philo));
		if (!philo)
			ft_exit("Allocation philo failed\n");
		ft_init(&data, philo);
		ft_init_mutex(&data, philo);
		ft_init_threads(&data, philo);
		ft_close_data(&data, philo);
	}
	else
		ft_exit("Invalid input\n");
	return (0);
}
