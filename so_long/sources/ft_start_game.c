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
	game->player_sprite = RIGHT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_msg("Error, no mlx ptr!", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 32 * (game->map.columns),
			32 * game->map.lines, "SO_LONG");
	if (game->win_ptr == NULL)
		ft_error_msg("Error!Ops, couldn't open the window", game);
}

t_image	ft_put_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = NULL;
	if (open(path, O_RDONLY))
		sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Error!There isn't any image", game);
	return (sprite);
}

void	ft_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->floor = ft_put_sprite(mlx, "textures/sprites/floor.xpm", game);
	game->wall = ft_put_sprite(mlx, "textures/sprites/wall.xpm", game);
	game->close_ex = ft_put_sprite(mlx, "textures/sprites/close_ex.xpm", game);
	game->open_ex = ft_put_sprite(mlx, "textures/sprites/open_ex.xpm", game);
	game->collectible = ft_put_sprite(mlx, "textures/sprites/coll.xpm", game);
	game->player_f = ft_put_sprite(mlx, "textures/sprites/player_f.xpm", game);
	game->player_b = ft_put_sprite(mlx, "textures/sprites/player_b.xpm", game);
	game->player_l = ft_put_sprite(mlx, "textures/sprites/player_l.xpm", game);
	game->player_r = ft_put_sprite(mlx, "textures/sprites/player_r.xpm", game);
}
