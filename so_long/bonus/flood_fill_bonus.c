/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:53:30 by btani             #+#    #+#             */
/*   Updated: 2023/03/06 21:59:40 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

char	**ft_copy_map(t_game *game)
{
	char	**dup;
	int		y;

	y = 0;
	dup = ft_calloc(game->map.lines + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	while (game->map.full[y] != NULL)
	{
		dup[y] = ft_strdup(game->map.full[y]);
		y++;
	}
	return (dup);
}

void	ft_reset_flood(t_game *game, char **temp_map)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y] != NULL)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (temp_map[y][x] == 'E' || temp_map[y][x] == 'C')
			{
				ft_free_matrix(temp_map);
				ft_error_msg("\033[0;31mError!E-C not reachables!\033[0m", game);
			}
			x++;
		}
		y++;
	}
}

void	ft_flood_fill(char **temp, int x, int y)
{
	if (temp[y][x] == '0' || temp[y][x] == 'E'
		|| temp[y][x] == 'P' || temp[y][x] == 'C')
	{
		if (temp[y][x] == 'E')
		{
			temp[y][x] = '#';
			return ;
		}
		temp[y][x] = '*';
		ft_flood_fill(temp, x, y - 1);
		ft_flood_fill(temp, x + 1, y);
		ft_flood_fill(temp, x, y + 1);
		ft_flood_fill(temp, x - 1, y);
	}
}
