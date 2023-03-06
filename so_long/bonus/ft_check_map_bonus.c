/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:14:14 by btani             #+#    #+#             */
/*   Updated: 2023/03/05 17:15:55 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_lines(t_game *game)
{
	int	ln;

	ln = 0;
	while (ln < game->map.lines)
	{
		if ((int) ft_strlen(game->map.full[ln]) != game->map.columns)
			ft_error_msg("Error!The map isn't rectangular", game);
		else if (game->map.full[ln][0] != WALL)
			ft_error_msg("Error!Wall in the first line missing", game);
		else if (game->map.full[ln][game->map.columns - 1] != WALL)
			ft_error_msg("Error!Wall in the last line missing", game);
		ln++;
	}
}

void	ft_check_columns(t_game *game)
{
	int	col;

	col = 0;
	while (col < game->map.columns)
	{
		if (game->map.full[0][col] != WALL)
			ft_error_msg("Error!Wall in the first column missing", game);
		else if (game->map.full[game->map.lines - 1][col] != WALL)
			ft_error_msg("Error!Wall in the last column missing", game);
		col++;
	}
}

void	ft_num_of_components(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.lines)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("01CEPN", game->map.full[y][x]))
				ft_error_msg("Error in the components. Invalid map!", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COLLECTIBLE)
				game->map.collects++;
			else if (game->map.full[y][x] == EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_check_components(t_game *game)
{
	if (game->map.collects == 0)
		ft_error_msg("Error!No collectibles here!", game);
	else if (game->map.exit == 0)
		ft_error_msg("Error!No exit here, how can you escape?!", game);
	else if (game->map.players != 1)
		ft_error_msg("Error!The player must be only one", game);
}

void	ft_check_map(t_game *game)
{
	ft_check_lines(game);
	ft_check_columns(game);
	ft_num_of_components(game);
	ft_check_components(game);
}
