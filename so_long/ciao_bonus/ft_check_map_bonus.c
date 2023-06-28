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
		if ((int) ft_strlen(game->map.full[ln]) != game->map.columns + 1)
			ft_error_msg("\033[0;31mError!The map isn't complete!\033[0m", game);
		//else if (game->map.lines == game->map.columns)
			//ft_error_msg("\033[0;31mError!The map is squared!\033[0m", game);
		else if (game->map.full[ln][0] != WALL)
			ft_error_msg("\033[0;31mError!Wall missing-first line!\033[0m", game);
		else if (game->map.full[ln][game->map.columns] != WALL)
			ft_error_msg("\033[0;31mError!Wall missing-last line!\033[0m", game);
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
			ft_error_msg("\033[0;31mError!Wall missing-first col!\033[0m", game);
		else if (game->map.full[game->map.lines - 1][col] != WALL)
			ft_error_msg("\033[0;31mError!Wall missing-last col!\033[0m", game);
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
				ft_error_msg("\033[0;31mError!Found unknown char!\033[0m", game);
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
		ft_error_msg("\033[0;31mError!No collectibles here!\033[0m", game);
	else if (game->map.exit == 0 || game->map.exit > 1)
		ft_error_msg("\033[0;31mError!The exit must be one!\033[0m", game);
	else if (game->map.players != 1)
		ft_error_msg("\033[0;31mError!The player must be only one!\033[0m", game);
}

void	ft_check_map(t_game *game)
{
	char	**temp_map;

	ft_check_lines(game);
	ft_check_columns(game);
	ft_num_of_components(game);
	ft_check_components(game);
	temp_map = ft_copy_map(game);
	ft_flood_fill(temp_map, game->map.player.x, game->map.player.y);
	ft_reset_flood(game, temp_map);
}