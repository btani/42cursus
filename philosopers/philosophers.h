/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:40:16 by btani             #+#    #+#             */
/*   Updated: 2023/06/04 16:42:25 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

//# define TIMES_TO_COUNT 21000

# define GREEN = \033[0;32m
# define RED = \033[0;
# define YELLOW = \033[0;33m
# define CIANO = \033[0;36]
# define PURPLE = \033[0;35m
# define NO_COLOR = \033[0m

/* STRUCTS*/
typedef struct s_general
{
	int				nbr_philo; //da usare per il monitoring
	int				death; //per il montiring: controlla se un philo muore
	int				*nbr_eat; //quante vlte ogni philo deve mangiare
	unsigned int	time_die; //reset ogni volta che il il philo mangia 
	time_t			now;
	time_t			*last_eat; //ultima volta che il philo ha mangiato: se now - last_eat[i] > time_die, il philo muore 
	pthread_t		*philo;
	pthread_mutex_t	general_start; //mutex generale
	pthread_mutex_t	*forks;

}	t_general;

typedef struct s_philo
{
	struct s_general	*general;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				fork_l;
	int				fork_r; //uguale al numero del philos
	
}	t_philo;

#endif
