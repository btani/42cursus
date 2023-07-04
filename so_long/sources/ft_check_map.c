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
	int	x;

	x = 0;
	while (x < game->map.columns)
	{
		if (game->map.full[0][x] != WALL)
			ft_error_msg("\033[0;31mError! Wall missing in lines!\033[0m", game);
		else if (game->map.full[game->map.lines - 1][x] != WALL)
			ft_error_msg("\033[0;31mError! Wall missing in lines!\033[0m", game);
		x++;
	}
}

void	ft_check_columns(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.lines)
	{
		if ((int) ft_strlen(game->map.full[y]) != game->map.columns)
			ft_error_msg("\033[0;31mError! The map isn't complete!\033[0m", game);
		if (game->map.full[y][0] != WALL)
			ft_error_msg("\033[0;31mError! Wall missingin col!\033[0m", game);
		else if (game->map.full[y][game->map.columns - 1] != WALL)
			ft_error_msg("\033[0;31mError! Wall missing in col!\033[0m", game);
		y++;
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

	if (game->map.lines == game->map.columns)
		ft_error_msg("\033[0;31mError! The map is squared!\033[0m", game);
	ft_check_lines(game);
	ft_check_columns(game);
	ft_num_of_components(game);
	ft_check_components(game);
	temp_map = ft_copy_map(game);
	ft_flood_fill(temp_map, game->map.player.x, game->map.player.y);
	ft_reset_flood(game, temp_map);
	ft_free_matrix(temp_map);
}
