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

/*allocazione degli elementi*/
void	ft_allocation(char **av, t_data *data)
{
	data->nbr_philo = ft_atoi(av[1]);
	if (data->nbr_philo < 1)
		ft_exit("too few philosophers\n");
	data->philos = (pthread_t *)ft_calloc(data->nbr_philo, sizeof(pthread_t));
	if (!data->philos)
		ft_exit("'data->philos'->allocation failed\n");
	data->forks = (pthread_mutex_t *)ft_calloc(data->nbr_philo,
			sizeof(pthread_mutex_t));
	if (!data->forks)
		ft_exit("'data->forks'->allocation failed\n");
	data->last_ate = (time_t *)ft_calloc(data->nbr_philo, sizeof(time_t));
	if (!data->last_ate)
		ft_exit("'data->last_ate'->allocation failed\n");
	data->nbr_meal = (int *)ft_calloc(data->nbr_philo, sizeof(int));
	if (!data->nbr_meal)
		ft_exit("'data->nbr_meal'->allocation failed\n");
}

int	ft_is_nbr(char **av, int i, int j)
{
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9' || ft_strlen(av[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if ((ac == 5 || ac == 6) && ft_is_nbr(av, 0, 1) == 1)
	{
		ft_allocation(av, &data);
		ft_initialize(ac, av, &data);
		philo = (t_philo *)ft_calloc(data.nbr_philo, sizeof(t_philo));
		if (!philo)
			ft_exit("Allocation philo failed\n");
		ft_init_philos(av, &data, philo);
		ft_init_mutex(&data, philo);
		ft_init_threads(&data, philo);
		ft_close_data(&data, philo);
	}
	else
		ft_exit("Invalid input\n");
	return (0);
}
