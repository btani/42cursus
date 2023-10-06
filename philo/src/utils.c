/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:41:59 by btani             #+#    #+#             */
/*   Updated: 2023/09/21 17:50:20 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

int	ft_exit(char *str)
{
	printf(RED"Error : "WHITE);
	printf(RED"%s"WHITE, str);
	exit(1);
}

void	ft_philo_handler_bis(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		ft_fork_routine(philo->data, philo);
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		ft_fork_routine(philo->data, philo);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		ft_fork_routine(philo->data, philo);
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		ft_fork_routine(philo->data, philo);
	}
}

void	ft_philo_handler(t_philo *philo)
{
	if (philo->left_fork % 2)
		usleep(1000);
	pthread_mutex_lock(&philo->data->lock);
	while (philo->data->death != 1)
	{
		pthread_mutex_unlock(&philo->data->lock);
		ft_philo_handler_bis(philo);
		ft_eat_routine(philo->data, philo);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		ft_sleep_routine(philo->data, philo);
		usleep(philo->time_to_sleep * 1000);
		if (!(philo->left_fork % 2))
			usleep(100);
		ft_think_routine(philo->data, philo);
		pthread_mutex_lock(&philo->data->lock);
	}
	pthread_mutex_unlock(&philo->data->lock);
}

/*pthread_mutex_destroy(): usata per distruggeree
pulire mutex object precedentemente inizializzato*/
void	ft_close_data(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	free(philo);
	free(data->philos);
	while (++i < data->nbr_philo)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
	free(data->last_ate);
	free(data->nbr_meal);
	pthread_mutex_destroy(&data->lock);
}

void	ft_reset_philo(t_philo *philo)
{
	gettimeofday(&philo->data->tv, NULL);
	philo->data->last_ate[philo->left_fork]
		= ((time_t)(philo->data->tv.tv_sec) * 1000)
		+ ((time_t)(philo->data->tv.tv_usec) / 1000);
}
