/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:23:25 by btani             #+#    #+#             */
/*   Updated: 2023/09/25 16:23:28 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

void	ft_one_philo(t_data *data, t_philo *philo)
{
	if (pthread_create(&data->philos[0], NULL,
			(void *)ft_one_philo_data, &philo[0]))
		ft_exit("thread creation failed\n");
	if (pthread_join(data->philos[0], NULL))
		ft_exit("thread join failed\n");
}

void	ft_one_philo_data(t_philo *philo)
{
	printf("0 | Philosopher 1 has taken a fork\n");
	usleep(philo->data->time_to_die * 1000);
	printf("%u | Philosopher 1 died\n", philo->data->time_to_die);
}
