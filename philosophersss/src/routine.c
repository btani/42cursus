/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:23:29 by btani             #+#    #+#             */
/*   Updated: 2023/09/16 17:23:31 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

void	ft_take_fork(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->lock);
	if (data->death != 1)
	{
		ft_get_time(data);
		printf("%ld | Philosopher %d has taken a fork\n",
			data->current - data->start, philo->right_fork + 1);
	}
	pthread_mutex_unlock(&data->lock);
}

void	ft_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->lock);
	if (data->death != 1)
	{
		ft_get_time(data);
		printf("%ld | Philosopher %d is eating\n",
			data->current - data->start, philo->right_fork + 1);
		if (philo->data->nbr_meal[philo->right_fork] > 0)
			philo->data->nbr_meal[philo->right_fork] -= 1;
		ft_reset_philo(philo);
	}
	pthread_mutex_unlock(&data->lock);
}

void	ft_sleep(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->lock);
	if (data->death != 1)
	{
		ft_get_time(data);
		printf("%ld | Philosopher %d is sleeping\n",
			data->current - data->start, philo->right_fork + 1);
	}
	pthread_mutex_unlock(&data->lock);
}

void	ft_think(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->lock);
	if (data->death != 1)
	{
		ft_get_time(data);
		printf("%ld | Philosopher %d is thinking\n",
			data->current - data->start, philo->right_fork + 1);
	}
	pthread_mutex_unlock(&data->lock);
}

