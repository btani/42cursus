/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:39:38 by btani             #+#    #+#             */
/*   Updated: 2023/09/15 15:39:40 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

void	ft_check_meal(t_data *data, int *n_death)
{
	pthread_mutex_lock(&data->lock);
	while (*n_death < data->nbr_philo)
	{
		if (data->nbr_meal[*n_death] == 0)
			*n_death += 1;
		else
		{
			*n_death = 0;
			break ;
		}
	}
	pthread_mutex_unlock(&data->lock);
	pthread_mutex_lock(&data->lock);
	if (*n_death == data->nbr_philo)
		data->death = 1;
	pthread_mutex_unlock(&data->lock);
}

void	ft_get_time(t_data *data)
{
	gettimeofday(&data->tv, NULL);
	data->current = ((time_t)(data->tv.tv_sec) * 1000)
		+ ((time_t)(data->tv.tv_usec) / 1000);
}

void	ft_check_death(t_data *data, int *n_ate)
{
	pthread_mutex_lock(&data->lock);
	ft_get_time(data);
	if (data->current - data->last_ate[*n_ate] > data->time_to_die)
	{
		data->death = 1;
		printf("%ld | Philosopher %d died\n",
			data->current - data->start, *n_ate + 1);
		pthread_mutex_unlock(&data->lock);
		return ;
	}
	pthread_mutex_unlock(&data->lock);
	*n_ate += 1;
	if (*n_ate == data->nbr_philo)
		*n_ate = 0;
}

/*pthread_mutex_lock(): used for acquiring a mutex lock,
which is a synchronization primitive used to protect
critical sections of code from simultaneous access by
multiple threads. Mutex locks ensure that only one thread
can access the protected code region at any given time,
preventing data races and ensuring thread safety*/
void	ft_check_mutex(t_data *data)
{
	int	n_ate;
	int	n_death;

	n_ate = 0;
	n_death = 0;
	data->death = 0;
	pthread_mutex_lock(&data->lock);
	while (data->death == 0)
	{
		pthread_mutex_unlock(&data->lock);
		ft_check_meal(data, &n_death);
		usleep(100);
		ft_check_death(data, &n_ate);
		pthread_mutex_lock(&data->lock);
	}
	pthread_mutex_unlock(&data->lock);
}
