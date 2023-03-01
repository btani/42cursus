/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:57:08 by btani             #+#    #+#             */
/*   Updated: 2023/02/28 17:57:12 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	x_last;
	int	y_last;

	game->player_sprite = player_sprite;
	x_last = game->map.player.x;
	y_last = game->map.player.y;
	if (game->map.full[new_y][new_x] == EXIT && game->map.collects == 0)
		ft_victory(game);
	else if ((game->map.full[new_y][new_x] == FLOOR)
		|| (game->map.full[new_y][new_x] == COLLECTIBLE))
	{
		game->map.full[x_last][y_last] = FLOOR;
		if (game->map.full[new_y][new_x] == COLLECTIBLE)
			game->map.collects--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->movs++;
		ft_render_map(game);
	}
}

int	ft_input(int key, t_game *game)
{
	if (key == 119 || key == 65362)
		ft_move_player(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (key == 97 || key == 65361)
		ft_move_player(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (key == 115 || key == 65363)
		ft_move_player(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (key == 100 || key == 65364)
		ft_move_player(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (key == 113 || key == 65307)
		ft_close_game(game);
	return (0);
}
