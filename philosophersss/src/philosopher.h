/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:42:18 by btani             #+#    #+#             */
/*   Updated: 2023/09/12 18:42:20 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include "../Libft/libft.h"

/* colors */
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define WHITE "\033[0m"
# define BOLD "\033[1m"

/* structures */
typedef struct s_philo
{
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				left_fork;
	int				right_fork;
	struct s_data	*data;
}			t_philo;

typedef struct s_data
{
	int				nbr_philo;
	int				*nbr_meal;
	int				death;
	unsigned int	time_to_die;
	pthread_t		check;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	time_t			start;
	time_t			current;
	time_t			*last_ate;
	struct timeval	tv;
}			t_data;

/* ALLOC_INIT.C */
void	ft_allocation(char **av, t_data *data);
void	ft_initialize(int ac, char **av, t_data *data);
void	ft_init_philos(char **av, t_data *data, t_philo *philo);
void	ft_init_mutex(t_data *data, t_philo *philo);
int		ft_init_threads(t_data *data, t_philo *philo);
void	ft_one_philo(t_philo *philo);

/* MUTEX_CHECK */
void	ft_check_meal(t_data *data, int *n_death);
void	ft_check_death(t_data *data, int *n_ate);
void	ft_check_mutex(t_data *data);
void	ft_get_time(t_data *data);

/* ROUTINE.C */
void	ft_take_fork(t_data *data, t_philo *philo);
void	ft_eat(t_data *data, t_philo *philo);
void	ft_sleep(t_data *data, t_philo *philo);
void	ft_think(t_data *data, t_philo *philo);

/* UTILS.C */
int		ft_exit(char *str);
void	ft_philo_handler(t_philo *philo);
void	ft_close_data(t_data *data, t_philo *philo);
void	ft_reset_philo(t_philo *philo);
#endif