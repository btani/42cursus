/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:53:30 by btani             #+#    #+#             */
/*   Updated: 2023/03/06 21:59:40 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find(char **temp, t_map size, t_position pos)
{
	if (pos.x < 0 || pos.x > size.columns || pos.y < 0 || pos.y >= size.lines
		|| temp[pos.y][pos.x] == '1')
		return ;
	if (temp[pos.y][pos.x] == 'E')
	{
		temp[pos.y][pos.x] = '1';
		return ;
	}
	temp[pos.y][pos.x] = '1';
	ft_find(temp, size, (t_position){pos.x + 1, pos.y});
	ft_find(temp, size, (t_position){pos.x - 1, pos.y});
	ft_find(temp, size, (t_position){pos.x, pos.y + 1});
	ft_find(temp, size, (t_position){pos.x, pos.y - 1});
}

int	ft_flood_fill(char **tab, t_map size, t_position begin)
{
	int	y;
	int	x;

	y = 0;
	ft_find(tab, size, begin);
	while (tab[y] != 0)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] != '0' && tab[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
