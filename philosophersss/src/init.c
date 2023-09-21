/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc&init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:41:19 by btani             #+#    #+#             */
/*   Updated: 2023/09/12 18:41:21 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosopher.h"

/*getttimeofday(): rileva il current time in microsecondi
struct timeval *tv: puntatore a una struttura che conserva il current time*/
void	ft_initialize(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	data->time_to_die = ft_atoi(av[2]);
	gettimeofday(&data->tv, NULL);
	data->start = ((time_t)(data->tv.tv_sec) * 1000)
		+ ((time_t)(data->tv.tv_usec) / 1000);
	while (i < data->nbr_philo)
	{
		data->last_ate[i] = data->start;
		i++;
	}
	i = 0;
	if (ac == 6)
		while (i < data->nbr_philo)
			data->nbr_meal[i++] = ft_atoi(av[5]);
	else
		while (i < data->nbr_philo)
			data->nbr_meal[i++] = -1;
	data->death = 0;
}

/*inizializzazione dati filosofi*/
void	ft_init_philos(char **av, t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].right_fork = i;
		philo[i].left_fork = (i + 1) % data->nbr_philo;
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		philo[i].data = data;
		i++;
	}
}

/*inizializzo mutex del lock e delle forks
con pthread_mutex_init()*/
void	ft_init_mutex(t_data *data, t_philo *philo)
{
	int	count;

	count = 0;
	(void) *philo;
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		ft_exit("Mutex inizialization failed");
	while (count < data->nbr_philo)
	{
		if (pthread_mutex_init(&data->forks[count], NULL))
			ft_exit("Mutex inizialization failed");
		count++;
	}
}

/*Creo un thread per ogni filosofo 
-pthread_create(): usata per creare nuovi threads
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
void *(*start_routine)(void *), void *arg);
-pthread_join(): aspettare che un thread specifico finisca la sua
esecuzione prima di permettere al thread principale di continuare
int pthread_join(pthread_t thread, void **retval);
void **retval: puntatore a un puntatore in cui viene conservato
l'exit status del thread una volta finita l'esecuzione.
Questo exit status e' il valore ritornato dal pthread_create()
Se viene passato come NULL significa che non ci serve l'exit status*/
int	ft_init_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_create(&data->check, NULL, (void *)ft_check_mutex, data))
		ft_exit("'check' creation failed");
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philos[i], NULL,
				(void *)ft_philo_handler, &philo[i]))
			ft_exit("'philos' creation failed");
		i++;
	}
	if (pthread_join(data->check, NULL))
		ft_exit("'check' join failed");
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(data->philos[i], NULL))
			ft_exit("'philos' join failed");
		i++;
	}
	return (0);
}

void	ft_one_philo(t_philo *philo)
{
	printf("0 | Philosopher 1 has taken a fork\n");
	usleep(philo->data->time_to_die * 1000);
	printf("%u | Philosopher 1 died\n", philo->data->time_to_die);
}
