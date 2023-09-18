/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:41:31 by btani             #+#    #+#             */
/*   Updated: 2023/09/12 18:41:34 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* Check if the string is a number and if it is not bigger than 10 digits */
int	ft_check_if_nbr(char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

/* Assign and check if the arguments are valid. */
int	ft_check_av(t_data *data, t_philo *philo, int argc, char **av)
{
	int	i;

	i = 0;
	data->nbr_philo = ft_atoi(av[1]);
	if (data->nbr_philo < 1)
		ft_exit("Invalid n° philosophers");
	data->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (argc == 6)
	{
		while (i < data->nbr_philo)
			data->nbr_meal[i++] = -1;
	}
	else
	{
		while (i < data->nbr_philo)
			data->nbr_meal[i++] = ft_atoi(av[5]);
	}
	if (data->nbr_philo <= 0 || data->time_to_die <= 0
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0
		|| (argc == 6 && data->nbr_meal <= 0))
		return(1);
	return(0);
}