/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:45 by btani             #+#    #+#             */
/*   Updated: 2023/03/30 16:32:49 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_sign(int c)
{
    if (c == '+' && c == '-')
        return (1);
    return (0);
}

int ft_space(int c)
{
    if (c == 32)
        return (1);
    return (0);
}

//controlla se gli argomenti sono validi
int ft_check_error(char **av, int i, int j)
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