/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:33:03 by btani             #+#    #+#             */
/*   Updated: 2023/02/23 18:33:04 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_check_lines(t_game *game)
{
	int	ln;
	int	len:
	
	ln = 0;
	len = ft_strlen(game->map.full[ln]);
	while (ln < game->map.lines)
	{
		if (len != game->map.columns)
			ft_error_msg("Error!The map isn't rectangular", game);
		else if (game->map.full[ln][0] != WALL || game->map.full[ln][game->map.colums] != WALL)
			ft_error_msg("Error!Wall missing", game);
		ln++;
	}
}

void	ft_check_columns(t_game *game)
{
	int	col;
	
	col = 0;
	while (col < game->map.columns)
	{
		if (game->map.columns[col][0] != WALL || game->map.columns[col][game->map.lines] != WALL)
			ft_error_msg("Error!Wall missing", game);
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
			if (!ft_strchr("01CEP", game->map.full[y][x]))
				ft_error_msg("Error in the parameters. Invalid map!", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COLLECTIBLE)
				game->map.collect++;
			else if (game->map.full[y][x] == EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_check_components(t_game *game)
{
	if (game->map.collect == 0)
		ft_error_msg("Error!No collectibles here!", game);
	else if (game->map.exit == 0)
		ft_error_msg("Error!No exit here, how can you escape?!", game);
	else if (game->map.players != 1)
		ft_error_msg("Error!THe player must be only one", game);
}

void	ft_check_map(t_game *game)
{
	ft_check_lines(game);
	ft_check_columns(game);
	ft_num_of_components(game);
	ft_check_components(game);
}
