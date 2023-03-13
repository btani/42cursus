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

	ln = 0;
	while (ln < game->map.lines)
	{
		if ((int) ft_strlen(game->map.full[ln]) != game->map.columns + 1)
			ft_error_msg("\033[0;31mError!The map isn't rectangular\033[0m", game);
		else if (game->map.full[ln][0] != WALL)
			ft_error_msg("\033[0;31mError! Wall missing in the first line\033[0m", game);
		else if (game->map.full[ln][game->map.columns - 1] != WALL)
			ft_error_msg("\033[0;31mError! Wall missing in the last line\033[0m", game);
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
			ft_error_msg("\033[0;31mError!Wall missing in the first column\033[0m", game);
		else if (game->map.full[game->map.lines - 1][col] != WALL)
			ft_error_msg("\033[0;31mError!Wall missing in the last column\033[0m", game);
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
				ft_error_msg("\033[0;31mError in the components. Invalid map!\033[0m", game);
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
	else if (game->map.exit == 0)
		ft_error_msg("\033[0;31mError!No exit here, how can you escape?!\033[0m", game);
	else if (game->map.players != 1)
		ft_error_msg("\033[0;31mError!The player must be only one\033[0m", game);
}

void	ft_check_map(t_game *game)
{
	
	ft_check_lines(game);
	ft_check_columns(game);
	ft_num_of_components(game);
	ft_check_components(game);
	
}
