/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:16:39 by btani             #+#    #+#             */
/*   Updated: 2023/02/23 18:16:41 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_init_variab(t_game *game)
{
	game->map.collects = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movs = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->sprite_player = RIGHT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_msg("Error, no mlx ptr!", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 32 * game->map.columns, 32 * game->map.lines, "SO_LONG"); //32 grandezza immagine
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Error!Ops, couldn't open the window", game);
	}
}

t_image ft_put_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Error!There isn't any image", game);
	return (sprite);
}

void	ft_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->floor = ft_put_sprite(mlx, "/assets/sptrites/floor.xpm", game);
	game->wall = ft_put_sprite(mlx, "/assets/sptrites/wall.xpm", game);
	game->close_exit = ft_put_sprite(mlx, "/assets/sptrites/close.xpm", game);
	game->open_exit = ft_put_sprite(mlx, "/assets/sptrites/open.xpm", game);
	game->collectible = ft_put_sprite(mlx, "/assets/sptrites/collect.xpm", game);
	game->player_f = ft_put_sprite(mlx, "/assets/sptrites/p_front.xpm", game);
	game->player_b = ft_put_sprite(mlx, "/assets/sptrites/p_back.xpm", game);
	game->player_l = ft_put_sprite(mlx, "/assets/sptrites/p_left.xpm", game);
	game->player_r = ft_put_sprite(mlx, "/assets/sptrites/p_right.xpm", game);
}
