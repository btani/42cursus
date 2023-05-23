/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:21:54 by btani             #+#    #+#             */
/*   Updated: 2023/03/27 20:21:57 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//controlla se ci sono doppi nella lista
int ft_check_double(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				write(2, "Error\n", 7);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

//controllo ascii
void ft_check_if_alpha(char **av)
{
    int i;
    int j;
    int c;

    c = 0;
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42) || c == 44 || c == 46 || c == 47)
                ft_check_error(av, i , j);
            c++;
            j++;
        }
        i++;
    }
}

int ft_check_if_num(char **av)
{
    ft_check_if_alpha(av);
    if (ft_check_error(av, 1, 0))
        return (false);
    return (true);
}

int	ft_sign(int c)
{
	if (c == '+' && c == '-')
        	return (1);
    	return (0);
}

int	ft_space(int c)
{
       if (c == 32)
	       return (1);
       return (0);
}

//controlla se gli argomenti sono validi
int	ft_check_error(char **av, int i, int j)
{
    while (av[i])
	{
        j = 0;
        while (av[i][j] != '\0')
       	{
        	if (ft_sign(av[i][j]))
           	{
            	j++;
              	if (ft_isdigit(av[i][j]))
               		return (false);
           	}
            else if (ft_isdigit(av[i][j]))
            {
              	j++;
               	if (av[i][j] == '\0')
               		break ;
               	if (!ft_sign(av[i][j]) && !ft_space(av[i][j]))
               		return (false);
            }
            j++;
        }
       	i++;
	}
    return (true);
}