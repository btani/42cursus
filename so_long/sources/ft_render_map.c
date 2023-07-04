/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:31:09 by btani             #+#    #+#             */
/*   Updated: 2023/02/28 14:31:21 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_which_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		ft_put_image_to_wind(game, game->player_f, y, x);
	if (game->player_sprite == BACK)
		ft_put_image_to_wind(game, game->player_b, y, x);
	if (game->player_sprite == LEFT)
		ft_put_image_to_wind(game, game->player_l, y, x);
	if (game->player_sprite == RIGHT)
		ft_put_image_to_wind(game, game->player_r, y, x);
}

void	ft_which_sprite(t_game *game, int y, int x)
{
	char	component;

	component = game->map.full[y][x];
	if (component == WALL)
		ft_put_image_to_wind(game, game->wall, y, x);
	else if (component == FLOOR)
		ft_put_image_to_wind(game, game->floor, y, x);
	else if (component == COLLECTIBLE)
		ft_put_image_to_wind(game, game->collectible, y, x);
	else if (component == EXIT)
		ft_put_image_to_wind(game, game->close_ex, y, x);
	else if (component == PLAYER)
		ft_which_player(game, y, x);
}

void	ft_put_image_to_wind(t_game *game, t_image sprite, int row, int col)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		sprite.xpm_ptr, col * sprite.x, row * sprite.y);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.lines)
	{
		x = 0;
		while (x < game->map.columns + 1)
		{
			ft_which_sprite(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
