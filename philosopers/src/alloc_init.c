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

void	ft_alloc_all(t_data *data)
{
	data->philos = ft_calloc(data->nbr_philo, sizeof(pthread_t));
	if (!data->philos)
		ft_exit("allocation philos failed");
	data->forks = ft_calloc(data->nbr_philo, sizeof(pthread_mutex_t));
	if (!data->forks)
		ft_exit("allocation forks failed");
	data->last_ate = ft_calloc(data->nbr_philo, sizeof(time_t));
	if (!data->last_ate)
		ft_exit("allocation last_ate failed");
	data->nbr_meal = ft_calloc(data->nbr_philo, sizeof(int));
	if (!data->nbr_meal)
		ft_exit("allocation nbr_meal failed");
}

/*getttimeofday(): used to retrieve the current time with microsecond precision
gettimeofday(struct timeval *tv, struct timezone *tz);
struct timeval *tv: pointer to a structure that will hold the current time*/
void	ft_init(t_data *data, t_philo *philo)
{
	int	n;

	n = 0;
	gettimeofday(&data->tv, NULL);
	data->start = ((time_t)(data->tv.tv_sec) * 1000) + ((time_t)
			(data->tv.tv_usec) / 1000);
	while (n++ < data->nbr_philo)
		data->last_ate[n] = data->start;
	data->death = 0;
	n = 0;
	while (n++ < data->nbr_philo)
	{
		philo[n].right_fork = (n + 1) % data->nbr_philo; // forse -?
		philo[n].left_fork = n;
		philo[n].data = data;
	}
}

/*inizializzazione dei mutex del lock e del fork
pthread_mutex_init(): unction used for initializing 
a mutex in a multi-threaded program
int pthread_mutex_init(pthread_mutex_t *mutex,
 const pthread_mutexattr_t *attr);*/
void	ft_init_mutex(t_data *data, t_philo *philo)
{
	int	count;

	count = 0;
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		ft_exit("Mutex inizialization failed");
	while (count++ < data->nbr_philo)
	{
		if (pthread_mutex_init(&philo->data->forks[count], NULL))
			ft_exit("Mutex inizialization failed");
	}
}

/*Creating a thread for each philosopher
-pthread_create(): function used for creating new threads
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
void *(*start_routine)(void *), void *arg);
-pthread_join(): function used to wait for a specific thread
to finish its execution before allowing the calling thread to continue
int pthread_join(pthread_t thread, void **retval);
void **retval: pointer to a pointer where the exit status of
the thread will be stored once it has finished executing.
This exit status is the value returned by the pthread_create() function.
if pass NULL it means don't need the exit status*/
int	ft_init_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (data->nbr_philo == 0)
	{
		if (pthread_create(&data->philos[0], NULL, (void *)ft_one_philo, &philo[0]))
			ft_exit("thread creation failed");
		if (pthread_join(data->philos[0], NULL))
			ft_exit("thread join failed");
	}
	if (pthread_create(&data->check, NULL, (void *)ft_check_mutex, data))
		ft_exit("thread creation failed");
	if (pthread_join(data->check, NULL) != 0)
		ft_exit("thread join failed");
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philos[i], NULL,
				(void *)ft_philo_handler, &philo[i]))
			ft_exit("thread creation failed");
		if (pthread_join(data->philos[i], NULL))
			ft_exit("thread join failed");
		i++;
	}
	return (0);
}

void	ft_one_philo(t_philo *philo)
{
	printf("0 | Philosopher 1 has taken a fork\n");
	usleep(philo->data->time_to_die * 1000);
	printf("%u | Philosopher 1 has died\n", philo->data->time_to_die);
}
