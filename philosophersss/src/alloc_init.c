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

/* allocazione degli elementi */
void	ft_allocation(char **av, t_data *data)
{
	data->nbr_philo = ft_atoi(av[1]);
	if (data->nbr_philo < 1)
		ft_exit("too few philosophers");
	data->philos = (pthread_t *)ft_calloc(data->nbr_philo, sizeof(pthread_t));
	if (!data->philos)
		ft_exit("'data->philos'->allocation failed");
	data->forks = (pthread_mutex_t *)ft_calloc(data->nbr_philo,
			sizeof(pthread_mutex_t));
	if (!data->forks)
		ft_exit("'data->forks'->allocation failed");
	data->last_ate = (time_t *)ft_calloc(data->nbr_philo, sizeof(time_t));
	if (!data->last_ate)
		ft_exit("'data->last_ate'->allocation failed");
	data->nbr_meal = (int *)ft_calloc(data->nbr_philo, sizeof(int));
	if (!data->nbr_meal)
		ft_exit("'data->nbr_meal'->allocation failed");
}

/*getttimeofday(): usata per rilevare il current time con precisioni in microsecondi
struct timeval *tv: puntatore a una struttura che conserva il current time*/
void	ft_initialize(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	data->time_to_die = ft_atoi(av[2]);
	gettimeofday(&data->tv, NULL);
	data->start = ((time_t)(data->tv.tv_sec) * 1000)
		+ ((time_t)(data->tv.tv_usec) / 1000);
	while (i++ < data->nbr_philo)
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

/* inizializzazione dati filosofi */
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

/*inizializzazione mutex del lock e delle forks
pthread_mutex_init(): usata per inizializzare un mutex
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);*/
void	ft_init_mutex(t_data *data, t_philo *philo)
{
	(void) philo;
	int	count;
	count = 0;
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		ft_exit("Mutex inizialization failed");
	while (count++ < data->nbr_philo)
	{
		if (pthread_mutex_init(&data->forks[count], NULL))
			ft_exit("Mutex inizialization failed");
	}
}

/*Creo un thread per ogni filosofo 
-pthread_create(): usata per creare nuovi threads
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
void *(*start_routine)(void *), void *arg);
-pthread_join(): usata per aspettare che un thread specifico finisca
la sua esecuzione prima di permettere al thread principale di continuare
int pthread_join(pthread_t thread, void **retval);
void **retval: puntatore a un puntatore dove l'exit status  del thread
viene conservato una volta che ha finito l'esecuzione.
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
